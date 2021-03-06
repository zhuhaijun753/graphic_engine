#include "CSVDvrRecordTab.h"
#include "DVR_GUI_OBJ.h"

#define REC_HIDE_TIME 5000;
unsigned int RecStartTime = 0;
unsigned int RecHideTimeCount = REC_HIDE_TIME;

class CRecordMenuHideActionTrigger : public IActionTrigger
{
    ACTION_TRIGGER_EVENT_CONSTRUCTION(CRecordMenuHideActionTrigger, m_eventDel, INPUT_EVENT_CTRL_CMD, Ctrl_Cmd_T, m_dvrCmd)
  public:
    virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
    {
//        RecMenuVisible = BUTTON_HIDE;
        m_dvrCmd->MsgHead.MsgType = IPC_MSG_TYPE_M4_A15_DVR_CMD;
        m_dvrCmd->MsgHead.MsgSize = sizeof(Ctrl_Cmd_T);
        m_dvrCmd->parameter[0] = DVR_USER_CLICK_SIDEBAR;
        m_dvrCmd->parameter[1] = GUI_SIDEBAR_STATUS_HIDE;
        m_eventDel->PostEventPayload((void *)m_dvrCmd, sizeof(Ctrl_Cmd_T));

        Log_Message("-----------CRecordHideActionTrigger: %d", sizeof(Ctrl_Cmd_T));
    }
    virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
    {
    }
	virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
	{
		
	}
};

class CRecordMenuShowActionTrigger : public IActionTrigger
{
	ACTION_TRIGGER_EVENT_CONSTRUCTION(CRecordMenuShowActionTrigger, m_eventDel, INPUT_EVENT_CTRL_CMD, Ctrl_Cmd_T, m_dvrCmd)
public:

	virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
	{
//	    RecMenuVisible = BUTTON_SHOW;
        m_dvrCmd->MsgHead.MsgType = IPC_MSG_TYPE_M4_A15_DVR_CMD;
        m_dvrCmd->MsgHead.MsgSize = sizeof(Ctrl_Cmd_T);
        m_dvrCmd->parameter[0] = DVR_USER_CLICK_SIDEBAR;
        m_dvrCmd->parameter[1] = GUI_SIDEBAR_STATUS_SHOW;
        m_eventDel->PostEventPayload((void *)m_dvrCmd, sizeof(Ctrl_Cmd_T));

		Log_Message("-----------CRecordHideActionTrigger: %d", sizeof(Ctrl_Cmd_T));
	}
	virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
	{

	}
	virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
	{
		
	}
};


class CRecordSwitchActionTrigger : public IActionTrigger
{
	ACTION_TRIGGER_EVENT_CONSTRUCTION(CRecordSwitchActionTrigger, m_eventDel, INPUT_EVENT_CTRL_CMD, Ctrl_Cmd_T, m_dvrCmd)
public:

	virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
	{
        RecHideTimeCount = REC_HIDE_TIME;
		m_dvrCmd->MsgHead.MsgType = IPC_MSG_TYPE_M4_A15_DVR_CMD;
		m_dvrCmd->MsgHead.MsgSize = sizeof(Ctrl_Cmd_T);
		m_dvrCmd->parameter[0] = DVR_USER_CLICK_RECORD_SWITCH;
		m_eventDel->PostEventPayload((void*)m_dvrCmd, sizeof(Ctrl_Cmd_T));
	
		Log_Message("-----------CRecordSwitchActionTrigger: %d", sizeof(Ctrl_Cmd_T));
	}
	virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
	{

	}
	virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
	{
		
	}
};

class CCaptureActionTrigger : public IActionTrigger
{
	ACTION_TRIGGER_EVENT_CONSTRUCTION(CCaptureActionTrigger, m_eventDel, INPUT_EVENT_CTRL_CMD, Ctrl_Cmd_T, m_dvrCmd)
public:

	virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
	{
        RecHideTimeCount = REC_HIDE_TIME;
	}
	virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
	{
        RecHideTimeCount = REC_HIDE_TIME;
		m_dvrCmd->MsgHead.MsgType = IPC_MSG_TYPE_M4_A15_DVR_CMD;
		m_dvrCmd->MsgHead.MsgSize = sizeof(Ctrl_Cmd_T);
		m_dvrCmd->parameter[0] = DVR_USER_CLICK_PHOTO_SHUTTER;
		m_eventDel->PostEventPayload((void*)m_dvrCmd, sizeof(Ctrl_Cmd_T));

		Log_Message("-----------CCaptureActionTrigger: %d", sizeof(Ctrl_Cmd_T));

	}
	virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
	{
		
	}
};

class CEventRecordActionTrigger : public IActionTrigger
{
	ACTION_TRIGGER_EVENT_CONSTRUCTION(CEventRecordActionTrigger, m_eventDel, INPUT_EVENT_CTRL_CMD, Ctrl_Cmd_T, m_dvrCmd)
public:

	virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
	{
        RecHideTimeCount = REC_HIDE_TIME;
		m_dvrCmd->MsgHead.MsgType = IPC_MSG_TYPE_M4_A15_DVR_CMD;
		m_dvrCmd->MsgHead.MsgSize = sizeof(Ctrl_Cmd_T);
		m_dvrCmd->parameter[0] = DVR_USER_CLICK_EVENT_RECORD;
		m_eventDel->PostEventPayload((void*)m_dvrCmd, sizeof(Ctrl_Cmd_T));
	
		Log_Message("-----------CEventRecordActionTrigger: %d", sizeof(Ctrl_Cmd_T));
	}
	virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
	{

	}
	virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
	{
		
	}
};

