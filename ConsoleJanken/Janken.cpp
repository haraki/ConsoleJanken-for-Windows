//
//  Janken.cpp
//  ConsoleJanken
//
//  Created by 原木 正志 on 2014/04/21.
//  Copyright (c) 2014年 Masashi Haraki. All rights reserved.
//

#include <iostream>
#include "Janken.h"

#include "StateInitialize.h"
#include "StateConnect.h"
#include "StateDisconnect.h"
#include "StateJan.h"
#include "StateKen.h"
#include "StatePon.h"
#include "StateResult.h"

#define FRAME_OUTPUT()  \
{                       \
    std::cout << "Frame id: " << frame.id() \
    << ", timestamp: " << frame.timestamp() \
    << ", hands: " << frame.hands().count() \
    << ", fingers: " << frame.fingers().count()                     \
    << ", tools: " << frame.tools().count()                         \
    << ", gestures: " << frame.gestures().count() << std::endl;     \
}

JankenApp* JankenApp::m_instance = NULL;

int JankenApp::create()
{
    JankenApp::m_instance = new JankenApp();

    return 0;
}

int JankenApp::destroy()
{
    delete JankenApp::m_instance;
    m_instance = NULL;
    
    return 0;
}

JankenApp::JankenApp()
    : Leap::Listener()
    , m_controller()
    , m_handExist(false)
    , m_result(RESULT_TYPE_NONE)
    , m_count(0)
{
    clearShakeStartPosition();
    
    changeState(StateInitialize::getInstance());
    
    m_controller.addListener(*this);
}

JankenApp::~JankenApp()
{
    m_controller.removeListener(*this);
}

int JankenApp::execute()
{
    std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();
    
    return 0;
}

int JankenApp::setResult(ResultType result)
{
    m_result = result;
    
    switch(m_result)
    {
        case RESULT_TYPE_GU:
            std::cout << "ぐー\n" << std::endl;
            break;
        case RESULT_TYPE_CHOKI:
            std::cout << "ちょき\n" << std::endl;
            break;
        case RESULT_TYPE_PAH:
            std::cout << "ぱー\n" << std::endl;
            break;
        default:
            break;
    }
    
    return 0;
}

int JankenApp::clearShakeStartPosition()
{
    m_shakeState = SHAKE_STATE_NONE;
    
    m_startShakePosition.x = 0.0F;
    m_startShakePosition.y = 0.0F;
    m_startShakePosition.z = 0.0F;
    
    return 0;
}

int JankenApp::setShakeStartPosition(Leap::Vector& position)
{
    m_shakeState = SHAKE_STATE_RISE;
    m_startShakePosition = position;
    
    return 0;
}

bool JankenApp::isShaked(const Hand& hand)
{
    if(++m_count >= 100)
    {
        m_count = 0;
        return true;
    }
    
    return false;
}

void JankenApp::onInit(const Leap::Controller& controller)
{
    std::cout << "onInit.\n" << std::endl;
    if (m_currentState != NULL)
    {
        m_currentState->eventInit(*this, controller);
    }
}

void JankenApp::onExit(const Leap::Controller& controller)
{
    std::cout << "onExit.\n" << std::endl;
    if (m_currentState != NULL)
    {
        m_currentState->eventExit(*this, controller);
    }
}

void JankenApp::onConnect(const Leap::Controller& controller)
{
    std::cout << "onConnect.\n" << std::endl;
    if (m_currentState != NULL)
    {
        m_currentState->eventConnect(*this, controller);
    }
}

void JankenApp::onDisconnect(const Leap::Controller& controller)
{
    std::cout << "onDisconnect.\n" << std::endl;
    if (m_currentState != NULL)
    {
        m_currentState->eventDisconnect(*this, controller);
    }
}

void JankenApp::onFrame(const Leap::Controller& controller)
{
//    std::cout << "onFrame.\n" << std::endl;
    if (m_currentState != NULL)
    {
        m_currentState->eventFrame(*this, controller);
    }
    
    const Leap::Frame frame = controller.frame();
    const Hand hand = frame.hands()[0];
    
    bool handExist = false;
    
    if (!frame.hands().isEmpty())
    {
        handExist = true;
    }
    else
    {
        handExist = false;
    }
    
    if(handExist != m_handExist)
    {
        m_handExist = handExist;
        m_count = 0;
        
        if(!m_handExist)
        {
            std::cout << "Hand lost\n" << std::endl;
            
            clearShakeStartPosition();
            
            if (m_currentState != NULL)
            {
                m_currentState->eventHandLost(*this, controller);
            }
        }
    }
    else if(handExist)
    {
        //        FRAME_OUTPUT();
        Leap::Vector nowPosition = hand.palmPosition();
        switch(m_shakeState)
        {
            case SHAKE_STATE_RISE:
//                std::cout << "RISE : start.y = " << m_startShakePosition.y << " : nowPosition.y = " << nowPosition.y << "\n";
                if(nowPosition.y >= m_startShakePosition.y + 200)
                {
                    m_shakeState = SHAKE_STATE_DESCENT;
                }
                break;
            case SHAKE_STATE_DESCENT:
//                std::cout << "DESC : start.y = " << m_startShakePosition.y << " : nowPosition.y = " << nowPosition.y << "\n";
                if(hand.palmPosition().y <= m_startShakePosition.y)
                {
                    m_shakeState = SHAKE_STATE_NONE;
                    m_currentState->eventShake(*this, controller);
                }
                break;
            default:
                break;
        }
    }
}

void JankenApp::onFocusGained(const Leap::Controller& controller)
{
    std::cout << "onFocusGained.\n" << std::endl;
    if (m_currentState != NULL)
    {
        m_currentState->eventFocusGained(*this, controller);
    }
}

void JankenApp::onFocusLost(const Leap::Controller& controller)
{
    std::cout << "onFocusLost.\n" << std::endl;
    if (m_currentState != NULL)
    {
        m_currentState->eventFocusLost(*this, controller);
    }
}
