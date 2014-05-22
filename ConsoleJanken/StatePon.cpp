//
//  StatePon.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include "StatePon.h"
#include "StateResult.h"
#include "StatePrepare.h"
#include "StateDisconnect.h"

StatePon::StatePon()
: StateMachine("PON")
{
    
}

StatePon::~StatePon()
{
    
}

int StatePon::entry()
{
//    std::cout << "State = \"" << m_name << "\"\n" << std::endl;
    
    return 0;
}

int StatePon::execute()
{
    return 0;
}

int StatePon::exit()
{
    return 0;
}

int StatePon::eventHandLost(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StatePrepare::getInstance());
    
    return ret;
}

int StatePon::eventShake(StateContext& context, const Leap::Controller& controller)
{
    std::cout << "ぽん\n" << std::endl;
    
    int ret = context.changeState(StateResult::getInstance());
    
    return ret;
}

int StatePon::eventDisconnect(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StateDisconnect::getInstance());
    
    return ret;
}