class CRecordFrontViewActionTrigger : public IActionTrigger
{
	ACTION_TRIGGER_EVENT_CONSTRUCTION(CRecordFrontViewActionTrigger, m_eventDel, INPUT_EVENT_CTRL_CMD, Ctrl_Cmd_T, m_dvrCmd)
public:

	virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
	{
        RecHideTimeCount = REC_HIDE_TIME;
		m_dvrCmd->MsgHead.MsgType = IPC_MSG_TYPE_M4_A15_DVR_CMD;
		m_dvrCmd->MsgHead.MsgSize = sizeof(Ctrl_Cmd_T);
		m_dvrCmd->parameter[0] = DVR_USER_CLICK_LIVE_VIEW;
		m_dvrCmd->parameter[1] = GUI_VIEW_INDEX_FRONT;
		m_eventDel->PostEventPayload((void*)m_dvrCmd, sizeof(Ctrl_Cmd_T));
	
		Log_Message("-----------CRecordFrontViewActionTrigger: %d", sizeof(Ctrl_Cmd_T));
	}
	virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
	{

	}
	virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
	{
		
	}
};

class CRecordRearViewActionTrigger : public IActionTrigger
{
	ACTION_TRIGGER_EVENT_CONSTRUCTION(CRecordRearViewActionTrigger, m_eventDel, INPUT_EVENT_CTRL_CMD, Ctrl_Cmd_T, m_dvrCmd)
public:

	virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
	{
        RecHideTimeCount = REC_HIDE_TIME;
		m_dvrCmd->MsgHead.MsgType = IPC_MSG_TYPE_M4_A15_DVR_CMD;
		m_dvrCmd->MsgHead.MsgSize = sizeof(Ctrl_Cmd_T);
		m_dvrCmd->parameter[0] = DVR_USER_CLICK_LIVE_VIEW;
		m_dvrCmd->parameter[1] = GUI_VIEW_INDEX_REAR;
		m_eventDel->PostEventPayload((void*)m_dvrCmd, sizeof(Ctrl_Cmd_T));
	
		Log_Message("-----------CRecordRearViewActionTrigger: %d", sizeof(Ctrl_Cmd_T));
	}
	virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
	{

	}
	virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
	{
		
	}
};

class CRecordLeftViewActionTrigger : public IActionTrigger
{
	ACTION_TRIGGER_EVENT_CONSTRUCTION(CRecordLeftViewActionTrigger, m_eventDel, INPUT_EVENT_CTRL_CMD, Ctrl_Cmd_T, m_dvrCmd)
public:

	virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
	{
        RecHideTimeCount = REC_HIDE_TIME;
		m_dvrCmd->MsgHead.MsgType = IPC_MSG_TYPE_M4_A15_DVR_CMD;
		m_dvrCmd->MsgHead.MsgSize = sizeof(Ctrl_Cmd_T);
		m_dvrCmd->parameter[0] = DVR_USER_CLICK_LIVE_VIEW;
		m_dvrCmd->parameter[1] = GUI_VIEW_INDEX_LEFT;
		m_eventDel->PostEventPayload((void*)m_dvrCmd, sizeof(Ctrl_Cmd_T));
	
		Log_Message("-----------CRecordLeftViewActionTrigger: %d", sizeof(Ctrl_Cmd_T));
	}
	virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
	{

	}
	virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
	{
		
	}
};

class CRecordRightViewActionTrigger : public IActionTrigger
{
	ACTION_TRIGGER_EVENT_CONSTRUCTION(CRecordRightViewActionTrigger, m_eventDel, INPUT_EVENT_CTRL_CMD, Ctrl_Cmd_T, m_dvrCmd)
public:

	virtual Void OnPress(Int32 id, Int32 x = 0, Int32 y = 0)
	{
        RecHideTimeCount = REC_HIDE_TIME;
		m_dvrCmd->MsgHead.MsgType = IPC_MSG_TYPE_M4_A15_DVR_CMD;
		m_dvrCmd->MsgHead.MsgSize = sizeof(Ctrl_Cmd_T);
		m_dvrCmd->parameter[0] = DVR_USER_CLICK_LIVE_VIEW;
		m_dvrCmd->parameter[1] = GUI_VIEW_INDEX_RIGHT;
		m_eventDel->PostEventPayload((void*)m_dvrCmd, sizeof(Ctrl_Cmd_T));
	
		Log_Message("-----------CRecordRightViewActionTrigger: %d", sizeof(Ctrl_Cmd_T));
	}
	virtual Void OnRelease(Int32 id, Boolean isIn, Int32 x = 0, Int32 y = 0)
	{

	}
	virtual Void OnMove(Int32 id, Int32 x = 0, Int32 y = 0)
	{
		
	}
};


CSVDvrRecordTab::CSVDvrRecordTab(IUINode* pUiNode , int pUiNodeId ): ISVHmi::ISVHmi(pUiNode, pUiNodeId)
{
	memset(m_trigger, 0, DVR_RECORD_TAB_ELEMEMT_NUM * sizeof(IActionTrigger*));
	memset(m_buttonStatus, 0, DVR_RECORD_TAB_ELEMEMT_NUM * sizeof(unsigned char));
	memset(m_buttonVisibility, 0, DVR_RECORD_TAB_ELEMEMT_NUM * sizeof(unsigned char));
    m_menuVisibility = GUI_SIDEBAR_STATUS_SHOW;
    RecStartTime = 0;
    RecHideTimeCount = REC_HIDE_TIME;	
}

