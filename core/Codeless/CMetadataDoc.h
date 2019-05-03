
#pragma once

#include "ADMMetadataDoc.h"

#include "beginh.dex"

//=============================================================================
class TB_EXPORT CMetadataDoc : public CAbstractFormDoc, public ADMMetadataDocObj
{
	DECLARE_DYNCREATE(CMetadataDoc)

public:
	CMetadataDoc();
	
public:	
	virtual	ADMObj*		GetADM		()	{ return this; }

protected:
	virtual BOOL	OnAttachData	();
};

#include "endh.dex"
