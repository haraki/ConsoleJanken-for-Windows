//
//  StateConnect.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__StateConnect__
#define __ConsoleJanken__StateConnect__

#include <iostream>
#include "StateMachine.h"

class StateConnect : public StateMachine, public SingletonState <StateConnect>
{
public:
    StateConnect();
    ~StateConnect();
    
    int entry();
    int execute();
    int exit();
    
    int eventConnect(StateContext& context, const Leap::Controller& controller);
};

#endif /* defined(__ConsoleJanken__StateConnect__) */
