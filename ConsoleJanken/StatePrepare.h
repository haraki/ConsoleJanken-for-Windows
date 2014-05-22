//
//  StatePrepare.h
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/23.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#ifndef __ConsoleJanken__StatePrepare__
#define __ConsoleJanken__StatePrepare__

#include <iostream>
#include "StateMachine.h"

class StatePrepare : public StateMachine, public SingletonState <StatePrepare>
{
public:
    StatePrepare();
    ~StatePrepare();
    
    int entry();
    int execute();
    int exit();
    
    int eventFrame(StateContext& context, const Leap::Controller& controller);
    int eventHandLost(StateContext& context, const Leap::Controller& controller);
    int eventDisconnect(StateContext& context, const Leap::Controller& controller);
private:
    int m_count;
};

#endif /* defined(__ConsoleJanken__StatePrepare__) */
