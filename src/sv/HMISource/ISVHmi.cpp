#include "ISVHmi.h"
//#include "gpu_log.h"

extern IXrCore* g_pIXrCore;

ISVHmi::ISVHmi(IUINode* pUiNode, int pUiNodeId):m_viewState(0)
{
	if(pUiNode == NULL)
    {
    	m_uiNodeId = g_pIXrCore->CreateRenderNodeUI(RenderNodeType_UI2D, 0, &m_uiNode);
		m_uiNodeInsertFlag = InsertFlag_Default;
	}
	else
	{
		m_uiNode = pUiNode;
		m_uiNodeId = pUiNodeId;
		m_uiNodeInsertFlag = InsertFlag_Child;
	}
}

IUINode* ISVHmi::GetSvHmiNode(int& pUiNodeId)
{
	pUiNodeId = m_uiNodeId;

	return m_uiNode;
}


ISVHmi::~ISVHmi()
{
	//Log_Message("--------delete ISVHmi!!!");
	if(m_uiNodeInsertFlag == InsertFlag_Default)
    {
    	Log_Message("--------delete ISVHmi!!!");
    	g_pIXrCore->ReleaseRenderNode(m_uiNodeId);
	}
}

int ISVHmi::Init(int window_width, int window_height)
{
    return HMI_SUCCESS;
}

int ISVHmi::Update(Hmi_Message_T& hmiMsg)
{
    return HMI_SUCCESS;
}
int ISVHmi::ReturnHmiMsg(Hmi_Message_T* pHmiMsg)
{
    return HMI_SUCCESS;
}
int ISVHmi::SetVisibility(unsigned int flag)
{
    if(flag > 1)
    {
        flag = 1;
    }

    m_visibilityStatus = flag;
    m_uiNode->SetEnable(m_visibilityStatus);
    
    return HMI_SUCCESS;
}

bool ISVHmi::SetSingleTouchDownEvent(int x, int y)
{
	m_touchEventFlag = TouchEvent_Down;
	m_touchDownEventPosX = x;
	m_touchDownEventPosY = y;

	return true;
}
bool ISVHmi::GetTouchEventInfo(int &x, int &y, int &type)
{
	switch(m_touchEventFlag)
	{
	case TouchEvent_Down:
		type = TouchEvent_Down;
		x = m_touchDownEventPosX;
		y = m_touchDownEventPosY;
		m_touchEventFlag = 0;
		return true;
		break;
	default:
		
		break;
	}
	
	return false;
}
bool ISVHmi::SetCurrentView(unsigned char viewIndex)
{
    m_viewState = viewIndex;
    return true;
}
bool ISVHmi::GetCurrentView(unsigned char &viewIndex)
{
    viewIndex = m_viewState;
    return true;
}

bool ISVHmi::SetAvmDisplayView(unsigned char viewIndex)
{
    m_avmDisplayViewState = viewIndex;
}
bool ISVHmi::GetAvmDisplayView(unsigned char &viewIndex)
{
    viewIndex = m_avmDisplayViewState;
}
int ISVHmi::SetElementsVisibility(unsigned char pFlag)
{
	return HMI_SUCCESS;
}

int ISVHmi::MockTouchEvent(Hmi_Message_T& hmiMsg)
{
	return HMI_NO_MOCK_DATA;
}

int ISVHmi::DestroyHmiElems()
{
    return HMI_SUCCESS;
}
