/*===========================================================================*\
 * FILE: CSVDemoLkaHmi.h
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

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "CSVDemoLkaHmi.h"
#include "gpu_log.h"

class CDemoActionTrigger : public IActionTrigger
{
public:
    CDemoActionTrigger()
    { 
        ;
    }
    virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
    {
        int i = 0;
    }
    virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
    {
    }
    virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
    {
        
    }

private:
};

CSVDemoLkaHmi::CSVDemoLkaHmi(IUINode* pUiNode, int pUiNodeId): ISVHmi::ISVHmi(pUiNode, pUiNodeId)
{
    memset(m_trigger, 0, DEMO_LKA_ICON_NUMS * sizeof(IActionTrigger*));
    
    memset(m_buttonVisibility, 1, DEMO_LKA_ICON_NUMS * sizeof(unsigned char));

    memset(m_buttonImage, 0, DEMO_LKA_ICON_NUMS * sizeof(unsigned char));

}

CSVDemoLkaHmi::~CSVDemoLkaHmi()
{
    for(int i = DEMO_LKA_STATUS_BAR_BKG; i < DEMO_LKA_ICON_NUMS; i++)
    {
        SAFE_DELETE(m_baseButtonData[i].icon_file_name[0]);     
        if(i == DEMO_LKA_DIRECTION_PROMPT
            || i == DEMO_LKA_STEERING_PROMPT)
        {
            SAFE_DELETE(m_baseButtonData[i].icon_file_name[1]); 
        }
        if(i == DEMO_LKA_LEFT_SIDE_LANE
            || i == DEMO_LKA_RIGHT_SIDE_LANE)
        {
            SAFE_DELETE(m_baseButtonData[i].icon_file_name[1]); 
            SAFE_DELETE(m_baseButtonData[i].icon_file_name[2]); 
        }
            
        SAFE_DELETE(m_trigger[i]);
        
        SAFE_DELETE(m_baseButton[i]);
    }

    SAFE_DELETE(m_speedTxtData.textContent[0]);
    SAFE_DELETE(m_speedTxt);
}
    
int CSVDemoLkaHmi::SetHmiParams()
{
    m_baseButtonData[DEMO_LKA_STATUS_BAR_BKG].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_STATUS_BAR_BKG].show_flag = 1;
    m_baseButtonData[DEMO_LKA_STATUS_BAR_BKG].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_STATUS_BAR_BKG].icon_file_name[0] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_STATUS_BAR_BKG].icon_file_name[0],"%sCar/LKA/status_bar_bkg.dds",XR_RES);  
    
    m_baseButtonData[DEMO_LKA_SPEED_PROMPT].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_SPEED_PROMPT].show_flag = 1;
    m_baseButtonData[DEMO_LKA_SPEED_PROMPT].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_SPEED_PROMPT].icon_file_name[0] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_SPEED_PROMPT].icon_file_name[0],"%sCar/LKA/speed_prompt.dds",XR_RES); 

    m_baseButtonData[DEMO_LKA_DIRECTION_PROMPT].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_DIRECTION_PROMPT].show_flag = 1;
    m_baseButtonData[DEMO_LKA_DIRECTION_PROMPT].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_DIRECTION_PROMPT].icon_file_name[0] = new char [50];
    m_baseButtonData[DEMO_LKA_DIRECTION_PROMPT].icon_file_name[1] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_DIRECTION_PROMPT].icon_file_name[0],"%sCar/LKA/direction_left_prompt.dds",XR_RES); 
    sprintf(m_baseButtonData[DEMO_LKA_DIRECTION_PROMPT].icon_file_name[1],"%sCar/LKA/direction_right_prompt.dds",XR_RES); 

    m_baseButtonData[DEMO_LKA_STEERING_PROMPT].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_STEERING_PROMPT].show_flag = 1;
    m_baseButtonData[DEMO_LKA_STEERING_PROMPT].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_STEERING_PROMPT].icon_file_name[0] = new char [50];
    m_baseButtonData[DEMO_LKA_STEERING_PROMPT].icon_file_name[1] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_STEERING_PROMPT].icon_file_name[0],"%sCar/LKA/steering_auto_work.dds",XR_RES); 
    sprintf(m_baseButtonData[DEMO_LKA_STEERING_PROMPT].icon_file_name[1],"%sCar/LKA/steering_manual_work.dds",XR_RES); 

    m_baseButtonData[DEMO_LKA_WARNING].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_WARNING].show_flag = 1;
    m_baseButtonData[DEMO_LKA_WARNING].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_WARNING].icon_file_name[0] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_WARNING].icon_file_name[0],"%sCar/LKA/warning.dds",XR_RES); 

    m_baseButtonData[DEMO_LKA_LANE_BKG].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_LANE_BKG].show_flag = 1;
    m_baseButtonData[DEMO_LKA_LANE_BKG].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_LANE_BKG].icon_file_name[0] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_LANE_BKG].icon_file_name[0],"%sCar/LKA/lane_bkg.dds",XR_RES); 

    m_baseButtonData[DEMO_LKA_LEFT_SIDE_LANE].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_LEFT_SIDE_LANE].show_flag = 1;
    m_baseButtonData[DEMO_LKA_LEFT_SIDE_LANE].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_LEFT_SIDE_LANE].icon_file_name[0] = new char [50];
    m_baseButtonData[DEMO_LKA_LEFT_SIDE_LANE].icon_file_name[1] = new char [50];
    m_baseButtonData[DEMO_LKA_LEFT_SIDE_LANE].icon_file_name[2] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_LEFT_SIDE_LANE].icon_file_name[0],"%sCar/LKA/lane_left_org.dds",XR_RES); 
    sprintf(m_baseButtonData[DEMO_LKA_LEFT_SIDE_LANE].icon_file_name[1],"%sCar/LKA/lane_left_blue.dds",XR_RES);
    sprintf(m_baseButtonData[DEMO_LKA_LEFT_SIDE_LANE].icon_file_name[2],"%sCar/LKA/lane_left_warning.dds",XR_RES); 

    m_baseButtonData[DEMO_LKA_RIGHT_SIDE_LANE].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_RIGHT_SIDE_LANE].show_flag = 1;
    m_baseButtonData[DEMO_LKA_RIGHT_SIDE_LANE].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_RIGHT_SIDE_LANE].icon_file_name[0] = new char [50];
    m_baseButtonData[DEMO_LKA_RIGHT_SIDE_LANE].icon_file_name[1] = new char [50];
    m_baseButtonData[DEMO_LKA_RIGHT_SIDE_LANE].icon_file_name[2] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_RIGHT_SIDE_LANE].icon_file_name[0],"%sCar/LKA/lane_right_org.dds",XR_RES); 
    sprintf(m_baseButtonData[DEMO_LKA_RIGHT_SIDE_LANE].icon_file_name[1],"%sCar/LKA/lane_right_blue.dds",XR_RES); 
    sprintf(m_baseButtonData[DEMO_LKA_RIGHT_SIDE_LANE].icon_file_name[2],"%sCar/LKA/lane_right_warning.dds",XR_RES); 

    m_baseButtonData[DEMO_LKA_CAR].icon_type = DYNAMIC_ICON;
    m_baseButtonData[DEMO_LKA_CAR].show_flag = 1;
    m_baseButtonData[DEMO_LKA_CAR].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_CAR].icon_file_name[0] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_CAR].icon_file_name[0],"%sCar/LKA/car.dds",XR_RES); 

    m_baseButtonData[DEMO_LKA_ERROR_WARNING_BKG].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_ERROR_WARNING_BKG].show_flag = 1;
    m_baseButtonData[DEMO_LKA_ERROR_WARNING_BKG].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_ERROR_WARNING_BKG].icon_file_name[0] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_ERROR_WARNING_BKG].icon_file_name[0],"%sCar/LKA/error_bkg.dds",XR_RES); 

    m_baseButtonData[DEMO_LKA_ERROR_WARNING_TXT].icon_type = STATIC_ICON;
    m_baseButtonData[DEMO_LKA_ERROR_WARNING_TXT].show_flag = 1;
    m_baseButtonData[DEMO_LKA_ERROR_WARNING_TXT].show_icon_num = 0;
    m_baseButtonData[DEMO_LKA_ERROR_WARNING_TXT].icon_file_name[0] = new char [50];
    sprintf(m_baseButtonData[DEMO_LKA_ERROR_WARNING_TXT].icon_file_name[0],"%sCar/LKA/error_txt.dds",XR_RES); 


    for(int i = DEMO_LKA_STATUS_BAR_BKG; i < DEMO_LKA_ICON_NUMS; i++)
    {
        m_baseButtonData[i].pos[0] = m_buttonPos[i][BUTTON_POS_X];
        m_baseButtonData[i].pos[1] = m_buttonPos[i][BUTTON_POS_Y];
        m_baseButtonData[i].width = m_buttonSize[i][BUTTON_SIZE_WIDTH];
        m_baseButtonData[i].height = m_buttonSize[i][BUTTON_SIZE_HEIGHT];
        m_baseButtonData[i].delegate_func = NULL;
        m_baseButtonData[i].trigger = m_trigger[i];

        if(i == DEMO_LKA_CAR)
        {
            m_speedTxt = new HmiTextEdit(&m_speedTxtData, m_uiNode);
        }
        m_baseButton[i] = new HMIButton(&(m_baseButtonData[i]),m_uiNode);
        m_baseButton[i]->SetVisibility(0);
    }
    m_speedTxtVisibility = 0;

    return DEMO_LKA_HMI_NORMAL;
}
int CSVDemoLkaHmi::Init(int window_width, int window_height)
{
    m_screenWidth = window_width;
    m_screenHeight = window_height;

    float heightInterval = 80.0;
    float stitchRegionWidth = window_width * 0.35;
    float stitchRegionHeight = window_height - 2.0 * heightInterval;
    float iconHInterval = 30.0;
    float iconVInterval = 20.0;
    float iconLaneWidth = 20.0;
    float iconCarVInterval = 20.0;
    float left_panel_width = 100.0;
    

    SetHmiElementProperty(DEMO_LKA_STATUS_BAR_BKG, stitchRegionWidth + left_panel_width, heightInterval, window_width - stitchRegionWidth - left_panel_width, 138.0);
    SetHmiElementProperty(DEMO_LKA_ERROR_WARNING_BKG, stitchRegionWidth + left_panel_width, heightInterval, window_width - stitchRegionWidth - left_panel_width, 138.0);


    m_speedTxtData.pos[0] = m_buttonPos[DEMO_LKA_STATUS_BAR_BKG][BUTTON_POS_X] + 15.0;
    m_speedTxtData.pos[1] = m_buttonPos[DEMO_LKA_STATUS_BAR_BKG][BUTTON_POS_Y] + 42.0;
    m_speedTxtData.width = 50;
    m_speedTxtData.font_size = 40.0;
    m_speedTxtData.line_num = 1;
    m_speedTxtData.visibilityStatus = 1;
    m_speedTxtData.targetIndex = -1;
    m_speedTxtData.insertFlag = InsertFlag_Default;
    m_speedTxtData.fontTypeMtlName = XR_RES"text_box.ttf";
    m_speedTxtData.trigger = NULL;
    m_speedTxtData.textColor[0] = 1.0;
    m_speedTxtData.textColor[1] = 1.0;
    m_speedTxtData.textColor[2] = 1.0;
    m_speedTxtData.textContent[0] = new char[100];
    char* ptext = "75";
    sprintf(m_speedTxtData.textContent[0],"%s", ptext);
    

    SetHmiElementProperty(DEMO_LKA_SPEED_PROMPT, m_speedTxtData.pos[0] + 90.0, m_speedTxtData.pos[1] + 35.0, 29.0, 13.0);

    m_buttonSize[DEMO_LKA_LANE_BKG][BUTTON_SIZE_HEIGHT] = 132.0;
    m_buttonSize[DEMO_LKA_LANE_BKG][BUTTON_SIZE_WIDTH] = 287.0;
    SetHmiElementProperty(DEMO_LKA_LANE_BKG, m_buttonPos[DEMO_LKA_STATUS_BAR_BKG][BUTTON_POS_X] + (m_buttonSize[DEMO_LKA_STATUS_BAR_BKG][BUTTON_SIZE_WIDTH] - m_buttonSize[DEMO_LKA_LANE_BKG][BUTTON_SIZE_WIDTH]) * 0.5, m_buttonPos[DEMO_LKA_STATUS_BAR_BKG][BUTTON_POS_Y] + (m_buttonSize[DEMO_LKA_STATUS_BAR_BKG][BUTTON_SIZE_HEIGHT] - m_buttonSize[DEMO_LKA_LANE_BKG][BUTTON_SIZE_HEIGHT]) * 0.5, 287.0, 132.0);

    m_buttonSize[DEMO_LKA_DIRECTION_PROMPT][BUTTON_SIZE_WIDTH] = 48.0;
    m_buttonSize[DEMO_LKA_DIRECTION_PROMPT][BUTTON_SIZE_HEIGHT] = 45.0;
    SetHmiElementProperty(DEMO_LKA_DIRECTION_PROMPT, m_buttonPos[DEMO_LKA_LANE_BKG][BUTTON_POS_X] - m_buttonSize[DEMO_LKA_DIRECTION_PROMPT][BUTTON_SIZE_WIDTH] - iconHInterval, m_buttonPos[DEMO_LKA_STATUS_BAR_BKG][BUTTON_POS_Y] + (m_buttonSize[DEMO_LKA_STATUS_BAR_BKG][BUTTON_SIZE_HEIGHT] - m_buttonSize[DEMO_LKA_DIRECTION_PROMPT][BUTTON_SIZE_HEIGHT]) * 0.5, 48.0, 45.0);

    m_buttonSize[DEMO_LKA_STEERING_PROMPT][BUTTON_SIZE_HEIGHT] = 45.0;
    m_buttonSize[DEMO_LKA_STEERING_PROMPT][BUTTON_SIZE_WIDTH] = 48.0;
    SetHmiElementProperty(DEMO_LKA_STEERING_PROMPT, m_buttonPos[DEMO_LKA_LANE_BKG][BUTTON_POS_X] + m_buttonSize[DEMO_LKA_LANE_BKG][BUTTON_SIZE_WIDTH] + iconHInterval, m_buttonPos[DEMO_LKA_STATUS_BAR_BKG][BUTTON_POS_Y] + (m_buttonSize[DEMO_LKA_STATUS_BAR_BKG][BUTTON_SIZE_HEIGHT] - m_buttonSize[DEMO_LKA_STEERING_PROMPT][BUTTON_SIZE_HEIGHT]) * 0.5, 48.0, 45.0);

    m_buttonSize[DEMO_LKA_WARNING][BUTTON_SIZE_HEIGHT] = 45.0;
    m_buttonSize[DEMO_LKA_WARNING][BUTTON_SIZE_WIDTH] = 48.0;
    SetHmiElementProperty(DEMO_LKA_WARNING, m_buttonPos[DEMO_LKA_STEERING_PROMPT][BUTTON_POS_X] + m_buttonSize[DEMO_LKA_STEERING_PROMPT][BUTTON_SIZE_WIDTH] + iconHInterval * 2, m_buttonPos[DEMO_LKA_STATUS_BAR_BKG][BUTTON_POS_Y] + (m_buttonSize[DEMO_LKA_STATUS_BAR_BKG][BUTTON_SIZE_HEIGHT] - m_buttonSize[DEMO_LKA_WARNING][BUTTON_SIZE_HEIGHT]) * 0.5, 48.0, 45.0);
    SetHmiElementProperty(DEMO_LKA_LEFT_SIDE_LANE, m_buttonPos[DEMO_LKA_LANE_BKG][BUTTON_POS_X], m_buttonPos[DEMO_LKA_LANE_BKG][BUTTON_POS_Y], 287.0, 132.0);
    SetHmiElementProperty(DEMO_LKA_RIGHT_SIDE_LANE, m_buttonPos[DEMO_LKA_LANE_BKG][BUTTON_POS_X], m_buttonPos[DEMO_LKA_LANE_BKG][BUTTON_POS_Y], 287.0, 132.0);
    SetHmiElementProperty(DEMO_LKA_CAR, m_buttonPos[DEMO_LKA_LANE_BKG][BUTTON_POS_X], m_buttonPos[DEMO_LKA_LANE_BKG][BUTTON_POS_Y], 287.0, 132.0);

    m_buttonSize[DEMO_LKA_ERROR_WARNING_TXT][BUTTON_SIZE_WIDTH] = 307.0;
    m_buttonSize[DEMO_LKA_ERROR_WARNING_TXT][BUTTON_SIZE_HEIGHT] = 40.0;
    SetHmiElementProperty(DEMO_LKA_ERROR_WARNING_TXT, m_buttonPos[DEMO_LKA_ERROR_WARNING_BKG][BUTTON_POS_X] + (m_buttonSize[DEMO_LKA_ERROR_WARNING_BKG][BUTTON_SIZE_WIDTH] - m_buttonSize[DEMO_LKA_ERROR_WARNING_TXT][BUTTON_SIZE_WIDTH]) * 0.5, m_buttonPos[DEMO_LKA_ERROR_WARNING_BKG][BUTTON_POS_Y] + (m_buttonSize[DEMO_LKA_ERROR_WARNING_BKG][BUTTON_SIZE_HEIGHT] - m_buttonSize[DEMO_LKA_ERROR_WARNING_TXT][BUTTON_SIZE_HEIGHT]) * 0.5, 307.0, 40.0);



    SetHmiParams();
    
    return DEMO_LKA_HMI_NORMAL;
}
int CSVDemoLkaHmi::Update(Hmi_Message_T& hmiMsg)
{
    LkaLcResultT lkaLcResult;   
    memset(&lkaLcResult, 0, sizeof(LkaLcResultT));
    CAvmRenderDataBase::GetInstance()->GetLkaLcResult(&lkaLcResult);

    MainMenuDataT mainMenuData;
    memset(&mainMenuData, 0, sizeof(MainMenuDataT));
    CAvmRenderDataBase::GetInstance()->GetMainMenuStatus(&mainMenuData);
    if(mainMenuData.iconStatus[MAIN_MENU_LKA] == 1)
    {
        lkaLcResult.funcMode = LKA_MODE;
    }
    else if(mainMenuData.iconStatus[MAIN_MENU_LC] == 1)
    {
        lkaLcResult.funcMode = LC_MODE;
    }
    if(mainMenuData.iconStatus[MAIN_MENU_LC] == 1
        && mainMenuData.iconStatus[MAIN_MENU_LKA] == 1)
    {
        lkaLcResult.funcMode = LKA_LC_MODE;
    }
    if(mainMenuData.iconStatus[MAIN_MENU_LC] != 1
        && mainMenuData.iconStatus[MAIN_MENU_LKA] != 1)
    {
        lkaLcResult.funcMode = LDW_MODE;
    }

    memset(m_buttonVisibility, 0, DEMO_LKA_ICON_NUMS * sizeof(unsigned char));

    if(lkaLcResult.funcMode == LKA_MODE)
    {
        ProcessLka(lkaLcResult);
    }
    else if(lkaLcResult.funcMode == LC_MODE)
    {
        ProcessLc(lkaLcResult);
    }
    else if(lkaLcResult.funcMode == LKA_LC_MODE)
    {
        ProcessLka(lkaLcResult);
        ProcessLc(lkaLcResult);

        //m_buttonVisibility[DEMO_LKA_CAR] = 1;
       // m_buttonVisibility[DEMO_LKA_LANE_BKG] = 1;
    }

    if(lkaLcResult.errorFlag == 1)
    {
        m_buttonVisibility[DEMO_LKA_ERROR_WARNING_BKG] = 1;     
        m_buttonVisibility[DEMO_LKA_ERROR_WARNING_TXT] = 1;
    }
    else
    {
        m_buttonVisibility[DEMO_LKA_ERROR_WARNING_BKG] = 0;     
        m_buttonVisibility[DEMO_LKA_ERROR_WARNING_TXT] = 0; 
    }

    float speed = 0.0;
    AVMData::GetInstance()->m_p_can_data->Get_Vehicle_Speed(&speed);

    ToSpeedText(speed);

	m_speedTxtVisibility = m_buttonVisibility[DEMO_LKA_STATUS_BAR_BKG];
	m_buttonVisibility[DEMO_LKA_SPEED_PROMPT] = m_speedTxtVisibility;
    
    RefreshHmi();

    return DEMO_LKA_HMI_NORMAL;
}
int CSVDemoLkaHmi::RefreshHmi()
{   
    for(int i = DEMO_LKA_STATUS_BAR_BKG; i < DEMO_LKA_ICON_NUMS; i++)
    {
        m_baseButton[i]->SetVisibility(m_buttonVisibility[i]);
        m_baseButton[i]->SetShowIconNum(m_buttonImage[i]);
        m_baseButton[i]->Update();
    }
    m_speedTxt->SetVisibility(m_speedTxtVisibility);
    m_speedTxt->Update(m_speedTxtData.textContent[0]);

    return DEMO_LKA_HMI_NORMAL;
}

int CSVDemoLkaHmi::SetElementsVisibility(unsigned char pFlag)
{
    for(int i = DEMO_LKA_STATUS_BAR_BKG; i < DEMO_LKA_ICON_NUMS; i++)
    {
        
        if(pFlag == 0)
        {
        	m_buttonVisibility[i] = pFlag;
            m_baseButton[i]->SetVisibility(m_buttonVisibility[i]);          
        }
        else
        {
            if(i != DEMO_LKA_LEFT_SIDE_LANE
                && i != DEMO_LKA_RIGHT_SIDE_LANE
                && i != DEMO_LKA_WARNING
                && i != DEMO_LKA_STEERING_PROMPT
                && i != DEMO_LKA_DIRECTION_PROMPT
                && i != DEMO_LKA_ERROR_WARNING_BKG
                && i != DEMO_LKA_ERROR_WARNING_TXT
                && i != DEMO_LKA_CAR
                && i != DEMO_LKA_LANE_BKG
                && i != DEMO_LKA_STATUS_BAR_BKG
                && i != DEMO_LKA_SPEED_PROMPT)
            {
            	m_buttonVisibility[i] = pFlag;
                m_baseButton[i]->SetVisibility(m_buttonVisibility[i]);  
            }
        }
    }

    m_speedTxtVisibility = m_buttonVisibility[DEMO_LKA_STATUS_BAR_BKG];
    m_speedTxt->SetVisibility(m_buttonVisibility[DEMO_LKA_STATUS_BAR_BKG]);

    return DEMO_LKA_HMI_NORMAL;
}

int CSVDemoLkaHmi::ReturnHmiMsg(Hmi_Message_T* hmi_msg)
{
    return DEMO_LKA_HMI_NORMAL;
}
int CSVDemoLkaHmi::DestroyHmiElems()
{
    return DEMO_LKA_HMI_NORMAL;
}

void CSVDemoLkaHmi::SetHmiElementProperty(unsigned char pIconIndex, float pIconPosX, float pIconPosY, float pIconWidth, float pIconHeight)
{
    m_buttonSize[pIconIndex][BUTTON_SIZE_WIDTH] = pIconWidth;
    m_buttonSize[pIconIndex][BUTTON_SIZE_HEIGHT] = pIconHeight;
    m_buttonPos[pIconIndex][BUTTON_POS_X] = pIconPosX;
    m_buttonPos[pIconIndex][BUTTON_POS_Y] = pIconPosY;
}

int CSVDemoLkaHmi::ProcessLka(LkaLcResultT pLkaLcResult)
{       
    if(pLkaLcResult.ltConfi != LKA_CTRL_UNRELIABLE)
    {
        m_buttonImage[DEMO_LKA_LEFT_SIDE_LANE] = pLkaLcResult.ltConfi - 1;
    }
    if(pLkaLcResult.rtConfi != LKA_CTRL_UNRELIABLE)
    {
        m_buttonImage[DEMO_LKA_RIGHT_SIDE_LANE] = pLkaLcResult.rtConfi - 1;
    }
    
    if(pLkaLcResult.lkaFlag == 1)
    {
        if(pLkaLcResult.lkaAlgoMode == LKA_ALGO_CTRL_LKA_STAGE1_LEFT
        ||pLkaLcResult.lkaAlgoMode == LKA_ALGO_CTRL_LKA_STAGE2_LEFT)
        {
            m_buttonImage[DEMO_LKA_LEFT_SIDE_LANE] = 2;
        }
        if(pLkaLcResult.lkaAlgoMode == LKA_ALGO_CTRL_LKA_STAGE1_RIGHT
            || pLkaLcResult.lkaAlgoMode == LKA_ALGO_CTRL_LKA_STAGE2_RIGHT)
        {
            m_buttonImage[DEMO_LKA_RIGHT_SIDE_LANE] = 2;
        }
    }

    if(pLkaLcResult.workFlag == 1)
    {
        m_buttonVisibility[DEMO_LKA_CAR] = 1;
        m_buttonVisibility[DEMO_LKA_LANE_BKG] = 1;
        m_buttonVisibility[DEMO_LKA_LEFT_SIDE_LANE] = 1;
        m_buttonVisibility[DEMO_LKA_RIGHT_SIDE_LANE] = 1;
		m_buttonVisibility[DEMO_LKA_STATUS_BAR_BKG] = 1;
    }


    if(pLkaLcResult.chimeFlag == 1)
    {
        m_buttonVisibility[DEMO_LKA_WARNING] = 1;
    }
    else
    {
        m_buttonVisibility[DEMO_LKA_WARNING] = 0;
    }
    return DEMO_LKA_HMI_NORMAL;
}
int CSVDemoLkaHmi::ProcessLc(LkaLcResultT pLkaLcResult)
{
    if(pLkaLcResult.workFlag == 1)
    {
        m_buttonVisibility[DEMO_LKA_CAR] = 1;
        m_buttonVisibility[DEMO_LKA_LANE_BKG] = 1;
        m_buttonVisibility[DEMO_LKA_STEERING_PROMPT] = 1;
		m_buttonVisibility[DEMO_LKA_STATUS_BAR_BKG] = 1;
		if(pLkaLcResult.lkaFlag == 0)
		{			
	        m_buttonImage[DEMO_LKA_STEERING_PROMPT] = 1;
		}
		else
		{		
        	m_buttonImage[DEMO_LKA_STEERING_PROMPT] = 0;
		}
    }
    else
    {
        m_buttonVisibility[DEMO_LKA_STEERING_PROMPT] = 0;
        m_buttonImage[DEMO_LKA_STEERING_PROMPT] = 1;
    }

    if(pLkaLcResult.lkaAlgoMode == LKA_ALGO_CTRL_LC_LEFT_LANE_CHANGE)
    {
        m_buttonImage[DEMO_LKA_DIRECTION_PROMPT] = 0;
        m_buttonVisibility[DEMO_LKA_DIRECTION_PROMPT] = 1;
    }
    else if(pLkaLcResult.lkaAlgoMode == LKA_ALGO_CTRL_LC_RIGHT_LANE_CHANGE)
    {
        m_buttonImage[DEMO_LKA_DIRECTION_PROMPT] = 1;
        m_buttonVisibility[DEMO_LKA_DIRECTION_PROMPT] = 1;
    }
    else
    {
        m_buttonVisibility[DEMO_LKA_DIRECTION_PROMPT] = 0;  
    }
    
    return DEMO_LKA_HMI_NORMAL;
}

void CSVDemoLkaHmi::ToSpeedText(float speed)
{
    if(speed >= 99.999999)
    {
        sprintf(m_speedTxtData.textContent[0], "%1.0f", speed);
    }
    else if(speed < 100.00 && speed >= 9.999999)
    {
        sprintf(m_speedTxtData.textContent[0], "%0.1f", speed);
    }
    else if(speed < 10.0 && speed >= 0.0)
    {
        sprintf(m_speedTxtData.textContent[0], "0%0.1f", speed);
    }   
}

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *   Date        userid       Description
 * ----------- ----------    -----------
 *  1/4/18   Jensen Wang   Create the CSVDemoLkaHmi class.
\*===========================================================================*/
