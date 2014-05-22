//
//  StateResult.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__StateResult__
#define __ConsoleJanken__StateResult__

#include <iostream>
#include "StateMachine.h"

class StateResult : public StateMachine, public SingletonState <StateResult>
{
public:
    StateResult();
    ~StateResult();
    
    int entry();
    int execute();
    int exit();
    
    int eventHandLost(StateContext& context, const Leap::Controller& controller);
    int eventFrame(StateContext& context, const Leap::Controller& controller);
    int eventDisconnect(StateContext& context, const Leap::Controller& controller);
};

#endif /* defined(__ConsoleJanken__StateResult__) */