CSVDvrRecordTab::~CSVDvrRecordTab()
{
    for(int i=0;i<DVR_RECORD_TAB_ELEMEMT_NUM;i++)
    {
        //SAFE_DELETE(m_baseButton[i]);
		SAFE_DELETE(m_baseButtonData[i].icon_file_name[0]);

		if(i == DVR_RECORD_TAB_RED_DOT
            || i == DVR_RECORD_TAB_HIDE_ICON
            || i == DVR_RECORD_TAB_SHOW_ICON
            || i == DVR_RECORD_TAB_RECORD_SWITCH
			|| i == DVR_RECORD_TAB_CAPTURE_ICON
			|| i == DVR_RECORD_TAB_EMERGENCY_ICON
			|| i == DVR_RECORD_TAB_VIEW_FRONT
			|| i == DVR_RECORD_TAB_VIEW_REAR
			|| i == DVR_RECORD_TAB_VIEW_LEFT
			|| i == DVR_RECORD_TAB_VIEW_RIGHT)
		{		
			SAFE_DELETE(m_baseButtonData[i].icon_file_name[1]);
		}
		
		SAFE_DELETE(m_trigger[i]);
    }
	//Log_Error("----------Release ~CSVDvrRecordTab!");
}

int CSVDvrRecordTab::SetHmiParams()
{
    m_baseButtonData[DVR_RECORD_TAB_RED_DOT].icon_type = DYNAMIC_ICON;
    m_baseButtonData[DVR_RECORD_TAB_RED_DOT].show_flag = 1;
    m_baseButtonData[DVR_RECORD_TAB_RED_DOT].show_icon_num = 0;
    m_baseButtonData[DVR_RECORD_TAB_RED_DOT].icon_file_name[0] = new char[50];
    m_baseButtonData[DVR_RECORD_TAB_RED_DOT].icon_file_name[1] = new char[50];
    sprintf(m_baseButtonData[DVR_RECORD_TAB_RED_DOT].icon_file_name[0], "%sCar/DVR/record_red_dot_normal.dds", XR_RES);
    sprintf(m_baseButtonData[DVR_RECORD_TAB_RED_DOT].icon_file_name[1], "%sCar/DVR/record_red_dot_emergency.dds", XR_RES);
    m_baseButtonData[DVR_RECORD_TAB_RED_DOT].animationStyle = BUTTON_NOMAL;

    m_baseButtonData[DVR_RECORD_TAB_RECORD_BKG].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_RECORD_BKG].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_RECORD_BKG].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_RECORD_BKG].icon_file_name[0] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_RECORD_BKG].icon_file_name[0],"%sCar/DVR/record_tab_bkg.dds",XR_RES); 

	m_baseButtonData[DVR_RECORD_TAB_HIDE_ICON].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_HIDE_ICON].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_HIDE_ICON].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_HIDE_ICON].icon_file_name[0] = new char[50];
	m_baseButtonData[DVR_RECORD_TAB_HIDE_ICON].icon_file_name[1] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_HIDE_ICON].icon_file_name[0],"%sCar/DVR/menu_hide_normal.dds",XR_RES); 
	sprintf(m_baseButtonData[DVR_RECORD_TAB_HIDE_ICON].icon_file_name[1],"%sCar/DVR/menu_hide_hightlight.dds",XR_RES); 
    m_baseButtonData[DVR_RECORD_TAB_HIDE_ICON].animationStyle = BUTTON_FLASH_HIGHLIGHT;
    m_trigger[DVR_RECORD_TAB_HIDE_ICON] = new CRecordMenuHideActionTrigger;


    m_baseButtonData[DVR_RECORD_TAB_SHOW_ICON].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_SHOW_ICON].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_SHOW_ICON].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_SHOW_ICON].icon_file_name[0] = new char[50];
	m_baseButtonData[DVR_RECORD_TAB_SHOW_ICON].icon_file_name[1] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_SHOW_ICON].icon_file_name[0],"%sCar/DVR/menu_show_normal.dds",XR_RES); 
	sprintf(m_baseButtonData[DVR_RECORD_TAB_SHOW_ICON].icon_file_name[1],"%sCar/DVR/menu_show_hightlight.dds",XR_RES); 
    m_baseButtonData[DVR_RECORD_TAB_SHOW_ICON].animationStyle = BUTTON_FLASH_HIGHLIGHT;
    m_trigger[DVR_RECORD_TAB_SHOW_ICON] = new CRecordMenuShowActionTrigger;
    
	m_baseButtonData[DVR_RECORD_TAB_RECORD_TITLE].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_RECORD_TITLE].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_RECORD_TITLE].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_RECORD_TITLE].icon_file_name[0] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_RECORD_TITLE].icon_file_name[0],"%sCar/DVR/record_title.dds",XR_RES); 
		
	m_baseButtonData[DVR_RECORD_TAB_RECORD_SWITCH].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_RECORD_SWITCH].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_RECORD_SWITCH].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_RECORD_SWITCH].icon_file_name[0] = new char[50];
	m_baseButtonData[DVR_RECORD_TAB_RECORD_SWITCH].icon_file_name[1] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_RECORD_SWITCH].icon_file_name[0],"%sCar/DVR/record_switch_normal.dds",XR_RES); 
	sprintf(m_baseButtonData[DVR_RECORD_TAB_RECORD_SWITCH].icon_file_name[1],"%sCar/DVR/record_switch_press.dds",XR_RES); 
	m_trigger[DVR_RECORD_TAB_RECORD_SWITCH] = new CRecordSwitchActionTrigger;

	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_TITLE].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_TITLE].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_TITLE].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_TITLE].icon_file_name[0] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_CAPTURE_TITLE].icon_file_name[0],"%sCar/DVR/capture_title.dds",XR_RES); 

	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_BKG].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_BKG].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_BKG].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_BKG].icon_file_name[0] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_CAPTURE_BKG].icon_file_name[0],"%sCar/DVR/capture_bkg.dds",XR_RES); 

	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_ICON].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_ICON].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_ICON].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_ICON].icon_file_name[0] = new char[50];
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_ICON].icon_file_name[1] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_CAPTURE_ICON].icon_file_name[0],"%sCar/DVR/capture_normal.dds",XR_RES); 
	sprintf(m_baseButtonData[DVR_RECORD_TAB_CAPTURE_ICON].icon_file_name[1],"%sCar/DVR/capture_hightlight.dds",XR_RES); 
	m_baseButtonData[DVR_RECORD_TAB_CAPTURE_ICON].animationStyle = BUTTON_FLASH_HIGHLIGHT;
	m_trigger[DVR_RECORD_TAB_CAPTURE_ICON] = new CCaptureActionTrigger;

	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_TITLE].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_TITLE].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_TITLE].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_TITLE].icon_file_name[0] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_TITLE].icon_file_name[0],"%sCar/DVR/emergency_title.dds",XR_RES); 

	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_BKG].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_BKG].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_BKG].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_BKG].icon_file_name[0] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_BKG].icon_file_name[0],"%sCar/DVR/emergency_bkg.dds",XR_RES); 

	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_ICON].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_ICON].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_ICON].show_icon_num = 1;
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_ICON].icon_file_name[0] = new char[50];
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_ICON].icon_file_name[1] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_ICON].icon_file_name[0],"%sCar/DVR/emergency_normal.dds",XR_RES); 
	sprintf(m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_ICON].icon_file_name[1],"%sCar/DVR/emergency_highlight.dds",XR_RES); 
	m_baseButtonData[DVR_RECORD_TAB_EMERGENCY_ICON].animationStyle = BUTTON_NOMAL;
	m_trigger[DVR_RECORD_TAB_EMERGENCY_ICON] = new CEventRecordActionTrigger;

	m_baseButtonData[DVR_RECORD_TAB_VIEW_TITLE].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_TITLE].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_TITLE].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_TITLE].icon_file_name[0] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_TITLE].icon_file_name[0],"%sCar/DVR/record_view_title.dds",XR_RES); 

	m_baseButtonData[DVR_RECORD_TAB_VIEW_BKG].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_BKG].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_BKG].show_icon_num = 0;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_BKG].icon_file_name[0] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_BKG].icon_file_name[0],"%sCar/DVR/record_view_bkg.dds",XR_RES); 

	m_baseButtonData[DVR_RECORD_TAB_VIEW_FRONT].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_FRONT].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_FRONT].show_icon_num = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_FRONT].icon_file_name[0] = new char[50];
	m_baseButtonData[DVR_RECORD_TAB_VIEW_FRONT].icon_file_name[1] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_FRONT].icon_file_name[0],"%sCar/DVR/record_view_front_normal.dds",XR_RES); 
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_FRONT].icon_file_name[1],"%sCar/DVR/record_view_front_highlight.dds",XR_RES); 
	m_trigger[DVR_RECORD_TAB_VIEW_FRONT] = new CRecordFrontViewActionTrigger;

	m_baseButtonData[DVR_RECORD_TAB_VIEW_REAR].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_REAR].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_REAR].show_icon_num = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_REAR].icon_file_name[0] = new char[50];
	m_baseButtonData[DVR_RECORD_TAB_VIEW_REAR].icon_file_name[1] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_REAR].icon_file_name[0],"%sCar/DVR/record_view_rear_normal.dds",XR_RES); 
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_REAR].icon_file_name[1],"%sCar/DVR/record_view_rear_highlight.dds",XR_RES); 
	m_trigger[DVR_RECORD_TAB_VIEW_REAR] = new CRecordRearViewActionTrigger;

	m_baseButtonData[DVR_RECORD_TAB_VIEW_LEFT].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_LEFT].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_LEFT].show_icon_num = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_LEFT].icon_file_name[0] = new char[50];
	m_baseButtonData[DVR_RECORD_TAB_VIEW_LEFT].icon_file_name[1] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_LEFT].icon_file_name[0],"%sCar/DVR/record_view_left_normal.dds",XR_RES); 
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_LEFT].icon_file_name[1],"%sCar/DVR/record_view_left_highlight.dds",XR_RES); 
	m_trigger[DVR_RECORD_TAB_VIEW_LEFT] = new CRecordLeftViewActionTrigger;

	m_baseButtonData[DVR_RECORD_TAB_VIEW_RIGHT].icon_type = STATIC_ICON;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_RIGHT].show_flag = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_RIGHT].show_icon_num = 1;
	m_baseButtonData[DVR_RECORD_TAB_VIEW_RIGHT].icon_file_name[0] = new char[50];
	m_baseButtonData[DVR_RECORD_TAB_VIEW_RIGHT].icon_file_name[1] = new char[50];
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_RIGHT].icon_file_name[0],"%sCar/DVR/record_view_right_normal.dds",XR_RES); 
	sprintf(m_baseButtonData[DVR_RECORD_TAB_VIEW_RIGHT].icon_file_name[1],"%sCar/DVR/record_view_right_highlight.dds",XR_RES); 
	m_trigger[DVR_RECORD_TAB_VIEW_RIGHT] = new CRecordRightViewActionTrigger;

	for(int i = DVR_RECORD_TAB_RED_DOT; i < DVR_RECORD_TAB_ELEMEMT_NUM; i++)
	{
		m_baseButtonData[i].pos[0] = m_buttonPos[i][BUTTON_POS_X];
		m_baseButtonData[i].pos[1] = m_buttonPos[i][BUTTON_POS_Y];
		m_baseButtonData[i].width = m_buttonSize[i][BUTTON_SIZE_WIDTH];
		m_baseButtonData[i].height = m_buttonSize[i][BUTTON_SIZE_HEIGHT];
		m_baseButtonData[i].delegate_func = NULL;
		m_baseButtonData[i].trigger = m_trigger[i];

		m_baseButton[i] = new HMIButton(&(m_baseButtonData[i]),m_uiNode);
		m_baseButton[i]->SetVisibility(0);
	}

	return HMI_SUCCESS;
}
int CSVDvrRecordTab::Init(int window_width, int window_height)
{
	float radio = 227.0/1280.0;

	m_buttonSize[DVR_RECORD_TAB_RED_DOT][BUTTON_SIZE_WIDTH] = 140.0;
	m_buttonSize[DVR_RECORD_TAB_RED_DOT][BUTTON_SIZE_HEIGHT] = 26.0;
	m_buttonPos[DVR_RECORD_TAB_RED_DOT][BUTTON_POS_X] = window_width - m_buttonSize[DVR_RECORD_TAB_RED_DOT][BUTTON_SIZE_WIDTH] - 20.0;
	m_buttonPos[DVR_RECORD_TAB_RED_DOT][BUTTON_POS_Y] = 100.0;

	m_buttonSize[DVR_RECORD_TAB_RECORD_BKG][BUTTON_SIZE_WIDTH] = 372.0;
	m_buttonSize[DVR_RECORD_TAB_RECORD_BKG][BUTTON_SIZE_HEIGHT] = 560.0;
	m_buttonPos[DVR_RECORD_TAB_RECORD_BKG][BUTTON_POS_X] = radio*window_width;
	m_buttonPos[DVR_RECORD_TAB_RECORD_BKG][BUTTON_POS_Y] = 80.0;
    
	m_buttonSize[DVR_RECORD_TAB_HIDE_ICON][BUTTON_SIZE_WIDTH] = 42.0;
	m_buttonSize[DVR_RECORD_TAB_HIDE_ICON][BUTTON_SIZE_HEIGHT] = 45.0;
	m_buttonPos[DVR_RECORD_TAB_HIDE_ICON][BUTTON_POS_X] = radio*window_width;
	m_buttonPos[DVR_RECORD_TAB_HIDE_ICON][BUTTON_POS_Y] = 0.5*window_height - 23;

    m_buttonSize[DVR_RECORD_TAB_SHOW_ICON][BUTTON_SIZE_WIDTH] = 42.0;
	m_buttonSize[DVR_RECORD_TAB_SHOW_ICON][BUTTON_SIZE_HEIGHT] = 45.0;
	m_buttonPos[DVR_RECORD_TAB_SHOW_ICON][BUTTON_POS_X] = radio*window_width;
	m_buttonPos[DVR_RECORD_TAB_SHOW_ICON][BUTTON_POS_Y] = 0.5*window_height - 23;
    
	m_buttonSize[DVR_RECORD_TAB_RECORD_TITLE][BUTTON_SIZE_WIDTH] = 58.0;
	m_buttonSize[DVR_RECORD_TAB_RECORD_TITLE][BUTTON_SIZE_HEIGHT] = 29.0;
	m_buttonPos[DVR_RECORD_TAB_RECORD_TITLE][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_RECORD_BKG][BUTTON_POS_X] + 50.0;
	m_buttonPos[DVR_RECORD_TAB_RECORD_TITLE][BUTTON_POS_Y] = 80.0 + 80.0;
		
	m_buttonSize[DVR_RECORD_TAB_RECORD_SWITCH][BUTTON_SIZE_WIDTH] = 114.0;
	m_buttonSize[DVR_RECORD_TAB_RECORD_SWITCH][BUTTON_SIZE_HEIGHT] = 47.0;
	m_buttonPos[DVR_RECORD_TAB_RECORD_SWITCH][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_RECORD_TITLE][BUTTON_POS_X] + m_buttonSize[DVR_RECORD_TAB_RECORD_TITLE][BUTTON_SIZE_WIDTH] + 100.0;
	m_buttonPos[DVR_RECORD_TAB_RECORD_SWITCH][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_RECORD_TITLE][BUTTON_POS_Y];

	m_buttonSize[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_SIZE_WIDTH] = 58.0;
	m_buttonSize[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_SIZE_HEIGHT] = 29.0;
	m_buttonPos[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_RECORD_TITLE][BUTTON_POS_X];
	m_buttonPos[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_RECORD_TITLE][BUTTON_POS_Y]+ m_buttonSize[DVR_RECORD_TAB_RECORD_SWITCH][BUTTON_SIZE_HEIGHT] + 60.0;

	m_buttonSize[DVR_RECORD_TAB_CAPTURE_BKG][BUTTON_SIZE_WIDTH] = 122.0;
	m_buttonSize[DVR_RECORD_TAB_CAPTURE_BKG][BUTTON_SIZE_HEIGHT] = 58.0;
	m_buttonPos[DVR_RECORD_TAB_CAPTURE_BKG][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_POS_X] + m_buttonSize[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_SIZE_WIDTH] + 100.0;
	m_buttonPos[DVR_RECORD_TAB_CAPTURE_BKG][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_POS_Y];
		
	m_buttonSize[DVR_RECORD_TAB_CAPTURE_ICON][BUTTON_SIZE_WIDTH] = 122.0;
	m_buttonSize[DVR_RECORD_TAB_CAPTURE_ICON][BUTTON_SIZE_HEIGHT] = 58.0;
	m_buttonPos[DVR_RECORD_TAB_CAPTURE_ICON][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_CAPTURE_BKG][BUTTON_POS_X];
	m_buttonPos[DVR_RECORD_TAB_CAPTURE_ICON][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_CAPTURE_BKG][BUTTON_POS_Y];
		
	m_buttonSize[DVR_RECORD_TAB_EMERGENCY_TITLE][BUTTON_SIZE_WIDTH] = 114.0;
	m_buttonSize[DVR_RECORD_TAB_EMERGENCY_TITLE][BUTTON_SIZE_HEIGHT] = 30.0;
	m_buttonPos[DVR_RECORD_TAB_EMERGENCY_TITLE][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_POS_X];
	m_buttonPos[DVR_RECORD_TAB_EMERGENCY_TITLE][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_POS_Y] + m_buttonSize[DVR_RECORD_TAB_CAPTURE_TITLE][BUTTON_SIZE_HEIGHT] + 60.0;

	m_buttonSize[DVR_RECORD_TAB_EMERGENCY_BKG][BUTTON_SIZE_WIDTH] = 122.0;
	m_buttonSize[DVR_RECORD_TAB_EMERGENCY_BKG][BUTTON_SIZE_HEIGHT] = 58.0;
	m_buttonPos[DVR_RECORD_TAB_EMERGENCY_BKG][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_EMERGENCY_TITLE][BUTTON_POS_X] + m_buttonSize[DVR_RECORD_TAB_EMERGENCY_BKG][BUTTON_SIZE_WIDTH] + 35;
	m_buttonPos[DVR_RECORD_TAB_EMERGENCY_BKG][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_EMERGENCY_TITLE][BUTTON_POS_Y];

	m_buttonSize[DVR_RECORD_TAB_EMERGENCY_ICON][BUTTON_SIZE_WIDTH] = 122.0;
	m_buttonSize[DVR_RECORD_TAB_EMERGENCY_ICON][BUTTON_SIZE_HEIGHT] = 58.0;
	m_buttonPos[DVR_RECORD_TAB_EMERGENCY_ICON][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_EMERGENCY_BKG][BUTTON_POS_X];
	m_buttonPos[DVR_RECORD_TAB_EMERGENCY_ICON][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_EMERGENCY_BKG][BUTTON_POS_Y];

	m_buttonSize[DVR_RECORD_TAB_VIEW_TITLE][BUTTON_SIZE_WIDTH] = 58.0;
	m_buttonSize[DVR_RECORD_TAB_VIEW_TITLE][BUTTON_SIZE_HEIGHT] = 29.0;
	m_buttonPos[DVR_RECORD_TAB_VIEW_TITLE][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_EMERGENCY_TITLE][BUTTON_POS_X];
	m_buttonPos[DVR_RECORD_TAB_VIEW_TITLE][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_EMERGENCY_TITLE][BUTTON_POS_Y] + m_buttonSize[DVR_RECORD_TAB_EMERGENCY_TITLE][BUTTON_SIZE_HEIGHT] + 60.0;

	m_buttonSize[DVR_RECORD_TAB_VIEW_BKG][BUTTON_SIZE_WIDTH] = 296.0;
	m_buttonSize[DVR_RECORD_TAB_VIEW_BKG][BUTTON_SIZE_HEIGHT] = 58.0;
	m_buttonPos[DVR_RECORD_TAB_VIEW_BKG][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_VIEW_TITLE][BUTTON_POS_X];
	m_buttonPos[DVR_RECORD_TAB_VIEW_BKG][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_VIEW_TITLE][BUTTON_POS_Y] + m_buttonSize[DVR_RECORD_TAB_VIEW_TITLE][BUTTON_SIZE_HEIGHT] + 10.0;

	m_buttonSize[DVR_RECORD_TAB_VIEW_FRONT][BUTTON_SIZE_WIDTH] = 75.0;
	m_buttonSize[DVR_RECORD_TAB_VIEW_FRONT][BUTTON_SIZE_HEIGHT] = 57.0;
	m_buttonPos[DVR_RECORD_TAB_VIEW_FRONT][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_VIEW_BKG][BUTTON_POS_X];
	m_buttonPos[DVR_RECORD_TAB_VIEW_FRONT][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_VIEW_BKG][BUTTON_POS_Y];

	m_buttonSize[DVR_RECORD_TAB_VIEW_REAR][BUTTON_SIZE_WIDTH] = 75.0;
	m_buttonSize[DVR_RECORD_TAB_VIEW_REAR][BUTTON_SIZE_HEIGHT] = 57.0;
	m_buttonPos[DVR_RECORD_TAB_VIEW_REAR][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_VIEW_FRONT][BUTTON_POS_X] + m_buttonSize[DVR_RECORD_TAB_VIEW_FRONT][BUTTON_SIZE_WIDTH];
	m_buttonPos[DVR_RECORD_TAB_VIEW_REAR][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_VIEW_FRONT][BUTTON_POS_Y];

	m_buttonSize[DVR_RECORD_TAB_VIEW_LEFT][BUTTON_SIZE_WIDTH] = 75.0;
	m_buttonSize[DVR_RECORD_TAB_VIEW_LEFT][BUTTON_SIZE_HEIGHT] = 57.0;
	m_buttonPos[DVR_RECORD_TAB_VIEW_LEFT][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_VIEW_REAR][BUTTON_POS_X] + m_buttonSize[DVR_RECORD_TAB_VIEW_REAR][BUTTON_SIZE_WIDTH];
	m_buttonPos[DVR_RECORD_TAB_VIEW_LEFT][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_VIEW_REAR][BUTTON_POS_Y];

	m_buttonSize[DVR_RECORD_TAB_VIEW_RIGHT][BUTTON_SIZE_WIDTH] = 75.0;
	m_buttonSize[DVR_RECORD_TAB_VIEW_RIGHT][BUTTON_SIZE_HEIGHT] = 57.0;
	m_buttonPos[DVR_RECORD_TAB_VIEW_RIGHT][BUTTON_POS_X] = m_buttonPos[DVR_RECORD_TAB_VIEW_LEFT][BUTTON_POS_X] + m_buttonSize[DVR_RECORD_TAB_VIEW_LEFT][BUTTON_SIZE_WIDTH];
	m_buttonPos[DVR_RECORD_TAB_VIEW_RIGHT][BUTTON_POS_Y] = m_buttonPos[DVR_RECORD_TAB_VIEW_LEFT][BUTTON_POS_Y];

	SetHmiParams();
	
	return HMI_SUCCESS;
}
int CSVDvrRecordTab::Update(Hmi_Message_T& hmiMsg)
{	
	DVR_GRAPHIC_UIOBJ* recordTabMsg = NULL;
	
	/*DVR_GRAPHIC_UIOBJ rec_gui_table[] =
{
	{ GUI_OBJ_ID_MAIN_MENU_TAB, "main_menu", 1, 1, GUI_OBJ_STATUS_TYPE_VALUE, GUI_MAIN_MENU_TAB_RECORD },
	{ GUI_OBJ_ID_CARD_STATE, "card_state", 1, 1, GUI_OBJ_STATUS_TYPE_VALUE, GUI_CARD_STATE_NO_CARD },
	{ GUI_OBJ_ID_REC_SWITCH, "record_switch", 1, 1, GUI_OBJ_STATUS_TYPE_VALUE, GUI_SWITCH_STATE_OFF },
	{ GUI_OBJ_ID_REC_STATE, "record_state", 1, 1, GUI_OBJ_STATUS_TYPE_VALUE, GUI_REC_STATE_STOP },
	{ GUI_OBJ_ID_REC_EVENT_RECORD_STATE, "event_record_state", 1, 0, GUI_OBJ_STATUS_TYPE_VALUE, GUI_EMERGENCY_REC_STOP },
	{ GUI_OBJ_ID_REC_VIEW_INDEX, "record_view", 1, 1, GUI_OBJ_STATUS_TYPE_VALUE, GUI_VIEW_INDEX_FRONT }
};*/
		
	if((DVR_GRAPHIC_UIOBJ*) hmiMsg.dvrTabMsg.tabMsgTable)
	{
		recordTabMsg = (DVR_GRAPHIC_UIOBJ*) hmiMsg.dvrTabMsg.tabMsgTable;
		for(int i = 0; i < hmiMsg.dvrTabMsg.objNum; i++)
		{			
			switch(recordTabMsg[i].Id)
			{
			case GUI_OBJ_ID_REC_SWITCH:

				if(recordTabMsg[i].uStatus.ObjVal == GUI_SWITCH_STATE_OFF)
				{
					m_buttonStatus[DVR_RECORD_TAB_RECORD_SWITCH] = BUTTON_OFF_IMAGE;                    
				}
				else if(recordTabMsg[i].uStatus.ObjVal == GUI_SWITCH_STATE_ON)
				{
					m_buttonStatus[DVR_RECORD_TAB_RECORD_SWITCH] = BUTTON_ON_IMAGE;
				}				
				break;

			case GUI_OBJ_ID_REC_STATE:
                if(recordTabMsg[i].uStatus.ObjVal == GUI_REC_STATE_START)
                {
                    if(recordTabMsg[i].bShow == 1)
                    {
                        m_buttonVisibility[DVR_RECORD_TAB_RED_DOT] = 1;
                    }
                    else if(recordTabMsg[i].bShow == 0)
                    {
                        m_buttonVisibility[DVR_RECORD_TAB_RED_DOT] = 0;
                    }
                }
                else if(recordTabMsg[i].uStatus.ObjVal == GUI_REC_STATE_STOP)
                {
                    m_buttonVisibility[DVR_RECORD_TAB_RED_DOT] = 0;
                }
				break;
                
			case  GUI_OBJ_ID_REC_EVENT_RECORD_STATE:
				
                if(recordTabMsg[i].bShow == GUI_EMERGENCY_REC_STOP)
				{
					m_buttonStatus[DVR_RECORD_TAB_EMERGENCY_ICON] = BUTTON_OFF_IMAGE;
                    m_buttonStatus[DVR_RECORD_TAB_RED_DOT] = 0;
                    m_baseButton[DVR_RECORD_TAB_RED_DOT] -> SetWidth(108.0);
                }
				else if(recordTabMsg[i].bShow == GUI_EMERGENCY_REC_RUNNING)
				{
					m_buttonStatus[DVR_RECORD_TAB_EMERGENCY_ICON] = BUTTON_ON_IMAGE;
                    m_buttonStatus[DVR_RECORD_TAB_RED_DOT] = 1;
                    m_baseButton[DVR_RECORD_TAB_RED_DOT] -> SetWidth(149.0);
				}
				break;

			case GUI_OBJ_ID_REC_VIEW_INDEX:
				
				m_buttonStatus[DVR_RECORD_TAB_VIEW_FRONT] = BUTTON_OFF_IMAGE;
				m_buttonStatus[DVR_RECORD_TAB_VIEW_REAR] = BUTTON_OFF_IMAGE;
				m_buttonStatus[DVR_RECORD_TAB_VIEW_LEFT] = BUTTON_OFF_IMAGE;
				m_buttonStatus[DVR_RECORD_TAB_VIEW_RIGHT] = BUTTON_OFF_IMAGE;
				
				if(recordTabMsg[i].uStatus.ObjVal == GUI_VIEW_INDEX_FRONT)
				{
					CAvmRenderDataBase::GetInstance()->SetDisplayViewCmd(DVR_FRONT_SINGLE_VIEW);					
					m_buttonStatus[DVR_RECORD_TAB_VIEW_FRONT] = BUTTON_ON_IMAGE;
				}
				else if(recordTabMsg[i].uStatus.ObjVal == GUI_VIEW_INDEX_REAR)
				{				
					CAvmRenderDataBase::GetInstance()->SetDisplayViewCmd(DVR_REAR_SINGLE_VIEW);
					m_buttonStatus[DVR_RECORD_TAB_VIEW_REAR] = BUTTON_ON_IMAGE;
				}
				else if(recordTabMsg[i].uStatus.ObjVal == GUI_VIEW_INDEX_LEFT)
				{				
					CAvmRenderDataBase::GetInstance()->SetDisplayViewCmd(DVR_LEFT_SINGLE_VIEW);
					m_buttonStatus[DVR_RECORD_TAB_VIEW_LEFT] = BUTTON_ON_IMAGE;
				}
				else if(recordTabMsg[i].uStatus.ObjVal == GUI_VIEW_INDEX_RIGHT)
				{				
					CAvmRenderDataBase::GetInstance()->SetDisplayViewCmd(DVR_RIGHT_SINGLE_VIEW);
					m_buttonStatus[DVR_RECORD_TAB_VIEW_RIGHT] = BUTTON_ON_IMAGE;
				}
				break;

            case GUI_OBJ_ID_SIDEBAR:
               
                if(recordTabMsg[i].bShow == GUI_SIDEBAR_STATUS_HIDE)
                {
                    m_menuVisibility = GUI_SIDEBAR_STATUS_HIDE;
                }
                else if(recordTabMsg[i].bShow == GUI_SIDEBAR_STATUS_SHOW)
                {
                    m_menuVisibility = GUI_SIDEBAR_STATUS_SHOW;
                }
//                Log_Error("GUI_SIDEBAR_STATUS = %d", m_menuVisibility);
                for (int i = DVR_RECORD_TAB_RECORD_BKG; i < DVR_RECORD_TAB_ELEMEMT_NUM; i++)
                {
                    m_buttonVisibility[i] = m_menuVisibility;
                }
                if (m_menuVisibility == GUI_SIDEBAR_STATUS_SHOW)
                {
                    m_buttonVisibility[DVR_RECORD_TAB_HIDE_ICON] = 1;
                    m_buttonVisibility[DVR_RECORD_TAB_SHOW_ICON] = 0;
                }
                else if (m_menuVisibility == GUI_SIDEBAR_STATUS_HIDE)
                {
                    m_buttonVisibility[DVR_RECORD_TAB_HIDE_ICON] = 0;
                    m_buttonVisibility[DVR_RECORD_TAB_SHOW_ICON] = 1;
                }
                break;

            default:
				break;
			}	
		}
	}
	RefreshHmi();
	return HMI_SUCCESS;
}
int CSVDvrRecordTab::RefreshHmi()
{
	for(int i = DVR_RECORD_TAB_RED_DOT; i < DVR_RECORD_TAB_ELEMEMT_NUM; i++)
	{
		m_baseButton[i]->SetShowIconNum(m_buttonStatus[i]);
		m_baseButton[i]->SetVisibility(m_buttonVisibility[i]);
		m_baseButton[i]->Update();
	}
	return HMI_SUCCESS;
}

