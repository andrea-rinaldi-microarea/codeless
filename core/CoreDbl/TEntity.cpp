#include "stdafx.h"

#include "TEntity.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(TEntity, SqlRecord)

//-----------------------------------------------------------------------------
TEntity::TEntity(BOOL bCallInit)
	:
	SqlRecord	(GetStaticName())
{
	f_DocNo.SetUpperCase();

	BindRecord();

	if (bCallInit) Init();
}

//-----------------------------------------------------------------------------
void TEntity::BindRecord()
{
	BEGIN_BIND_DATA();
		BIND_DATA	(_NS_FLD("DocID"),			f_DocID);
		BIND_DATA	(_NS_FLD("DocNo"),			f_DocNo);
		BIND_DATA	(_NS_FLD("DocDate"),		f_DocDate);
		BIND_DATA	(_NS_FLD("LastSubId"),		f_LastSubId);
	END_BIND_DATA();
}

//-----------------------------------------------------------------------------
LPCTSTR TEntity::GetStaticName() {return _NS_TBL("Entity"); }

/////////////////////////////////////////////////////////////////////////////
//						class TEntityDetails implementation
/////////////////////////////////////////////////////////////////////////////
//
//=============================================================================
IMPLEMENT_DYNCREATE(TEntityDetails, SqlRecord)

//-----------------------------------------------------------------------------
TEntityDetails::TEntityDetails(BOOL bCallInit)
	:
	SqlRecord			(GetStaticName())
{
	f_Code.SetUpperCase();

	BindRecord();

	if (bCallInit) Init();
}

//-----------------------------------------------------------------------------
void TEntityDetails::BindRecord()
 {
 	BEGIN_BIND_DATA();
 		BIND_DATA	(_NS_FLD("DocID"),			f_DocID);
 		BIND_DATA	(_NS_FLD("DocSubID"),		f_DocSubID);
 		BIND_DATA	(_NS_FLD("Code"),			f_Code);
 		BIND_DATA	(_NS_FLD("Description"),	f_Description);
	END_BIND_DATA();
}

//-----------------------------------------------------------------------------
LPCTSTR TEntityDetails::GetStaticName() {return _NS_TBL("EntityDetails"); }

