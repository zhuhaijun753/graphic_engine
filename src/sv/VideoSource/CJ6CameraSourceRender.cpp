/*===========================================================================*\
 * FILE: template.c
 *===========================================================================
 * Copyright 2008 O-Film Technologies, Inc., All Rights Reserved.
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

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "CJ6CameraSourceRender.h"
#include "../../XrCore/XrSrc/External/XrHeaders.h"
#include "../fileloader.h"
#include "../DataStruct.h"
#include "../videoloader.h"
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/

	


/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * External Object Definitions
\*===========================================================================*/

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
static char *m_ShaderName[6]={"OVVertShaderNew.vtx","OVFragShader_J6.frg","OVVertShaderSV2D.vtx","OVFragShaderSV2D_J6.frg","OVVertShaderEmirror.vtx","OVFragEmirror_J6.frg"};
static char *m_CamIMGName[4] = {"front.bmp","rear.bmp","left.bmp","right.bmp"};
/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/

void CJ6CameraSourceRender::Init(char *file_path)
{
    memcpy(m_file_path,file_path,MAX_NAME_LENGTH*sizeof(char));

	ITextureDelegate* tdelegate[4];

	for (int i=0;i<4;i++) {

		
		m_texture_index[i] =-1;
	}   

	
    return;

}

void CJ6CameraSourceRender::SetCameraSourceToMaterial(IMaterial *pMaterial,int camera_index)
{
    printf("\r\n material = 0x%x,index = %d",pMaterial,camera_index);
	
    printf("\r\n m_texture_index[%d] = %d",camera_index,m_texture_index[camera_index]);
	
    char TempName[MAX_NAME_LENGTH];
	sprintf(&(TempName[0]),"%s%s",m_file_path,m_CamIMGName[camera_index]);
	printf("\r\n load texture name[%s]",TempName);
	//pMaterial->SetDiffuseMap(m_texture_index[camera_index]);
	
	pMaterial->SetDiffuseMap(TempName);
	m_texture_id[camera_index]= pMaterial->GetDiffuseMap()->texid;
	return;

}
void CJ6CameraSourceRender::SetCameraSourceMask(int textureid,int camera_index)
{

	m_masktexture_id[camera_index]=textureid;
	return;

}

int CJ6CameraSourceRender::GetCameraSourceTextureId(int index)
{
    return m_texture_id[index];

}

void CJ6CameraSourceRender::UpdateCameraSource(int index,unsigned int texBuffer)
{
    unsigned char internal_index;
    if(index == 0)
    {
        internal_index = front_camera_index;
    }
	else if(index == 1)
	{
        internal_index = rear_camera_index;
	}
	else if(index == 2)
	{
        internal_index = left_camera_index;
	}	
	else if(index == 3)
	{
        internal_index = right_camera_index;
	}	


    m_texture_buffer[internal_index]=texBuffer;
    return;
}

void CJ6CameraSourceRender::UseCameraTexture(int index)
{
    if(index>=4)
    {
        index = 3;
    }

	glBindTexture(GL_TEXTURE_EXTERNAL_OES, m_texture_buffer[index]); 
}
  
void CJ6CameraSourceRender::UseCameraMaskTexture(int index)
{
    if(index>=4)
    {
        index = 3;
    }

	 glActiveTexture(GL_TEXTURE0);
	 glBindTexture(GL_TEXTURE_2D, m_masktexture_id[index]);
}


unsigned char CJ6CameraSourceRender::GetShaderName(char *pVertexShader,int type)
{
   // char *TempName[MAX_NAME_LENGTH];
	sprintf(pVertexShader,"%s%s",m_file_path,m_ShaderName[type]);

	return 0;
}

/*===========================================================================*\
 * External Function Definitions
\*===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date             SCR                   userid                   Description
 * ----------------------------------------------------------------------------------

\*===========================================================================*/

