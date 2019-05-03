//=============================================================================
// Module name  : CoreDocumentsInterface.cpp
//=============================================================================

#include "stdafx.h" 

#include "DCategories.h"
#include "UICategories.hjson"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define _AddOn_Interface_Of coredocuments

/////////////////////////////////////////////////////////////////////////////
//					Add-On Interface Definition
/////////////////////////////////////////////////////////////////////////////
//

//-----------------------------------------------------------------------------
BEGIN_ADDON_INTERFACE()
	DATABASE_RELEASE(1)

	//-----------------------------------------------------------------------------
	BEGIN_TABLES()
		BEGIN_REGISTER_TABLES	()
		END_REGISTER_TABLES		()
	END_TABLES()

	//-----------------------------------------------------------------------------
	BEGIN_FUNCTIONS()
	END_FUNCTIONS()

	//-----------------------------------------------------------------------------
	BEGIN_HOTLINK()
	END_HOTLINK ()

	//-----------------------------------------------------------------------------
	BEGIN_TEMPLATE()
		//BEGIN_DOCUMENT (_NS_DOC("Categories"), TPL_NO_PROTECTION)
		//	REGISTER_MASTER_JSON_TEMPLATE(szDefaultViewMode,	DCategories,	IDD_CATEGORIES)
		//	REGISTER_BKGROUND_TEMPLATE	(szBackgroundViewMode,	DCategories)
		//END_DOCUMENT ()
	END_TEMPLATE()

	//-----------------------------------------------------------------------------
	BEGIN_CLIENT_DOC()
	END_CLIENT_DOC()

END_ADDON_INTERFACE()

#undef _AddOn_Interface_Of