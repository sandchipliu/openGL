#include "Camera.h"

Camera::Camera(glm::vec3 position,glm::vec3 direction)
{
    this->Postion = position;
    this->Direction = direction;
}

Camera::~Camera()
{

}
