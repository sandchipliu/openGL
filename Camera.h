#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

enum ECameraType{
    Perspective=0,  //正交
    Orthographic=1 //
};

class Camera
{
private:

public:
    ECameraType type;
    glm::vec3 postion;
    glm::vec3 direction;
    glm::vec3  rotation;
public:
    Camera(ECameraType type,glm::vec3 position,glm::vec3 direction,glm::vec3  rotation);
    ~Camera();
    void lookAt(glm::vec3 target);
};

#endif