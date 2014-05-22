//
//  StateInitialize.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__StateInitialize__
#define __ConsoleJanken__StateInitialize__

#include <iostream>
#include "StateMachine.h"

class StateInitialize : public StateMachine, public SingletonState <StateInitialize>
{
public:
    StateInitialize();
    ~StateInitialize();
    
    int entry();
    int execute();
    int exit();
    
    int eventInit(StateContext& context, const Leap::Controller& controller);
};

#endif /* defined(__ConsoleJanken__StateInitialize__) */
