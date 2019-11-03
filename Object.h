#ifndef OBJECT_H
#define OBJECT_H

#include "Vertex.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Object
{
private:
    glm::vec3 *position;
public:
    Vertex *vertex;
    Object();
    ~Object();
    void enablePolygonMode(bool enable);
    virtual void update();
};

#endif