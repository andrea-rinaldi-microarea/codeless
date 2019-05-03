
#pragma once

#include "beginh.dex"


/////////////////////////////////////////////////////////////////////////////
class TB_EXPORT TEntity : public SqlRecord
{
	DECLARE_DYNCREATE(TEntity)

public:
	DataLng		f_DocID;
    DataStr		f_DocNo;
	DataDate	f_DocDate;
	DataLng		f_LastSubId;

public:
	TEntity(BOOL bCallInit = TRUE);

public:
	virtual void	BindRecord();

public:
	static LPCTSTR GetStaticName();
};

/////////////////////////////////////////////////////////////////////////////
class TB_EXPORT TEntityDetails : public SqlRecord
{
	DECLARE_DYNCREATE(TEntityDetails)

public:
	DataLng		f_DocID;
	DataLng		f_DocSubID;
	DataStr		f_Code;
	DataStr		f_Description;

public:
	TEntityDetails(BOOL bCallInit = TRUE);

public:
	virtual void	BindRecord();

public:
	static LPCTSTR GetStaticName();
};
#include "endh.dex"
