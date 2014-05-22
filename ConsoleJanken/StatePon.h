//
//  StatePon.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/22.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__StatePon__
#define __ConsoleJanken__StatePon__

#include <iostream>
#include "StateMachine.h"

class StatePon : public StateMachine, public SingletonState <StatePon>
{
public:
    StatePon();
    ~StatePon();
    
    int entry();
    int execute();
    int exit();
    
    int eventHandLost(StateContext& context, const Leap::Controller& controller);
    int eventShake(StateContext& context, const Leap::Controller& controller);
    int eventDisconnect(StateContext& context, const Leap::Controller& controller);
};

#endif /* defined(__ConsoleJanken__StatePon__) */
