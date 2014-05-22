//
//  StateMachine.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/23.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__StateMachine__
#define __ConsoleJanken__StateMachine__

#include <iostream>
#include "StateContext.h"
#include "Leap.h"

class StateContext;

class StateMachine
{
public:
    StateMachine(const char* name);
    virtual ~StateMachine();
    
    virtual int entry()   = 0;
    virtual int exit()    = 0;
    virtual int execute() = 0;
    
    virtual int eventInit(StateContext& context, const Leap::Controller& controller);
    virtual int eventExit(StateContext& context, const Leap::Controller& controller);
    virtual int eventConnect(StateContext& context, const Leap::Controller& controller);
    virtual int eventDisconnect(StateContext& context, const Leap::Controller& controller);
    virtual int eventFrame(StateContext& context, const Leap::Controller& controller);
    virtual int eventFocusGained(StateContext& context, const Leap::Controller& controller);
    virtual int eventFocusLost(StateContext& context, const Leap::Controller& controller);
    virtual int eventShake(StateContext& context, const Leap::Controller& controller);
    virtual int eventHandLost(StateContext& context, const Leap::Controller& controller);
    
protected:
    std::string m_name;
};

template <class T>
class SingletonState
{
public:
    SingletonState() {}
    virtual ~SingletonState() {}
    
    static T& getInstance()
    {
        static T instance;
        
        return instance;
    }
    
private:
};

#endif /* defined(__ConsoleJanken__StateMachine__) */
