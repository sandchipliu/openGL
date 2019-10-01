
#ifndef _WINDOW_H_
#define _WINDOW_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define WIN_WIDTH 480
#define WIN_HEIGHT 320

class Window
{
private:
    /* data */
    GLFWwindow *win;
    bool createWindow();
public:
    Window(/* args */);
    ~Window();
    void loop(void (*func)());
};

#endif