#ifndef SQUARE_H
#define SQUARE_H

#include "Model.h"
#include "Texture.h"

class Square:public Model
{
private:
    Texture *texture0;
    Texture *texture1;
public:
    Square(/* args */);
    ~Square();
    void update();
};


#endif