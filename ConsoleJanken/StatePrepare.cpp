//
//  StatePrepare.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/23.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include "Janken.h"
#include "StatePrepare.h"
#include "StateJan.h"
#include "StateDisconnect.h"

StatePrepare::StatePrepare()
: StateMachine("PREPARE")
, m_count(0)
{
    
}

StatePrepare::~StatePrepare()
{
    
}

int StatePrepare::entry()
{
//    std::cout << "State = \"" << m_name << "\"\n" << std::endl;
    
    return 0;
}

int StatePrepare::execute()
{
    return 0;
}

int StatePrepare::exit()
{
    return 0;
}

int StatePrepare::eventFrame(StateContext& context, const Leap::Controller& controller)
{
    int ret = 0;
    
    const Leap::Frame frame = controller.frame();
    
    if(!frame.hands().isEmpty())
    {
        const Leap::Hand hand = frame.hands()[0];
    
        if(!hand.fingers().isEmpty())
        {
            std::cout << "Are you ready?\n" << std::endl;
        
            Leap::Vector position = hand.palmPosition();
        
            JankenApp::getInstance()->setShakeStartPosition(position);
        
            ret = context.changeState(StateJan::getInstance());
        }
    }
    
    return ret;
}

int StatePrepare::eventHandLost(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StatePrepare::getInstance());
    
    return ret;
}

int StatePrepare::eventDisconnect(StateContext& context, const Leap::Controller& controller)
{
    int ret = context.changeState(StateDisconnect::getInstance());
    
    return ret;
}
