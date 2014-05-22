//
//  StateDisconnect.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__StateDisconnect__
#define __ConsoleJanken__StateDisconnect__

#include <iostream>
#include "StateMachine.h"

class StateDisconnect : public StateMachine, public SingletonState <StateDisconnect>
{
public:
    StateDisconnect();
    ~StateDisconnect();
    
    int entry();
    int execute();
    int exit();
    
    int eventConnect(StateContext& context, const Leap::Controller& controller);
};

#endif /* defined(__ConsoleJanken__StateDisconnect__) */
