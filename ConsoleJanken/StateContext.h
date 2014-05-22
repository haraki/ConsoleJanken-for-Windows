//
//  StateContext.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/23.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__StateContext__
#define __ConsoleJanken__StateContext__

#include <iostream>
#include "StateMachine.h"

class StateMachine;

class StateContext
{
public:
    StateContext();
    virtual ~StateContext();
    
    int changeState(StateMachine& newState);
    
protected:
    StateMachine* m_currentState;
};


#endif /* defined(__ConsoleJanken__StateContext__) */
