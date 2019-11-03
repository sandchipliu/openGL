#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Program.h"

enum EProjection{
    Perspective=0,  //正交
    Orthographic=1 //
};

class Camera
{
private:
    Program* program;
    glm::vec3 postion;
    glm::vec3 rotation;
public:
    EProjection eProjection;
    glm::mat4 view;
    glm::mat4 projection;

private:
    
public:
    Camera(Program *program, glm::vec3 position);
    glm::mat4 Perspective(float fovy,float ascpt,float near,float far);
    glm::mat4 Ortho(float left,float right,float buttom,float top);
    ~Camera();
};

#endif