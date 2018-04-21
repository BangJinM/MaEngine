#include <iostream>

/*
 *  输入管理模块，用来获取用户输入
 *  策略模块，用来执行策略
 *  场景管理模块，用来管理场景和更新场景
 *  渲染模块，用来执行渲染和画面输出
 *  频音效模块，用来管理声音，混音和播放
 *  网络通信模块，用来管理网络通信
 *  文件I/O模块，用来管理资源的加载和参数的保存回复
 *  内存管理模块，用来调度管理内存上的资源
 *  驱动模块，用来根据时间，事件等驱动其它模块
 *  辅助模块，用来执行调试，log输出等辅助功能
 *  应用程序模块，用来抽象处理配置文件，特定平台的通知，创建窗口等需要与特定平台对接的部分
 *
 */
#include "../Interface/IApplication .h"

using namespace My;
namespace My {
    extern IApplication* g_pApp;
}
int main(int argc, char** argv) {
    int ret;

    if ((ret = g_pApp->Initialize()) != 0) {
        printf("App Initialize failed, will exit now.");
        return ret;
    }

    while (!g_pApp->IsQuit()) {
        g_pApp->Tick();
    }

    g_pApp->Finalize();
    return 0;
}