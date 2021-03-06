/*===========================================================================*\
 * FILE: CSVHmiIntent.h
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


#ifndef _CSV_HMI_INTENT_H_
#define _CSV_HMI_INTENT_H_

#include "../../XrCore/XrSrc/External/XrHeaders.h"

class ISVHmi;

class CSVHmiIntent
{
public:

	CSVHmiIntent();
	~CSVHmiIntent();

	static CSVHmiIntent* GetInstance();
	int Intent(ISVHmi* pFromHmi,  char* pToHmi);
	int Intent(char* pToHmi); 
	int StartHmi(void* hmiMsg);
	int MoveToAfter(int TargetNodeID,int NodeID);
	ISVHmi* GetCurrentHmi();

private:

	ISVHmi* m_fromHmi;
	ISVHmi* m_toHmi;

	unsigned char m_toHmiUpdateStatus;

};


#endif //_CSV_HMI_INTENT_H_


/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *   Date        userid       Description
 * ----------- ----------    -----------
 *  12/16/17   Jensen Wang   Create the CSVHmiIntent class.
\*===========================================================================*/