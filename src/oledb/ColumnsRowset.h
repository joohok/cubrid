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
  
#pragma once
  
#include "type.h"
#include "Error.h"
  
#define CUBRID_COLENTRY_EX(name, ordinal, flags, colSize, dbtype, precision, scale, dbid, member) \
{
  \
    \
  {
    \
									 * little-endian�̸�
									 * ������ ���� ������ �ʹ�. */  \ 
  }
, \

, 
#define CUBRID_COLENTRY(name, ordinal, maybenull, precision, dbid, member) \
  CUBRID_COLENTRY_EX (name, ordinal, DBCOLUMNFLAGS_ISFIXEDLENGTH | (maybenull ? DBCOLUMNFLAGS_MAYBENULL : 0),
		    \
		    255, dbid, member) 
// atldb.h���� colSize==255�ε�, LTM���� �����ؼ� 127�� �����ߴ�.
#define CUBRID_COLENTRY_WSTR(name, ordinal, dbid, member) \
  CUBRID_COLENTRY_EX (name, ordinal, DBCOLUMNFLAGS_MAYBENULL, 127, DBTYPE_WSTR, 255, 255, dbid, member) 
#define CUBRID_COLENTRY_BOOL(name, ordinal, dbid, member) \
     CUBRID_COLENTRY_EX (name, ordinal, DBCOLUMNFLAGS_ISFIXEDLENGTH | DBCOLUMNFLAGS_MAYBENULL, \
		    DBTYPE_BOOL, 255, 255, dbid, member) 
       g_cRequiredMetadataColumns = 11;
     

{

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

    
    
    
  {
    
    
    
    
    
  
    // Required Metadata Columns
    CUBRID_COLENTRY_WSTR ("DBCOLUMN_IDNAME", 1, DBCOLUMN_IDNAME, m_szIDName) 
												true, 255,
												DBCOLUMN_GUID,
												m_guid) 
    CUBRID_COLENTRY ("DBCOLUMN_PROPID", 3, true, 10, DBCOLUMN_PROPID,
		     m_ulPropid) 
							 m_szName) 
										      DBCOLUMN_NUMBER,
										      m_ulNumber) 
    CUBRID_COLENTRY ("DBCOLUMN_TYPE", 6, false, 5, DBCOLUMN_TYPE, m_nType) 
											      true, 255,
											      DBCOLUMN_TYPEINFO,
											      m_pTypeInfo) 
    CUBRID_COLENTRY ("DBCOLUMN_COLUMNSIZE", 8, false, 10, DBCOLUMN_COLUMNSIZE,
		     m_ulColumnSize) 
							m_nPrecision) 
											 DBCOLUMN_SCALE,
											 m_nScale) 
    CUBRID_COLENTRY ("DBCOLUMN_FLAGS", 11, false, 10, DBCOLUMN_FLAGS, m_ulFlags) 
    // Optional Metadata Columns
CUBRID_COLENTRY ("DBCOLUMN_ISSEARCHABLE", 0, true, 10, DBCOLUMN_ISSEARCHABLE,
		     m_ulSearchable) 
								 DBCOLUMN_ISCASESENSITIVE,
								 m_bCaseSensitive) 
    CUBRID_COLENTRY_WSTR ("DBCOLUMN_BASECOLUMNNAME", 0, DBCOLUMN_BASECOLUMNNAME,
			      m_szBaseColumnName) 
									      DBCOLUMN_BASETABLENAME,
									      m_szBaseTableName) 
    CUBRID_COLENTRY ("DBCOLUMN_DEFAULTVALUE", 0, true, 255, DBCOLUMN_DEFAULTVALUE,
			 m_varDefault) 
								   m_bHasDefault) 
    CUBRID_COLENTRY_BOOL ("DBCOLUMN_ISUNIQUE", 0, DBCOLUMN_ISUNIQUE,
			      m_bIsUnique) 
								  DBCOLUMN_DATETIMEPRECISION,
								  m_ulDateTimePrecision) 
    CUBRID_COLENTRY ("DBCOLUMN_OCTETLENGTH", 0, true, 10, DBCOLUMN_OCTETLENGTH,
			 m_ulCharOctetLength) 


