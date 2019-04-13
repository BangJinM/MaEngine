//
// Created by 马邦进 on 2018/4/21.
//
#include "BaseApplication.h"
#include <iostream>
NAMESPACEBEGINE
bool BaseApplication::m_bQuit = false;
void BaseApplication::Finalize() {}

void BaseApplication::Tick() {}

int BaseApplication::Initialize() {
    std::cout << m_Config;
    return 0;
}

bool BaseApplication::IsQuit() {
    return m_bQuit;
}

BaseApplication::BaseApplication(GfxConfiguration& cfg)
  :m_Config(cfg)
{

}
NAMESPACEEND