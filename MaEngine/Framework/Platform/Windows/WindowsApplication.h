//
// Created by 马邦进 on 2018/4/21.
//

#ifndef MAENGINE_WINDOWSAPPLICATION_H
#define MAENGINE_WINDOWSAPPLICATION_H
#if _WIN32



#include <windows.h>
#include <windowsx.h>
#include "Common/BaseApplication.h"
#include "MaEngineDef.h"

NAMESPACEBEGINE
    class MaEngine_DLL WindowsApplication : public BaseApplication
    {
    public:
        WindowsApplication(GfxConfiguration& config)
                : BaseApplication(config) {};

        virtual int Initialize();
        virtual void Finalize();
        // One cycle of the main loop
        virtual void Tick();

        // the WindowProc function prototype
        static LRESULT CALLBACK WindowProc(HWND hWnd,
                                           UINT message,
                                           WPARAM wParam,
                                           LPARAM lParam);
    };
}
#endif // WIN32
#endif //MAENGINE_WINDOWSAPPLICATION_H
