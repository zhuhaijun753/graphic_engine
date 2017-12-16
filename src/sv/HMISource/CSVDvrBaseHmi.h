#ifndef _CSV_DVR_BASE_HMI_H_
#define _CSV_DVR_BASE_HMI_H_

#include "ISVHmi.h"

typedef enum DvrBaseHmiElementTag
{
	DVR_BASE_TITLE_BKG = 0,
	DVR_BASE_TAB_BKG,
	DVR_BASE_TITLE_ICON,
	DVR_BASE_LIVE_VIDEO_TAB,
	DVR_BASE_FILE_TAB,
	DVR_BASE_SETTING_TAB,
	DVR_BASE_ELEMEMT_NUM,
}
DvrBaseHmiElementT;

class CSVDvrBaseHmi : public ISVHmi
{
public:

	CSVDvrBaseHmi();
	HMI_BASE_INHERITANCE_FUNC()

private:
	int SetHmiParams();
	int RefreshHmi();
private:
	Hmi_Button_Data_T m_baseButtonData[DVR_BASE_ELEMEMT_NUM];
    HMIButton* m_baseButton[DVR_BASE_ELEMEMT_NUM];

	float m_buttonPos[DVR_BASE_ELEMEMT_NUM][BUTTON_POS];
	float m_buttonSize[DVR_BASE_ELEMEMT_NUM][BUTTON_SIZE];

	IActionTrigger*	m_trigger[DVR_BASE_ELEMEMT_NUM];

	unsigned char m_dvrStatus;	
	unsigned char m_buttonStatus[DVR_BASE_ELEMEMT_NUM];
	unsigned char m_buttonVisibility[DVR_BASE_ELEMEMT_NUM];

	ISVHmi* m_dvrSettingTab;
	ISVHmi* m_dvrRecordTab;
	ISVHmi* m_dvrPlaybackTab;

	unsigned char m_dvrSettingTabVisibility;
	unsigned char m_dvrRecordTabVisibility;
	unsigned char m_dvrPlaybackTabVisibility;

	int     m_windowHeight;
	int     m_windowWidth;
	
public:	
	int SetDvrStatus(unsigned char pDvrStatus);
	
};


#endif //_CSV_DVR_BASE_HMI_H_