/*
 *
 * Copyright 2016 CUBRID Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#include "method_runtime_context.hpp"

#include "method_query_cursor.hpp"
#include "query_manager.h"
#include "session.h"
#include "xserver_interface.h"

namespace cubmethod
{
//////////////////////////////////////////////////////////////////////////
// Global interface
//////////////////////////////////////////////////////////////////////////

  runtime_context *get_rctx (cubthread::entry *thread_p)
  {
    method_runtime_context *rctx = nullptr;
    session_get_method_runtime_context (thread_p, rctx);
    return rctx;
  }

//////////////////////////////////////////////////////////////////////////
// Runtime Context
//////////////////////////////////////////////////////////////////////////

  runtime_context::runtime_context ()
    : m_group_stack {}
    , m_returning_cursors {}
    , m_group_map {}
    , m_cursor_map {}
  {
    //
  }

  runtime_context::~runtime_context ()
  {
    destroy_all_cursors ();
    destroy_all_groups ();
  }

  method_invoke_group *
  runtime_context::create_invoke_group (cubthread::entry *thread_p, const method_sig_list &sig_list)
  {
    method_invoke_group *group = new (std::nothrow) cubmethod::method_invoke_group (thread_p, sig_list);
    if (group)
      {
	m_group_map [group->get_id ()] = group;
      }
    return group;
  }

  void
  runtime_context::push_stack (cubthread::entry *thread_p, method_invoke_group *group)
  {
    m_group_stack.push_back (group->get_id ());
  }

  void
  runtime_context::pop_stack (cubthread::entry *thread_p)
  {
    m_group_stack.pop_back ();
  }

  method_invoke_group *
  runtime_context::top_stack ()
  {
    assert (m_group_stack.empty () == false);

    METHOD_GROUP_ID top = m_group_stack.back ();

    const auto &it = m_group_map.find (top);
    if (it == m_group_map.end ())
      {
	// should not happended
	assert (false);
	return nullptr;
      }

    return it->second;
  }

  query_cursor *
  runtime_context::get_cursor (cubthread::entry *thread_p, QUERY_ID query_id)
  {
    if (query_id == NULL_QUERY_ID)
      {
	return nullptr;
      }

    // find in map
    auto search = m_cursor_map.find (query_id);
    if (search != m_cursor_map.end ())
      {
	// found
	return search->second;
      }

    return nullptr;
  }

  query_cursor *
  runtime_context::create_cursor (cubthread::entry *thread_p, QUERY_ID query_id, bool is_oid_included)
  {
    if (query_id == NULL_QUERY_ID || query_id >= SHRT_MAX)
      {
	// something wrong!
	assert (false);
	return nullptr;
      }

    query_cursor *cursor = nullptr;

    // find in map
    auto search = m_cursor_map.find (query_id);
    if (search != m_cursor_map.end ())
      {
	// found
	cursor = search->second;
	assert (cursor != nullptr);

	cursor->change_owner (thread_p);
	return cursor;
      }
    else
      {
	// not found, create a new server-side cursor
	int tran_index = LOG_FIND_THREAD_TRAN_INDEX (thread_p);
	QMGR_QUERY_ENTRY *query_entry_p = qmgr_get_query_entry (thread_p, query_id, tran_index);
	if (query_entry_p != NULL)
	  {
	    // m_list_id is going to be destoryed on server-side, so that qlist_count has to be updated
	    qfile_update_qlist_count (thread_p, query_entry_p->list_id, 1);

	    // store a new cursor in map
	    cursor = new (std::nothrow) query_cursor (thread_p, query_entry_p, is_oid_included);
	    m_cursor_map [query_id] = cursor;

	    assert (cursor != nullptr);
	  }
      }

    return cursor;
  }

  void
  runtime_context::destroy_cursor (cubthread::entry *thread_p, QUERY_ID query_id)
  {
    if (query_id == NULL_QUERY_ID)
      {
	/* do nothing */
	return;
      }

    // find in map
    auto search = m_cursor_map.find (query_id);
    if (search != m_cursor_map.end ())
      {
	query_cursor *cursor = search->second;
	if (cursor)
	  {
	    cursor->close ();
	    xqmgr_end_query (thread_p, query_id);
	    delete cursor;
	  }

	m_cursor_map.erase (search);
      }
  }

  void
  runtime_context::register_returning_cursor (cubthread::entry *thread_p, QUERY_ID query_id)
  {
    if (query_id == NULL_QUERY_ID)
      {
	/* do nothing */
	return;
      }

    m_returning_cursors.insert (query_id);
  }

  void
  runtime_context::deregister_returning_cursor (cubthread::entry *thread_p, QUERY_ID query_id)
  {
    if (query_id == NULL_QUERY_ID)
      {
	/* do nothing */
	return;
      }

    m_returning_cursors.erase (query_id);
  }

  void
  runtime_context::destroy_all_groups ()
  {
    for (auto &it : m_group_map)
      {
	if (it.second)
	  {
	    delete it.second;
	  }
      }
    m_group_map.clear ();
  }

  void
  runtime_context::destroy_all_cursors ()
  {
    for (auto &it : m_cursor_map)
      {
	if (it.second)
	  {
	    delete it.second;
	  }
      }
    m_cursor_map.clear ();
    m_returning_cursors.clear ();
  }
} // cubmethod
