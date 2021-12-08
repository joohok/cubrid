/*
 * Copyright (C) 2008 Search Solution Corporation. All rights reserved by Search Solution. 
 *
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met: 
 *
 * - Redistributions of source code must retain the above copyright notice, 
 *   this list of conditions and the following disclaimer. 
 *
 * - Redistributions in binary form must reproduce the above copyright notice, 
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution. 
 *
 * - Neither the name of the <ORGANIZATION> nor the names of its contributors 
 *   may be used to endorse or promote products derived from this software without 
 *   specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE. 
 *
 */  
  
// Session.h : Declaration of the CCUBRIDSession
  
#pragma once
  
#include "resource.h"		// main symbols
#include "Command.h"
#include "util.h"
  

// SR = Schema Rowset
  class CSRTables;











// CCUBRIDSession
[
  
  
  
{

  



  {
    
    
  
  {
    
    
  
  {
    
    
  
  
  
    // ITransactionLocal
private:
  
  
  
  
  

  
  
  
  
				 ULONG * pulTransactionLevel);
  
  
  
  
    // IOpenRowset
    STDMETHOD (OpenRowset) (IUnknown * pUnk, DBID * pTID, DBID * pInID, REFIID riid, 
			    IUnknown ** ppRowset);
  
    // ISessionProperties
    virtual HRESULT IsValidValue (ULONG /* iCurSet */ , DBPROP * pDBProp);
  
  
    // ITableDefinition
    STDMETHOD (CreateTable) (IUnknown * pUnkOuter, 
			     
			     
  
  
  
  
    // IIndexDefinition
    STDMETHOD (CreateIndex) (
			     
			     
  
  
    PROPERTY_INFO_ENTRY_VALUE (SESS_AUTOCOMMITISOLEVELS,
			       DBPROPVAL_TI_READCOMMITTED) 
    
    // IDBSchemaRowset
  void SetRestrictions (ULONG cRestrictions, GUID * rguidSchema, ULONG * rgRestrictions);
  

												  CSRColumns) 
    SCHEMA_ENTRY (DBSCHEMA_PROVIDER_TYPES, CSRProviderTypes) 
									       CSRTablePrivileges) 
    SCHEMA_ENTRY (DBSCHEMA_COLUMN_PRIVILEGES, CSRColumnPrivileges) 
										     CSRTableConstraints) 
    SCHEMA_ENTRY (DBSCHEMA_TABLES_INFO, CSRTablesInfo) 
									 CSRStatistics) 
    SCHEMA_ENTRY (DBSCHEMA_INDEXES, CSRIndexes) 
								  CSRViewColumnUsage) 
													CSRViews) 
    END_SCHEMA_MAP () 


#define SR_PROPSET_MAP(Class)						\
  BEGIN_PROPSET_MAP (Class) \ 
  
  
  
  
									 0) \ 
													  0) \ 
  /* �� �ڴ� LTM�� ���� �Ӽ� */ \
  /* LTM�� CCUBRIDDataSource�� ���� �Ӽ��� ��´� */ \
  /* ���� Schema Rowset�� �ƴ� */ \
  /* CCUBRIDCommand�� ���ǵ� �Ӽ��� ���� �׽�Ʈ�� �����Ѵ� */ \
  PROPERTY_INFO_ENTRY_VALUE (ABORTPRESERVE, ATL_VARIANT_FALSE) \ 
												   DBPROPVAL_AO_RANDOM,
												   DBPROPFLAGS_ROWSET |
												   DBPROPFLAGS_READ)
  
				     DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ)
  
			       ATL_VARIANT_TRUE) \ 
  
				     DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ) \
  
												     ATL_VARIANT_FALSE,
												     DBPROPFLAGS_ROWSET
												     | DBPROPFLAGS_READ)
  
				     DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ) 
PROPERTY_INFO_ENTRY_VALUE_FLAGS (IMMOBILEROWS, ATL_VARIANT_FALSE,
				 DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ) 
PROPERTY_INFO_ENTRY_VALUE_FLAGS (IMultipleResults, ATL_VARIANT_FALSE,
				 DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ) \ 
													    ATL_VARIANT_FALSE,
													    DBPROPFLAGS_ROWSET
													    |
													    DBPROPFLAGS_READ)
\ 
								ATL_VARIANT_FALSE) 
PROPERTY_INFO_ENTRY_VALUE (ISupportErrorInfo, ATL_VARIANT_FALSE) \ 
	   DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ) \ 
										      ATL_VARIANT_FALSE,
										      DBPROPFLAGS_ROWSET |
										      DBPROPFLAGS_READ) \

DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ) 
								     DBPROPFLAGS_ROWSET | DBPROPFLAGS_READ) \

#include "SRTables.h"
#include "SRColumns.h"
#include "SRProviderTypes.h"
#include "SRTablePrivileges.h"
#include "SRColumnPrivileges.h"
#include "SRTableConstraints.h"
#include "SRTablesInfo.h"
#include "SRStatistics.h"
#include "SRIndexes.h"
#include "SRViewColumnUsage.h"
#include "SRViews.h"
#include "SRPrimaryKeys.h"
#include "SRKeyColumnUsage.h"