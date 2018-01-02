#ifndef __GPU_MODULE_INTERFACE__
#define __GPU_MODULE_INTERFACE__
/*------------------------------------------------------------------------------------------*\
 * FILE: GPU_Module_Interface.h
 *==========================================================================================
 * Copyright 2016   O-Film Technologies, Inc., All Rights Reserved.
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
 * VERSION: 27 9月 2016 dota2_black
 *------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------------------------
 * Standard Header Files
 *------------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
/*------------------------------------------------------------------------------------------
 * Other Header Files
 *------------------------------------------------------------------------------------------*/
#include "avm/smc.h"
#include "commondef.h"
#include "gpu_public_data_struct.h"
/*------------------------------------------------------------------------------------------
 * Exported Preprocessor #define Constants
 *------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------
 * Exported Preprocessor #define MACROS
 *------------------------------------------------------------------------------------------*/
#define DLL_PUBLIC __attribute__ ((visibility ("default")))
#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
/*------------------------------------------------------------------------------------------
 * Exported Type Declarations
 *------------------------------------------------------------------------------------------*/

//重定义, 省去包含egl等头文件
typedef unsigned int GLuint;

#include "luminb_result.h"
/*------------------------------------------------------------------------------------------
 * Exported Object Declarations
 *------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------
 * Exported Function Prototypes
 *------------------------------------------------------------------------------------------*/

typedef enum RenderInterfaceErrorCodeTag
{
	RENDER_INTERFACE_NO_ERROR = 0,
	RENDER_INTERFACE_INPUT_DATA_NULL,
	RENDER_INTERFACE_RET_NULL,
	RENDER_INTERFACE_ERROR_NUM,
}
RenderInterfaceErrorCodeT;


typedef enum Changan_Track_Cam_Region_Index_Tag
{
    CCAG_TRACK_CAMERA_REGION_FRONT = 0,
    CCAG_TRACK_CAMERA_REGION_REAR,
    CCAG_TRACK_CAMERA_REGION_LEFT,
    CCAG_TRACK_CAMERA_REGION_RIGHT,
    CCAG_TRACK_CAMERA_REGION_FRONT_LEFT,
    CCAG_TRACK_CAMERA_REGION_FRONT_RIGHT,
    CCAG_TRACK_CAMERA_REGION_REAR_LEFT,
    CCAG_TRACK_CAMERA_REGION_REAR_RIGHT,    
    CCAG_TRACK_CAMERA_REGION_NUMS
} Changan_Track_Cam_Region_Index_T;
 
 
 typedef enum Changan_Cam_Region_Index_Tag
 {
    CCAG_CAMERA_REGION_FRONT = 9,
    CCAG_CAMERA_REGION_REAR,
    CCAG_CAMERA_REGION_LEFT,
    CCAG_CAMERA_REGION_RIGHT
 
 } Changan_Cam_Region_Index_T;
	

typedef enum RenderDataTypeTag
{
	RENDER_DATA_CAN = 1,
	RENDER_DATA_VIEW_CMD,
	RENDER_DATA_TYPE_NUM,
}
RenderDataTypeT;

typedef struct RenderDataHeaderTag
{
	unsigned short dataTypeId;
	unsigned int   dataLength;
}
RenderDataHeaderT;

typedef struct RenderDataTag
{
	RenderDataHeaderT dataHeader;
	void*             data;
}
RenderDataT;


DLL_PUBLIC int SetRenderData(RenderDataT* pRenderData);	

DLL_PUBLIC void InitADASMdlHMI(st_ADAS_Mdl_HMI_T **pAdasMdlHmiHandle,int HmiMdlNum);
DLL_PUBLIC void SetEglBaseParameter(EGLDisplay display,EGLContext context,EGLSurface surf);
DLL_PUBLIC int InitAppNew(int width, int height, st_GPU_Init_Config_T* gpu_init);
DLL_PUBLIC int UpdateApp(unsigned int view_control_flag,GLuint texYuv[]);
DLL_PUBLIC int OnMouseSingleUp(int x,int y);
DLL_PUBLIC int OnMouseSingleDown(int x,int y);
DLL_PUBLIC int OnMouseSingleMove(int x,int y);

DLL_PUBLIC void UpdateGpuMdlCalibRslt(unsigned int ** out_config_store,
                                      float* data_buffer,
                                      unsigned short* gui_index_buffer,
                                      GPU_MDL_POSE pose);

DLL_PUBLIC void UpdateGpuLuminanceBalanceCof(CoefYUV *lb_result);
DLL_PUBLIC void UpdateGPUMdlCANData(CAN_DATA in_CAN_data);

DLL_PUBLIC void UpdateCustomHMIData();
DLL_PUBLIC void UpdateStichAngle(unsigned char seam_change_flag[],StitcherResult* sticher_result);

DLL_PUBLIC void UpdateAPAResult(APAOverlayStruct *pAPAReslt);

DLL_PUBLIC void UpdateCtaResult(unsigned char pCtaStatus, void* pCtaResult);

DLL_PUBLIC void setHMIAlgStatus(int alg_status_value);
DLL_PUBLIC void setHMIChainsStatus(int demo_status_value);
    
DLL_PUBLIC void GetSonarPLDRslt(Radar_PLD_Result *pReslt);

DLL_PUBLIC void SetShutdownDisplay();

/*
param key_mode: 
    0, next_view change mode.
    1, view_index change mode.
*/
DLL_PUBLIC void MockTouchEvent(unsigned char key_value, unsigned char key_mode = 0);

/*------------------------------------------------------------------------------------------
 * Exported Inline Function Definitions and #define Function-Like Macros
 *------------------------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif
/*------------------------------------------------------------------------------------------
 * File Revision History (top to bottom: first revision to last revision)
 *------------------------------------------------------------------------------------------
 *
 * Date             SCR                   userid                   Description
 * -----------------------------------------------------------------------------------------

 *------------------------------------------------------------------------------------------*/
#endif /* } GPU_Module_Interface_H */





