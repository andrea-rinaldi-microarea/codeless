
#pragma once

#include "beginh.dex"

class TCategories;

/////////////////////////////////////////////////////////////////////////////
//							ADMCategoriesObj
/////////////////////////////////////////////////////////////////////////////
//
class TB_EXPORT ADMCategoriesObj : public ADMObj
{     
	DECLARE_ADMCLASS(ADMCategoriesObj)
		
public:
	virtual	ADMObj*				GetADM					()					= 0;
	virtual	TCategories*	GetCategories	()			const	= 0;
};

#include "endh.dex"
