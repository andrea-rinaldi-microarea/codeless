
#pragma once
#include "beginh.dex"

/////////////////////////////////////////////////////////////////////////////
class TB_EXPORT TCategories : public SqlRecord
{
	DECLARE_DYNCREATE(TCategories) 

public:
	DataStr		f_Code;
	DataStr		f_Description;
	
public:
	TCategories(BOOL bCallInit = TRUE);

public:
    virtual void	BindRecord();
		
public:
	static  LPCTSTR  GetStaticName();
};


#include "endh.dex"