//
//  StateDisconnect.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include "StateDisconnect.h"
#include "StateConnect.h"

StateDisconnect::StateDisconnect()
: StateMachine("DISCONNECT")
{
    
}

StateDisconnect::~StateDisconnect()
{
    
}

int StateDisconnect::entry()
{
//    std::cout << "State = \"" << m_name << "\"\n" << std::endl;
    
    return 0;
}

int StateDisconnect::execute()
{
    return 0;
}

int StateDisconnect::exit()
{
    return 0;
}

int StateDisconnect::eventConnect(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StateConnect::getInstance());
    
    return ret;
}
