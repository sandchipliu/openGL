#ifndef MODEL_H
#define MODEL_H

#include "Vertex.h"

class Model
{
private:

public:
    Vertex *vertex;
    Model(/* args */);
    ~Model();
    void update();
};

#endif