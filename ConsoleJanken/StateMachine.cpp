//
//  StateMachine.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/23.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include "StateContext.h"
#include "StateMachine.h"

StateMachine::StateMachine(const char* name)
: m_name(name)
{
}

StateMachine::~StateMachine()
{
}

int StateMachine::eventInit(StateContext& context, const Leap::Controller& controller)
{
    return 0;
}

int StateMachine::eventExit(StateContext& context, const Leap::Controller& controller)
{
    return 0;
}

int StateMachine::eventConnect(StateContext& context, const Leap::Controller& controller)
{
    return 0;
}

int StateMachine::eventDisconnect(StateContext& context, const Leap::Controller& controller)
{
    return 0;
}

int StateMachine::eventFrame(StateContext& context, const Leap::Controller& controller)
{
    return 0;
}

int StateMachine::eventFocusGained(StateContext& context, const Leap::Controller& controller)
{
    return 0;
}

int StateMachine::eventFocusLost(StateContext& context, const Leap::Controller& controller)
{
    return 0;
}

int StateMachine::eventShake(StateContext& context, const Leap::Controller& controller)
{
    return 0;
}

int StateMachine::eventHandLost(StateContext& context, const Leap::Controller& controller)
{
    return 0;
}
