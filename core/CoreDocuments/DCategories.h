
#pragma once

#include <core\coreComponents\ADMCategories.h>

#include "beginh.dex"

class TCategories;

//////////////////////////////////////////////////////////////////////////////
//             class DBTCategories definition
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
class TB_EXPORT DBTCategories : public DBTMaster
{ 
	DECLARE_DYNAMIC (DBTCategories)

public:
	DBTCategories (CRuntimeClass*, CAbstractFormDoc*);

public:
	TCategories* GetCategories () const { return (TCategories*) GetRecord(); }

protected: 
	virtual void	OnEnableControlsForFind		();
	virtual void	OnDisableControlsForEdit	();
	
	virtual	void	OnDefineQuery		();
	virtual	void	OnPrepareQuery		();
	virtual	void	OnPrepareBrowser	(SqlTable* pTable);

	virtual	BOOL	OnCheckPrimaryKey	();
	virtual	void	OnPreparePrimaryKey	() {}
};

//=============================================================================
class TB_EXPORT DCategories : public CAbstractFormDoc, public ADMCategoriesObj
{
	DECLARE_DYNCREATE(DCategories)

public:
	DCategories();
	DBTCategories*		m_pDBTCategories;
	
public:	// function Member
	virtual	TCategories*	GetCategories() const;                        
	// interfaccia ADM
	virtual	ADMObj*		GetADM		()	{ return this; }

protected:
	virtual BOOL	OnAttachData	();
};

#include "endh.dex"
