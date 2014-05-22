//
//  StateConnect.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include "StateConnect.h"
#include "StatePrepare.h"

StateConnect::StateConnect()
: StateMachine("CONNECT")
{
    
}

StateConnect::~StateConnect()
{
    
}

int StateConnect::entry()
{
//    std::cout << "State = \"" << m_name << "\"\n" << std::endl;
    
    return 0;
}

int StateConnect::execute()
{
    return 0;
}

int StateConnect::exit()
{
    return 0;
}

int StateConnect::eventConnect(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StatePrepare::getInstance());
    
    return ret;
}
