//
//  StateJan.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__StateJan__
#define __ConsoleJanken__StateJan__

#include <iostream>
#include "StateMachine.h"

class StateJan : public StateMachine, public SingletonState <StateJan>
{
public:
    StateJan();
    ~StateJan();
    
    int entry();
    int execute();
    int exit();
    
    int eventHandLost(StateContext& context, const Leap::Controller& controller);
    int eventShake(StateContext& context, const Leap::Controller& controller);
    int eventDisconnect(StateContext& context, const Leap::Controller& controller);
};

#endif /* defined(__ConsoleJanken__StateJan__) */
