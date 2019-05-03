
#include "stdafx.h"

#include "CMetadataDoc.h"  


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////////
//									CMetadataDoc                          //
//////////////////////////////////////////////////////////////////////////////
//
//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(CMetadataDoc, CAbstractFormDoc)

//-----------------------------------------------------------------------------
CMetadataDoc::CMetadataDoc()
{
}

//-----------------------------------------------------------------------------
BOOL CMetadataDoc::OnAttachData()
{              
	return TRUE;
}