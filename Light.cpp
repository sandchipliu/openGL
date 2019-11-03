
#include "Light.h"

Light::Light(Program *program)
{
    this->strength = 1.0f;
    this->dir = glm::vec3(0.0f,0.0f,0.0f);
    this->color = glm::vec3(1.0f,1.0f,1.0f);
    this->pos = glm::vec3(0.0f,0.0f,-6.0f);

    this->program = program;
    this->update();
}

Light::~Light()
{

}

void Light::setColor(glm::vec3 color)
{
    this->color = color;
    this->update();
}   

void Light::setStrength(float strength)
{
    this->strength = strength;
    this->update();
}

void Light::update()
{
    this->program->use();
    this->program->setVec3("lightColor",this->color * this->strength);
    this->program->setVec3("ligthPos",this->pos);
}