//
// Created by 马邦进 on 2018/4/21.
//
#include "BaseApplication.h"
#include <iostream>
bool MaEngine::BaseApplication::m_bQuit = false;
void MaEngine::BaseApplication::Finalize() {}

void MaEngine::BaseApplication::Tick() {}

int MaEngine::BaseApplication::Initialize() {
    std::cout << m_Config;
    return 0;
}

bool MaEngine::BaseApplication::IsQuit() {
    return m_bQuit;
}

MaEngine::BaseApplication::BaseApplication(GfxConfiguration& cfg)
  :m_Config(cfg)
{

}