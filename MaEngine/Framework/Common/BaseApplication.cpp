//
// Created by 马邦进 on 2018/4/21.
//
#include "BaseApplication.h"
#include <iostream>
bool My::BaseApplication::m_bQuit = false;
void My::BaseApplication::Finalize() {}

void My::BaseApplication::Tick() {}

int My::BaseApplication::Initialize() {
    std::cout << m_Config;
    return 0;
}

bool My::BaseApplication::IsQuit() {
    return m_bQuit;
}

My::BaseApplication::BaseApplication(GfxConfiguration& cfg)
  :m_Config(cfg)
{

}