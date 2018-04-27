/*!  \file kfbxobjectmetadata.h
 */

#ifndef _FBXSDK_OBJECTMETADATA_H_
#define _FBXSDK_OBJECTMETADATA_H_

/**************************************************************************************

 Copyright � 2001 - 2008 Autodesk, Inc. and/or its licensors.
 All Rights Reserved.

 The coded instructions, statements, computer programs, and/or related material 
 (collectively the "Data") in these files contain unpublished information 
 proprietary to Autodesk, Inc. and/or its licensors, which is protected by 
 Canada and United States of America federal copyright law and by international 
 treaties. 
 
 The Data may not be disclosed or distributed to third parties, in whole or in
 part, without the prior written consent of Autodesk, Inc. ("Autodesk").

 THE DATA IS PROVIDED "AS IS" AND WITHOUT WARRANTY.
 ALL WARRANTIES ARE EXPRESSLY EXCLUDED AND DISCLAIMED. AUTODESK MAKES NO
 WARRANTY OF ANY KIND WITH RESPECT TO THE DATA, EXPRESS, IMPLIED OR ARISING
 BY CUSTOM OR TRADE USAGE, AND DISCLAIMS ANY IMPLIED WARRANTIES OF TITLE, 
 NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE OR USE. 
 WITHOUT LIMITING THE FOREGOING, AUTODESK DOES NOT WARRANT THAT THE OPERATION
 OF THE DATA WILL BE UNINTERRUPTED OR ERROR FREE. 
 
 IN NO EVENT SHALL AUTODESK, ITS AFFILIATES, PARENT COMPANIES, LICENSORS
 OR SUPPLIERS ("AUTODESK GROUP") BE LIABLE FOR ANY LOSSES, DAMAGES OR EXPENSES
 OF ANY KIND (INCLUDING WITHOUT LIMITATION PUNITIVE OR MULTIPLE DAMAGES OR OTHER
 SPECIAL, DIRECT, INDIRECT, EXEMPLARY, INCIDENTAL, LOSS OF PROFITS, REVENUE
 OR DATA, COST OF COVER OR CONSEQUENTIAL LOSSES OR DAMAGES OF ANY KIND),
 HOWEVER CAUSED, AND REGARDLESS OF THE THEORY OF LIABILITY, WHETHER DERIVED
 FROM CONTRACT, TORT (INCLUDING, BUT NOT LIMITED TO, NEGLIGENCE), OR OTHERWISE,
 ARISING OUT OF OR RELATING TO THE DATA OR ITS USE OR ANY OTHER PERFORMANCE,
 WHETHER OR NOT AUTODESK HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH LOSS
 OR DAMAGE. 

**************************************************************************************/

#include <kaydaradef.h>
#ifndef KFBX_DLL 
	#define KFBX_DLL K_DLLIMPORT
#endif

#include <kaydara.h>

#include <kfbxplugins/kfbxobject.h>
#include <kfbxplugins/kfbxgroupname.h>

#include <klib/kstring.h>
#include <klib/karrayul.h>
#include <klib/kname.h>
#include <kfbxmath/kfbxmatrix.h>

#include <fbxfilesdk_nsbegin.h>

/** This class is used to hold meta-data information on nodes.
  * \nosubgrouping
  *
  * This class does not offer any new functionality over a regular KFbxObject;
  * all meta-data information should be stored in properties.
  * 
  */
class KFBX_DLL KFbxObjectMetaData : public KFbxObject
{
	KFBXOBJECT_DECLARE(KFbxObjectMetaData,KFbxObject);
public:

///////////////////////////////////////////////////////////////////////////////
//
//  WARNING!
//
//	Anything beyond these lines may not be documented accurately and is 
// 	subject to change without notice.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef DOXYGEN_SHOULD_SKIP_THIS

	// Clone
	virtual KFbxObject* Clone(KFbxObject* pContainer, KFbxObject::ECloneType pCloneType) const;

protected:
	
	/** Create an object of type KFbxObjectMetaData.
	 * \param pManager (need to exist for extended validation).
	 * \param pName Name of this KFbxObjectMetaData.
	 */
	KFbxObjectMetaData(KFbxSdkManager& pManager, char const* pName);
	
	/** Deletes this object. 
	 */
	~KFbxObjectMetaData();
	
	// From KFbxObject
	virtual KString		GetTypeName() const;
	virtual KStringList	GetTypeFlags() const;

	//! Assignment operator.
    KFbxObjectMetaData& operator=(KFbxObjectMetaData const& pMetaData);

	friend class KFbxReaderFbx;
	friend class KFbxWriterFbx6;

#endif // #ifndef DOXYGEN_SHOULD_SKIP_THIS 

};

typedef KFbxObjectMetaData* HKFbxObjectMetaData;

#include <fbxfilesdk_nsend.h>

#endif // #ifndef _FBXSDK_OBJECTMETADATA_H_


