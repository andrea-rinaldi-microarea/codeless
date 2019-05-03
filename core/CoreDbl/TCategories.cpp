
#include "stdafx.h"             

#include "TCategories.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(TCategories, SqlRecord) 

//-----------------------------------------------------------------------------
TCategories::TCategories(BOOL bCallInit)
	:
	SqlRecord	(GetStaticName())
{
	f_Code.SetUpperCase();

	BindRecord();	
	if (bCallInit) Init();
}

//-----------------------------------------------------------------------------
void TCategories::BindRecord()
{
	BEGIN_BIND_DATA	();
		BIND_DATA	(_NS_FLD("Code"),			f_Code);
		BIND_DATA	(_NS_FLD("Description"),	f_Description);
		BIND_TB_GUID();
	END_BIND_DATA();    
}

//-----------------------------------------------------------------------------
LPCTSTR TCategories::GetStaticName() { return _NS_TBL("SB_Categories"); }