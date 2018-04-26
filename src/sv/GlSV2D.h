#ifndef __GL_SV_2D_H__
#define __GL_SV_2D_H__
#include "DataStruct.h"
#include "fileloader.h"
#include "../XrCore/XrSrc/External/XrHeaders.h"

#include "../XrCore/XrSrc/XrUILibrary/XrUILibrary.h"
#include "AVMData.h"

#include "TS_config.h"

#define RENDER_BUFFER_TOTAL 2
#define FRAME_BUFFER_TOTAL 2
#define PRINT_GL_ERROR printf

#define REAR_SINGLE_LEFT 0.83375
#define REAR_SINGLE_RIGHT  0.19
#define REAR_SINGLE_TOP   0.0645
#define REAR_SINGLE_BOTTOM  0.9335
#if 0
#define FRONT_SINGLE_LEFT 0.0625
#define FRONT_SINGLE_RIGHT 0.9021 
#define FRONT_SINGLE_TOP   0.1
#define FRONT_SINGLE_BOTTOM  0.85
#else
#define FRONT_SINGLE_LEFT 0.143
#define FRONT_SINGLE_RIGHT 0.831
#define FRONT_SINGLE_TOP   0.035
#define FRONT_SINGLE_BOTTOM 0.904

#endif

#define LEFT_SINGLE_LEFT 0.29456
#define LEFT_SINGLE_RIGHT 0.95652 
#define LEFT_SINGLE_TOP   0.0196
#define LEFT_SINGLE_BOTTOM  1.0



#define RIGHT_SINGLE_LEFT  0.75
#define RIGHT_SINGLE_RIGHT  0.05
#define RIGHT_SINGLE_TOP   1.0
#define RIGHT_SINGLE_BOTTOM  0.0196


enum
{
  ROT_X_ADJ=0,
  ROT_Y_ADJ,
  ROT_Z_ADJ,
  POS_X_ADJ,
  POS_Y_ADJ,
  POS_Z_ADJ,
};


enum
{
   ADJUST_DIRECT_POS=0,
   ADJUST_DIRECT_NEG
};


#define ANGLE_ADJUST_STEP  2

#define LINEAR_CAMERA_WIDTH 640
#define LINEAR_CAMERA_HEIGHT 640
#define LINEAR_CAMERA_CX 200
#define LINEAR_CAMERA_CY 200
#define LINEAR_CAMERA_SKEW_C 1
#define LINEAR_CAMERA_SKEW_D 0
#define LINEAR_CAMERA_SKER_E 0
#define LINEAR_CAMERA_HFOV  50.0
#define LINEAR_CAMERA_VFOV  50.0

#define RIGHT_LINEAR_CAM_R_X    1.7929496
#define RIGHT_LINEAR_CAM_R_Y    0.0461896
#define RIGHT_LINEAR_CAM_R_Z    1.024359
#define RIGHT_LINEAR_CAM_T_X    5835.072022
#define RIGHT_LINEAR_CAM_T_Y     -1122.099127
#define RIGHT_LINEAR_CAM_T_Z     -1021.658668
//#define RIGHT_LINEAR_CAM_ROT_X   28
//#define RIGHT_LINEAR_CAM_ROT_Y    44
//#define RIGHT_LINEAR_CAM_ROT_Z   60

#define RIGHT_LINEAR_CAM_ROT_X   0
#define RIGHT_LINEAR_CAM_ROT_Y   63
#define RIGHT_LINEAR_CAM_ROT_Z   43

#if 0
#define RIGHT_SIDE_VIEW_ROI_START_X  0
#define RIGHT_SIDE_VIEW_ROI_START_Y  0
#define RIGHT_SIDE_VIEW_ROI_END_X   639
#define RIGHT_SIDE_VIEW_ROI_END_Y   639

#else
#define RIGHT_SIDE_VIEW_ROI_START_X  47
#define RIGHT_SIDE_VIEW_ROI_START_Y  168
#define RIGHT_SIDE_VIEW_ROI_END_X   463
#define RIGHT_SIDE_VIEW_ROI_END_Y   483

//#define RIGHT_SIDE_VIEW_ROI_START_X  57
//#define RIGHT_SIDE_VIEW_ROI_START_Y  108
//#define RIGHT_SIDE_VIEW_ROI_END_X   463
//#define RIGHT_SIDE_VIEW_ROI_END_Y   483

#endif
#define RIGHT_SIDE_VIEW_MESH_WIDTH  11     //actual width +1
#define RIGHT_SIDE_VIEW_MESH_HEIGHT 11     //actual height +1



#define LEFT_LINEAR_CAM_R_X    1.7929496
#define LEFT_LINEAR_CAM_R_Y    0.0461896
#define LEFT_LINEAR_CAM_R_Z    1.024359
#define LEFT_LINEAR_CAM_T_X    5835.072022
#define LEFT_LINEAR_CAM_T_Y     -1122.099127
#define LEFT_LINEAR_CAM_T_Z     -1021.658668
#define LEFT_LINEAR_CAM_ROT_X   0
#define LEFT_LINEAR_CAM_ROT_Y    -63
#define LEFT_LINEAR_CAM_ROT_Z   -43

