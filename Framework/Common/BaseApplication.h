//
// Created by 马邦进 on 2018/4/21.
//

#ifndef MAENGINE_BASEAPPLICATION_H
#define MAENGINE_BASEAPPLICATION_H

#include "../Interface/Interface.h"
#include "../Interface/IApplication .h"

namespace My {
    class BaseApplication : implements IApplication
            {
                    public:
                    virtual int Initialize();
                    virtual void Finalize();
                    // One cycle of the main loop
                    virtual void Tick();

                    virtual bool IsQuit();

                    protected:
                    // 标记是否在住循环中退出
                    bool m_bQuit;
            };
}
#endif //MAENGINE_BASEAPPLICATION_H
