//
// Created by 马邦进 on 2018/4/26.
//

#ifndef MAENGINE_XCBAPPLICATION_H
#define MAENGINE_XCBAPPLICATION_H
#if linux
#include "Empty/EmptyApplication.h"
class XcbApplication {
public:
    AppDeBugger(int SCR_WIDTH, int SCR_HEIGHT);
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow *window);
    int	init(int SCR_WIDTH, int SCR_HEIGHT);
    ~AppDeBugger();
};


#endif // linux
#endif //MAENGINE_XCBAPPLICATION_H
