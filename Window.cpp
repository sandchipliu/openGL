
#include "Window.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

Window::Window()
{
    this->createWindow();
}

Window::~Window()
{
}

bool Window::createWindow()
{
    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	this->win = glfwCreateWindow(WIN_WIDTH,WIN_HEIGHT,"test opengl",NULL,NULL);
	if(this->win == NULL){
		std::cout<<"failed to create GLFW window"<<std::endl;
		glfwTerminate();
		return false;
	}
	//通知GLFW将我们窗口的上下文设置为当前线程的主上下文
    glfwMakeContextCurrent(this->win);
    //对窗口注册一个回调函数,每当窗口改变大小，GLFW会调用这个函数并填充相应的参数供你处理
    glfwSetFramebufferSizeCallback(this->win, framebuffer_size_callback);
    //初始化GLAD用来管理OpenGL的函数指针
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    return true;
}

void Window::update(void (*func)())
{
    while(!glfwWindowShouldClose(this->win))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        func();
        processInput(this->win);
        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }
    glfwTerminate();
}