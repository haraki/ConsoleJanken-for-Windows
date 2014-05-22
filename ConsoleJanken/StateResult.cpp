//
//  StateResult.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include "Janken.h"
#include "StateResult.h"
#include "StatePrepare.h"
#include "StateDisconnect.h"

StateResult::StateResult()
: StateMachine("JAN")
{
    
}

StateResult::~StateResult()
{
    
}

int StateResult::entry()
{
//    std::cout << "State = \"" << m_name << "\"\n" << std::endl;
    
    return 0;
}

int StateResult::execute()
{
    return 0;
}

int StateResult::exit()
{
    return 0;
}

int StateResult::eventFrame(StateContext& context, const Leap::Controller& controller)
{
    int ret = 0;
    
    const Leap::Frame frame = controller.frame();
    const Leap::Hand hand = frame.hands()[0];
    
    int fingerNum = hand.fingers().count();
    
    if(fingerNum <= 1)
    {
        JankenApp::getInstance()->setResult(RESULT_TYPE_GU);
    }
    else if(fingerNum <= 3)
    {
        JankenApp::getInstance()->setResult(RESULT_TYPE_CHOKI);
    }
    else
    {
        JankenApp::getInstance()->setResult(RESULT_TYPE_PAH);
    }
    
    ret = context.changeState(StatePrepare::getInstance());
    
    return ret;
}

int StateResult::eventHandLost(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StatePrepare::getInstance());
    
    return ret;
}

int StateResult::eventDisconnect(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StateDisconnect::getInstance());
    
    return ret;
}
