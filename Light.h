
#ifndef LIGHT_H
#define LIGHT_H

#include "Object.h"
#include "Program.h"

class Light:public Object
{
private:
    Program *program;
    
public:
    float strength; //强度
    glm::vec3 color;//光顔色
    glm::vec3 pos;  //位置
    glm::vec3 dir;  //方向
public:
    Light(Program *program);
    ~Light();
    void setColor(glm::vec3 color);
    void setStrength(float strength);
    void update();
};

#endif