int CSVDvrRecordTab::SetMenuVisibility()
{
     m_baseButtonData[DVR_RECORD_TAB_SHOW_ICON].trigger->OnPress(0);
     return HMI_SUCCESS;
}

int CSVDvrRecordTab::SetElementsVisibility(unsigned char pFlag)
{
    memset(m_buttonVisibility, pFlag, DVR_RECORD_TAB_ELEMEMT_NUM * sizeof(unsigned char));    
    if(pFlag == BUTTON_HIDE)
    {
	    for(int i = DVR_RECORD_TAB_RED_DOT; i < DVR_RECORD_TAB_ELEMEMT_NUM; i++)
	    {
		    m_baseButton[i]->SetVisibility(BUTTON_HIDE);
	    }        
    }
    else if(pFlag == BUTTON_SHOW)
    {
        if(m_menuVisibility == GUI_SIDEBAR_STATUS_HIDE)
        {
            m_baseButton[DVR_RECORD_TAB_RECORD_BKG]->SetVisibility(BUTTON_HIDE);
            m_baseButton[DVR_RECORD_TAB_HIDE_ICON]->SetVisibility(BUTTON_HIDE);
            m_baseButton[DVR_RECORD_TAB_SHOW_ICON]->SetVisibility(BUTTON_SHOW);
           	for(int i = DVR_RECORD_TAB_RECORD_TITLE; i < DVR_RECORD_TAB_ELEMEMT_NUM; i++)
	        {
		        m_baseButton[i]->SetVisibility(BUTTON_HIDE);
	        } 
        }
        if(m_menuVisibility == GUI_SIDEBAR_STATUS_SHOW)
        {
            m_baseButton[DVR_RECORD_TAB_RECORD_BKG]->SetVisibility(BUTTON_SHOW);
            m_baseButton[DVR_RECORD_TAB_HIDE_ICON]->SetVisibility(BUTTON_SHOW);
            m_baseButton[DVR_RECORD_TAB_SHOW_ICON]->SetVisibility(BUTTON_HIDE);
           	for(int i = DVR_RECORD_TAB_RECORD_TITLE; i < DVR_RECORD_TAB_ELEMEMT_NUM; i++)
	        {
		        m_baseButton[i]->SetVisibility(BUTTON_SHOW);
	        } 
        }
    }
	return HMI_SUCCESS;
}
int CSVDvrRecordTab::ReturnHmiMsg(Hmi_Message_T* hmi_msg)
{
	return HMI_SUCCESS;
}
int CSVDvrRecordTab::DestroyHmiElems()
{
	return HMI_SUCCESS;
}
