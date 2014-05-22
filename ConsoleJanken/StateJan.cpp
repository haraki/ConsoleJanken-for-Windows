//
//  StateJan.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include "Janken.h"
#include "StateJan.h"
#include "StateKen.h"
#include "StatePrepare.h"
#include "StateDisconnect.h"

StateJan::StateJan()
: StateMachine("JAN")
{
    
}

StateJan::~StateJan()
{
    
}

int StateJan::entry()
{
//    std::cout << "State = \"" << m_name << "\"\n" << std::endl;
    
    return 0;
}

int StateJan::execute()
{
    return 0;
}

int StateJan::exit()
{
    return 0;
}

int StateJan::eventHandLost(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StatePrepare::getInstance());
    
    return ret;
}

int StateJan::eventShake(StateContext& context, const Leap::Controller& controller)
{
    std::cout << "じゃん\n" << std::endl;
    
    const Leap::Frame frame = controller.frame();
    const Leap::Hand hand = frame.hands()[0];
    
    Leap::Vector position = hand.palmPosition();
    
    JankenApp::getInstance()->setShakeStartPosition(position);
    
    int ret = context.changeState(StateKen::getInstance());
    
    return ret;
}

int StateJan::eventDisconnect(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StateDisconnect::getInstance());
    
    return ret;
}
