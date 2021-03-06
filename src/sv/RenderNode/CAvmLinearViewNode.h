/*===========================================================================*\
 * FILE: CAvmLinearViewNode.h
 *===========================================================================
 * Copyright 2003 O-Film Technologies, Inc., All Rights Reserved.
 * O-Film Confidential
 *
 * DESCRIPTION:
 *
 * ABBREVIATIONS:
 *   TODO: List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *
 * DEVIATIONS FROM STANDARDS:
 *   TODO: List of deviations from standards in this file, or
 *   None.
 *
\*===========================================================================*/

#ifndef _CAVM_LINEARVIEW_NODE_H_
#define _CAVM_LINEARVIEW_NODE_H_

#include "../../XrCore/XrSrc/External/XrHeaders.h"
#include "../DataStruct.h"
#include "../SVDelegate.h"


class CAvmLinearViewNode
{
public:
	CAvmLinearViewNode();
	virtual ~CAvmLinearViewNode();
	virtual int InitNode(class IXrCore* pXrcore);
	virtual int UpdateNode();
	virtual int SetVisibility(unsigned char pVisibilityFlag);
	virtual int ResetLinearViewNodeRegion(Region* pRegion);
	

	class ISceneNode*  GetAvmLinearViewNode();
	class ICamera*  GetAvmLinearViewCamera();
	int SetClear(unsigned char pColorFlag, unsigned char pDepthFlag);

private:
	class ISceneNode* m_180DegreeViewNode;	
	int         m_180DegreeViewNodeId;
	class IMaterial* m_180DegreeViewMtl;
	int         m_180DegreeViewMtlId;
	class IMesh*	 m_180DegreeViewMesh[3];
	int			m_180DegreeViewMeshId[3];
	class INode*      m_180DegreeViewPlane[8];

	class IXrCore*	m_xrCore;

	class ICamera*	m_180DegreeViewCamera;
	int			m_180DegreeViewCameraId;

	class RenderDelegateCV*		m_renderDelegate;
	
	SurroundViewCameraParamsT*   m_180DegreerViewCameraParams;

	GLfloat* m_front_afVertices[3];
	GLfloat* m_rear_afVertices[3];

	GLfloat* m_afVertices[3];

	int m_meshWidth;
	int m_meshHeight;

	unsigned char m_visibilityFlag;

	unsigned char m_depthClearFlag;
	unsigned char m_colorClearFlag;
};

#endif // _CAVM_LINEARVIEW_NODE_H_

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *   Date        userid       Description
 * ----------- ----------    -----------
 *  11/01/17   Jensen Wang   Create the CAvmLinearViewNode class.
\*===========================================================================*/