// CreatorClass = CCUBRIDCommand �ε� ������Ű�� �Ͱ� ����ó��
// templateȭ �ϴ� ���� ��� ���� ������ �𸣰���
// ������Ű�� ������ *.cpp�� �и��� �� �־� �������� �ٱ� ��
template < class CreatorClass > 
  CreatorClass > 
{

  
  


    m_rgColumns (0)
    
  {
  
  {
    
  
			bool bHasBookmark) 
  {
    
    
      
      {
	
	
      
    
    
      
    
    
    
    
    
    
      return RaiseError (E_FAIL, 1, __uuidof (IColumnsRowset), "cci_get_result_info failed");
    
      // ATLASSERT(cmd_type==CUBRID_STMT_SELECT || cmd_type==CUBRID_STMT_INSERT);
      
    
      return RaiseError (E_FAIL, 1, __uuidof (IColumnsRowset), error.err_msg);
    
    
      
      {
	
	
      
    
      
      {
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	{
	  
	
	
	{
	  
	  
	
      
    
      
      {
	
	
	
	  
	
	  
	    -1 ? Type::GetDynamicTypeInfo (CCI_U_TYPE_STRING, 0, 0, true) : 
	
	
	
	
	
	
	
	
	
	
	
	  
	
	else
	  
	
	  
	
	else
	  
	
	  // TODO: Columns Schema Rowset������ NULL �ε�,
	  // ���⼭�� 15�� �ؾ� LTM�� ����Ѵ�. ������ �� �𸣰ڴ�.
	  // LTM�� Ʋ���� ����.
	  if (crrData.m_nType == DBTYPE_DBDATE || crrData.m_nType == DBTYPE_DBTIME)
	  
	  {
	    
	  
	
	  
	  {
	    
	      // tbl_infos[j].iOrdinal == j+1 �� �� ���� �ѵ� Ȯ������ �ʴ�.
	      for (size_t j = 0; j < tbl_infos.GetCount (); j++)
	      
	      {
		
		  
		  {
		    
		    
		    
		    
		    
		      
		    
		    
		      
		    
		  
	      
	  
	
	{
	  
	
	
	{
	  
	  
	
      
    
      // ��û�Ǵ� optional metadata columns�� �ٸ��Ƿ�
      // CColumnsRowsetRow::GetColumnInfo�� �ٷ� �̿��� �� ����.
      // �׷��� ������ �����ؼ� ���� �����.
      DBORDINAL tmp;
    
    
    
      // Required Column�� ������ ����
      memcpy (m_rgColumns, pInfo, sizeof (ATLCOLUMNINFO) * g_cRequiredMetadataColumns);
    
      // Optional Column�� ������ ����
      for (DBORDINAL i = 0; i < cOptColumns; i++)
      
      {
	
	
	  
	else
	  
	  {			// DBID�� ���� optional column�� ã�´�.
	    while (j < g_cRequiredMetadataColumns + g_cOptionalMetadataColumns)
	      
	      {
		
		  
		
	      
	  
	
	  return RaiseError (DB_E_BADCOLUMNID, 0, __uuidof (IColumnsRowset));
	
	
      
    
  
  
  {
    
    
    
      // if (crrData.m_ulNumber == 0) //Bookmark
      // {
      // switch(pInfo->iOrdinal)
      // {
      // case 2:
      // case 3:
      // case 5:
      // case 6:
      // case 8:
      // case 9:
      // case 11:
      // return DBSTATUS_S_OK;
      // }
      // } else
    {
      
	
	{
	
	case 3:		// DBCOLUMN_PROPID
	case 7:		// DBCOLUMN_TYPEINFO
	  return DBSTATUS_S_ISNULL;
	
	  if (crrData.m_nPrecision == (USHORT) ~ 0)
	    
	  
	  else
	    
	
	  if (crrData.m_nScale == -1)
	    
	  
	  else
	    
	
	case 4:		// DBCOLUMN_NAME
	case 5:		// DBCOLUMN_NUMBER
	case 6:		// DBCOLUMN_TYPE
	case 8:		// DBCOLUMN_COLUMNSIZE
	case 11:		// DBCOLUMN_FLAGS
	  return DBSTATUS_S_OK;
	
    
    
      // optional metadata columns
      if (memcmp (&pInfo->columnid, &DBCOLUMN_ISSEARCHABLE, sizeof (DBID)) == 0)
      
      {
	
      
    
      
      {
	
      
    
      
      {
	
	  
	
	else
	  
      
    
      
      {
	
	  
	
	else
	  
      
    
      // SQL�� ��� ���� �׸��� ���� ������ �ʴ´�.
      if (m_bIsTable)
      
      {
	
	  
	  {
	    
	  
	
	  
	  {
	    
	      
	    
	    else
	      
	  
	
	  
	  {
	    
	  
	
	  
	  {
	    
	  
	
	  
	  {
	    
	  
      
    
  
  
  {
    
    
  



{

  {
    
    
    
    
      
    
      
    
      
    
      
      {
	
	  
	
	  
      
    
    {
      
	
    
    
      
      {
	
	
	
	
	
	  
	
	
	  
      
    
  
  
				  ULONG cPropertySets, 
  {
    
    
    
    
    
      // ���� �˻�
      if (ppColRowset == NULL
	  || (cPropertySets > 0 && rgPropertySets == NULL) 
      
    
    
      
      {
	
	  
	
	  
	  {
	    
	    
	      
	  
      
    
      
      {
	
	  
	
	  
      
    
    {
      
	
    
    
      
    
      // Columns Rowset ��ü ����
      CComPolyObject < CColumnsRowset < CreatorClass > >*pPolyObj;
    
    
      
    
      // ������ COM ��ü�� �����ؼ�, ���н� �ڵ� �����ϵ��� �Ѵ�.
      CComPtr < IUnknown > spAutoReleaseUnk;
    
    
      
      {
	
	return RaiseError (hr, 0, __uuidof (IColumnsRowset));
      
    
      // ��ü�� �ʱ�ȭ �Ѵ�.
      CColumnsRowset < CreatorClass > *pRowsetObj = &(pPolyObj->m_contained);
    
    
      
    
      // set properties
    const GUID *ppGuid[1];
    
    
    
      
    
    
      
    
      // Columns Rowset ��ü�� site�� �����Ѵ�.
      CComPtr < IUnknown > spOuterUnk;
    
    
    
      // Check to make sure we set any 'post' properties based on the riid requested.
      if (FAILED (pRowsetObj->OnInterfaceRequested (riid)))
      
    
    
      // �÷� ��Ÿ ������ �˾Ƴ��� ���켭�� ���̺� �̸��� �ʿ��ϴ�.
      CW2A strTableName = pT->m_strTableName;
    
    
    
#if 0
      if (cci_is_updatable (hReq))
      
      {
	
      
    
#endif /* 
      // Columns Rowset ��ü�� ������ ä���.
    int hConn;
    
    
    
      return RaiseError (hr, 0, __uuidof (IColumnsRowset));
    
    
      pRowsetObj->Execute (hConn, hReq, szTableName, cOptColumns, rgOptColumns, V_BOOL (&var) == ATL_VARIANT_TRUE);
    
      
    
      // Columns Rowset ��ü���� riid�� ��û�� interface�� ���Ѵ�.
      if (InlineIsEqualGUID (riid, IID_NULL))
      
    
    
      
      {
	
	
      
    
  


