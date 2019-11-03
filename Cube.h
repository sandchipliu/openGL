#ifndef SQUARE_H
#define SQUARE_H

#include "Object.h"
#include "Texture.h"
#include "Program.h"

class Cube:public Object
{
private:
    Texture *texture0;
    Texture *texture1;
    Program *program;

public:
    Cube(Program *program);
    ~Cube();
    void update();
};


#endif