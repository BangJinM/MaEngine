//
// Created by 马邦进 on 2018/4/21.
//
#include "BaseApplication.h"
void My::BaseApplication::Finalize() {}

void My::BaseApplication::Tick() {}

int My::BaseApplication::Initialize() {
    m_bQuit = false;
    return 0;
}

bool My::BaseApplication::IsQuit() {
    return m_bQuit;
}