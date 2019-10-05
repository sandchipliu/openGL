#include "Camera.h"

Camera::Camera(ECameraType type,glm::vec3 position,glm::vec3 direction,glm::vec3  rotation)
{
    this->type = type;
    this->postion = position;
    this->direction = direction;
    this->rotation = rotation;
}

Camera::~Camera()
{

}

 void Camera::lookAt(glm::vec3 target)
 {

 }
