
#include "stdafx.h"

#include "DCategories.h"  
#include <core\coreDbl\TCategories.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
static TCHAR szParamCode[] = _T("paramCode");

//////////////////////////////////////////////////////////////////////////////
//             class DBTCategories implementation
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (DBTCategories, DBTMaster)

//-----------------------------------------------------------------------------	
DBTCategories::DBTCategories
	(
		CRuntimeClass*		pClass, 
		CAbstractFormDoc*	pDocument
	)
	:
	DBTMaster (pClass, pDocument, _NS_DBT("Categories"))
{
}

//-----------------------------------------------------------------------------
void DBTCategories::OnEnableControlsForFind ()
{
	GetCategories ()->f_Code.SetFindable();
	GetCategories ()->f_Description.SetFindable();
}

//-----------------------------------------------------------------------------
void DBTCategories::OnDisableControlsForEdit ()
{
	GetCategories ()->f_Code.SetReadOnly ();
}

//-----------------------------------------------------------------------------	
void DBTCategories::OnPrepareBrowser (SqlTable* pTable)
{
	TCategories* pRec = (TCategories*) pTable->GetRecord();

	pTable->SelectAll();
	pTable->AddSortColumn(pRec->f_Code);
}

//-----------------------------------------------------------------------------
void DBTCategories::OnDefineQuery ()
{
	m_pTable->SelectAll			();
	m_pTable->AddParam			(szParamCode,GetCategories ()->f_Code);
	m_pTable->AddFilterColumn	(GetCategories ()->f_Code);
}

//-----------------------------------------------------------------------------
void DBTCategories::OnPrepareQuery ()
{
	m_pTable->SetParamValue (szParamCode, GetCategories()->f_Code);
}

//-----------------------------------------------------------------------------
BOOL DBTCategories::OnCheckPrimaryKey	()
{
	return
		!GetCategories ()->f_Code.IsEmpty() ||
		!SetError(_TB("The code field is mandatory"));
}

//////////////////////////////////////////////////////////////////////////////
//									DCategories                          //
//////////////////////////////////////////////////////////////////////////////
//
//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(DCategories, CAbstractFormDoc)

//-----------------------------------------------------------------------------
DCategories::DCategories()
	:
	m_pDBTCategories	(NULL)
{
}

//-----------------------------------------------------------------------------
TCategories*	DCategories::GetCategories () const 
{ 
	return (TCategories*) m_pDBTCategories->GetRecord(); 
}

//-----------------------------------------------------------------------------
BOOL DCategories::OnAttachData()
{              
	SetFormTitle (_TB("Categories document"));
	
	m_pDBTCategories = new DBTCategories (RUNTIME_CLASS (TCategories), this);
	
	return Attach (m_pDBTCategories);
}