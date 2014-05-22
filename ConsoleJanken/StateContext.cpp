//
//  StateContext.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/23.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include "StateContext.h"
#include "StateMachine.h"

StateContext::StateContext()
: m_currentState(NULL)
{
    
}

StateContext::~StateContext()
{
    
}

int StateContext::changeState(StateMachine& newState)
{
    int ret = 0;
    
    if(m_currentState != NULL)
    {
        ret = m_currentState->exit();
        if(ret < 0)
        {
            return ret;
        }
    }
    
    m_currentState = &newState;
    ret = m_currentState->entry();
    if(ret < 0)
    {
        return ret;
    }
    
    return 0;
}
