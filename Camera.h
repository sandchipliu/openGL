#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

enum ECameraMovement{
    FORMARD,
    BACKWARD,
    LEFT,
    RIGTH
};

const float YAW = 0.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVTY = 0.1f;
const float ZOOM = 45.0f;

class Camera
{
private:

public:
    glm::vec3 Postion;
    glm::vec3 Direction;
   
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;
public:
    Camera(glm::vec3 position,glm::vec3 direction);
    ~Camera();
};

#endif