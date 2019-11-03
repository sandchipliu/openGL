#include "Object.h"

Object::Object()
{
}

Object::~Object()
{

}

void Object::enablePolygonMode(bool enable)
{
    if(enable){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//开启线框模式
    }else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//关闭线框模式
    }
}

void Object::update()
{

}