#if 0
#define LEFT_SIDE_VIEW_ROI_START_X  0
#define LEFT_SIDE_VIEW_ROI_START_Y  0
#define LEFT_SIDE_VIEW_ROI_END_X   639
#define LEFT_SIDE_VIEW_ROI_END_Y  639


#else

#define LEFT_SIDE_VIEW_ROI_START_X  0
#define LEFT_SIDE_VIEW_ROI_START_Y  177
#define LEFT_SIDE_VIEW_ROI_END_X   394
#define LEFT_SIDE_VIEW_ROI_END_Y  507

/*
#define LEFT_SIDE_VIEW_ROI_START_X  17
#define LEFT_SIDE_VIEW_ROI_START_Y  118
#define LEFT_SIDE_VIEW_ROI_END_X   463
#define LEFT_SIDE_VIEW_ROI_END_Y   473
*/
#endif


#define RENDER_BUFFER_TOTAL 2
#define FRAME_BUFFER_TOTAL 2
#define PRINT_GL_ERROR printf

#define REAR_SINGLE_LEFT 0.81
#define REAR_SINGLE_RIGHT  0.19
#define REAR_SINGLE_TOP   0.0
#define REAR_SINGLE_BOTTOM  1.0
#if 0
#define REAR_SINGLE_LEFT 0.8320
#define REAR_SINGLE_RIGHT  0.203125
#define REAR_SINGLE_TOP   0.0645
#define REAR_SINGLE_BOTTOM  0.9335
#endif
#if 0
#define FRONT_SINGLE_LEFT 0.0625
#define FRONT_SINGLE_RIGHT 0.9021 
#define FRONT_SINGLE_TOP   0.1
#define FRONT_SINGLE_BOTTOM  0.85
#else
//#define FRONT_SINGLE_LEFT 0.19
//#define FRONT_SINGLE_RIGHT 0.81
#define FRONT_SINGLE_LEFT 0.2
#define FRONT_SINGLE_RIGHT 0.8
#define FRONT_SINGLE_TOP   0.0
#define FRONT_SINGLE_BOTTOM 1.0

#endif


#define CLC_CAM_WIDTH  640
#define CLC_CAM_HEIGHT 480
#define CLC_CAM_CX   320
#define CLC_CAM_CY 240
#define CLC_CAM_PITCH 60
#define CLC_CAM_ROLL 0
#define CLC_CAM_YAW  0
#define REAR_CLC_CAM_PITCH 57



#define FRONT_CLC_VIEW_ROI_START_X  86
#define FRONT_CLC_VIEW_ROI_START_Y  150
#define FRONT_CLC_VIEW_ROI_END_X   550
#define FRONT_CLC_VIEW_ROI_END_Y   458

#define FRONT_CLC_VIEW_MESH_WIDTH  21     //actual width +1
#define FRONT_CLC_VIEW_MESH_HEIGHT 21     //actual height +1

#if 1
#define REAR_CLC_VIEW_ROI_START_X  94
#define REAR_CLC_VIEW_ROI_START_Y  156
#define REAR_CLC_VIEW_ROI_END_X   554
#define REAR_CLC_VIEW_ROI_END_Y   456
#else
#define REAR_CLC_VIEW_ROI_START_X  0
#define REAR_CLC_VIEW_ROI_START_Y  0
#define REAR_CLC_VIEW_ROI_END_X   639
#define REAR_CLC_VIEW_ROI_END_Y   479
#endif
#define REAR_CLC_VIEW_MESH_WIDTH  21     //actual width +1
#define REAR_CLC_VIEW_MESH_HEIGHT 21     //actual height +1






class GlSV2D 
{
public:
	GlSV2D();

	int Init();
	int InitLinear();
	int Update(void);


	int GetIndexBuffer(int Index,GLushort **pIndexBuffer, unsigned int *BufSize);
	
	int GetVertexBuffer(int Index,float **pVertexBuffer, unsigned int *BufSize);


	int GenerateSideSingleViewLUT(int camera_index,float *pVert);
	int InitSideViewBuffer(int width, int height, GLfloat **pData, GLushort **pIndex, unsigned int *puiVertSize, unsigned int *puiIndexSize,unsigned char index_flag = 0);
	void AdjustSideSingleViewLUT(int camera_index,unsigned char adjust_port,unsigned char adjust_direct);
	int InitFrontRearViewBuffer(int width,int height,GLfloat **pData,GLushort **pIndex,unsigned int *puiVertSize,unsigned int *puiIndexSize);
	int GenerateFrontRearSingleViewLUT(int camera_index,float *pVert);

	int InitFrontRearSingleViewCamLUT(int camera_index);

private:

	GLuint *uiConfig;
	
	GLuint *uiConfigAlpha;

	

	GLfloat *m_pfVertexBuff[eMeshIndexMax];
	
	//GLfloat *m_pfVertexSingleView[eSingleEnd];

	
	GLushort	 *m_pucIndexBuff[eMeshIndexMax];
	
	
	unsigned int m_SideViewVertSize[4];
	unsigned int m_SideViewIndexSize[4];
	
	Cam_Model *m_cam_linear[4];
	
	Cam_Model_Cyli *m_cam_clc[4];
	float m_linear_cam[4][3];
	
	unsigned char m_camType;

};

#endif //#ifndef __GL_SV_DEMO_H__
