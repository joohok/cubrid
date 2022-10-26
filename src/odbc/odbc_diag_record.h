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
  
#ifndef	__ODBC_DIAG_HEADER	/* to avoid multiple inclusion */
#define	__ODBC_DIAG_HEADER
  
#include		"cas_cci.h"
  
#define		ODBC_DIAG_INIT			0
#define		ODBC_DIAG_RESET			1
#define		ODBC_DIAG_FREE_MEMBER	2
#define		ODBC_DIAG_FREE_ALL		3
  
#define		ODBC_DIAG_RECORD_INIT			0
#define		ODBC_DIAG_RECORD_RESET			1
#define		ODBC_DIAG_RECORD_FREE_MEMBER	2
#define		ODBC_DIAG_RECORD_FREE_ALL		3
  
/* CUBRID ODBC specific error code */ 
#define ODBC_OK				0
#define	ODBC_ERROR_OFFSET			(-10000)
#define	ODBC_GENERAL_ERROR			(-1 + ODBC_ERROR_OFFSET)
#define	ODBC_WARING					(-2 + ODBC_ERROR_OFFSET)
#define	ODBC_UNKNOWN				(-3 + ODBC_ERROR_OFFSET)
#define ODBC_NULL_VALUE				(-4 + ODBC_ERROR_OFFSET)
#define ODBC_CAS_ERROR				(-6 + ODBC_ERROR_OFFSET)
#define ODBC_NO_MORE_DATA			(-7 + ODBC_ERROR_OFFSET)
#define ODBC_MEMORY_ALLOC_ERROR		(-8 + ODBC_ERROR_OFFSET)
#define	ODBC_NOT_IMPLEMENTED		(-9 + ODBC_ERROR_OFFSET)
#define	ODBC_UNKNOWN_TYPE			(-10 + ODBC_ERROR_OFFSET)
#define	ODBC_INVALID_TYPE_CONVERSION (-11 + ODBC_ERROR_OFFSET)

{
  
   
 

{
  
   
   
   
   
 

{
  
   
   
 







				     
				     

				   
				   



#endif	/* ! __ODBC_DIAG_HEADER */