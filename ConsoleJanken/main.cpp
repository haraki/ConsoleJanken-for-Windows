//
//  main.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/21.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include <iostream>
#include "Janken.h"

int main(int argc, const char * argv[])
//int _tmain(int argc, _TCHAR* argv[])
{
    std::cout << "Janken\n";
    
    int ret = 0;
    
    ret = JankenApp::create();
    if(ret < 0)
    {
        std::cout << "JankenApp::create() error. ret = " << ret << "\n";
        return ret;
    }
    
    ret = JankenApp::execute();
    if(ret < 0)
    {
        std::cout << "JankenApp::execute() error. ret = " << ret << "\n";
        return ret;
    }
    
    ret = JankenApp::destroy();
    if(ret < 0)
    {
        std::cout << "JankenApp::destroy() error. ret = " << ret << "\n";
        return ret;
    }
    
    return 0;
}

