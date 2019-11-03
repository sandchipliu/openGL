#include "Camera.h"

Camera::Camera(Program *program, glm::vec3 position)
{
    this->program = program;
    this->postion = position;
    // this->rotation = rotation;

    this->view = glm::translate(this->view,postion);
    // this->view = glm::rotate(this->view,)
    program->setMat4("view", glm::value_ptr(this->view));
}

Camera::~Camera()
{

}

glm::mat4 Camera::Perspective(float fovy,float ascpt,float near,float far)
{
    // this->eProjection = EProjection.Perspective;
    this->projection = glm::perspective(fovy,ascpt,near,far);
    this->program->setMat4("projection", glm::value_ptr(this->projection));
    return this->projection;
}

glm::mat4 Camera::Ortho(float left,float right,float buttom,float top)
{
    this->projection = glm::ortho(left,right,buttom,top);
    this->program->setMat4("projection", glm::value_ptr(this->projection));
    return this->projection;
}

