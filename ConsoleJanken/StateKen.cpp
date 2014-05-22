//
//  StateKen.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include "Janken.h"
#include "StateKen.h"
#include "StatePon.h"
#include "StatePrepare.h"
#include "StateDisconnect.h"

StateKen::StateKen()
: StateMachine("KEN")
{
    
}

StateKen::~StateKen()
{
    
}

int StateKen::entry()
{
//    std::cout << "State = \"" << m_name << "\"\n" << std::endl;
    
    return 0;
}

int StateKen::execute()
{
    return 0;
}

int StateKen::exit()
{
    return 0;
}

int StateKen::eventHandLost(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StatePrepare::getInstance());
    
    return ret;
}

int StateKen::eventShake(StateContext& context, const Leap::Controller& controller)
{
    std::cout << "けん\n" << std::endl;
    
    const Leap::Frame frame = controller.frame();
    const Leap::Hand hand = frame.hands()[0];
    
    Leap::Vector position = hand.palmPosition();
    
    JankenApp::getInstance()->setShakeStartPosition(position);
    
    int ret = context.changeState(StatePon::getInstance());
    
    return ret;
}

int StateKen::eventDisconnect(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StateDisconnect::getInstance());
    
    return ret;
}
