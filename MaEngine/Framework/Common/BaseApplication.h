//
// Created by 马邦进 on 2018/4/21.
//

#ifndef MAENGINE_BASEAPPLICATION_H
#define MAENGINE_BASEAPPLICATION_H

#include "Interface/Interface.h"
#include "Interface/IApplication .h"
#include "GfxConfiguration.h"
#include "MaEngineDef.h"

NAMESPACEBEGINE
	extern IApplication* g_pApp;
    class MaEngine_DLL BaseApplication : implements IApplication {
    public:
        BaseApplication(GfxConfiguration &cfg);

        virtual int Initialize();

        virtual void Finalize();

        // One cycle of the main loop
        virtual void Tick();

        virtual bool IsQuit();

    protected:
        // 标记是否在住循环中退出
        static bool m_bQuit;
        GfxConfiguration m_Config;
    private:
        // hide the default construct to enforce a configuration
        BaseApplication() {};
    };
NAMESPACEEND
#endif //MAENGINE_BASEAPPLICATION_H
