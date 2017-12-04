#ifndef CGpuAvmEvent_h
#define CGpuAvmEvent_h

#include <stdio.h>
#include "event/RawAvmEvent.h"
#include "log/LogHelper.hpp"
#include "log/log.h"
#include "utils/utils.h"
#include "global/config.h"
#include "GpuAvmEvent.h"

//前置申明
class AvmEvent;

/*
 * \brief 
 */
class CGpuAvmEventDelegate
{

public:
    CGpuAvmEventDelegate(const char* className);
    virtual ~CGpuAvmEventDelegate();

    /*
     * \brief 请求AvmEvent,分配event 对象，用于数据填充
     */
    AvmEvent* RequestEvent(Layout_Event_Payload_T** payload);
    /*
     * \brief 请求post 指定数据
     */
    bool PostEvent(AvmEvent* avm_event);
    
    /*
     * \brief 函数内部已完成event 请求，可直接post 指定数据
     */
    bool PostEventPayload(Layout_Event_Payload_T* payload);

private:
    /*
     * \brief 绑定AvmEvent
     */
    bool RegisterAvmEvent(const char* eventName);
    
private:
    AvmEventType m_eventType; //AvmEvent事件类型id
    const char* m_className;  //Layout className
};


#endif /* CGpuAvmEvent_hpp */
