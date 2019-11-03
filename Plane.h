
#ifndef _PLANE_H_
#define _PLANE_H_

#include "Object.h"
#include "Texture.h"
#include "Program.h"

class Plane:public Object
{
private:
    Texture *texture0;
    Texture *texture1;
    Program *program;

public:
    Plane(Program *program);
    ~Plane();
    void update();
};

#endif