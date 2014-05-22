//
//  Janken.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/21.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__JankenApp__
#define __ConsoleJanken__JankenApp__

#include <iostream>
#include <map>
#include "Leap.h"
#include "StateContext.h"
using namespace Leap;

enum ShakeStateType
{
    SHAKE_STATE_NONE,
    
    SHAKE_STATE_RISE,
    SHAKE_STATE_DESCENT,
};

enum ResultType
{
    RESULT_TYPE_NONE,
    
    RESULT_TYPE_GU,
    RESULT_TYPE_CHOKI,
    RESULT_TYPE_PAH,
};

class JankenApp : public Leap::Listener, public StateContext
{
public:
    JankenApp();
    virtual ~JankenApp();
        
    static int create();
    static int destroy();
    static int execute();
    
    int setResult(ResultType result);
    int clearShakeStartPosition();
    int setShakeStartPosition(Leap::Vector& position);
    
    static JankenApp* getInstance() { return m_instance; }
    
private:
    bool isShaked(const Hand& hand);
    
    virtual void onInit(const Leap::Controller&b);
    virtual void onExit(const Leap::Controller&);
    virtual void onConnect(const Leap::Controller&);
    virtual void onDisconnect(const Leap::Controller&);
    virtual void onFrame(const Leap::Controller&);
    virtual void onFocusGained(const Leap::Controller&);
    virtual void onFocusLost(const Leap::Controller&);
    
    Leap::Controller m_controller;
    
    bool m_handExist;
    
    ResultType m_result;
    
    int32_t m_count;
    
    ShakeStateType m_shakeState;
    Leap::Vector m_startShakePosition;
    
    static JankenApp* m_instance;
};

#endif /* defined(__ConsoleJanken__JankenApp__) */
