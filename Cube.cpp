#include "Cube.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Cube::Cube(Program *program)
{
    GLfloat vertices[]={
        // positions          // texture coords //
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   0.0f,  0.0f, -1.0f,          
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,   0.0f,  0.0f, -1.0f,          
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   0.0f,  0.0f, -1.0f,       
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   0.0f,  0.0f, -1.0f,          
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,   0.0f,  0.0f, -1.0f,         
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,   0.0f,  0.0f, -1.0f,          
    
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   0.0f,  0.0f, 1.0f,         
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,   0.0f,  0.0f, 1.0f,          
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,   0.0f,  0.0f, 1.0f,          
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,   0.0f,  0.0f, 1.0f,          
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,   0.0f,  0.0f, 1.0f,          
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   0.0f,  0.0f, 1.0f,          
    
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   -1.0f,  0.0f, 0.0f,         
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   -1.0f,  0.0f, 0.0f,          
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   -1.0f,  0.0f, 0.0f,          
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   -1.0f,  0.0f, 0.0f,          
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   -1.0f,  0.0f, 0.0f,          
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   -1.0f,  0.0f, 0.0f,          
    
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   1.0f,  0.0f, -0.0f,         
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   1.0f,  0.0f, -0.0f,          
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   1.0f,  0.0f, -0.0f,          
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   1.0f,  0.0f, -0.0f,          
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   1.0f,  0.0f, -0.0f,          
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   1.0f,  0.0f, -0.0f,          
    
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   0.0f,  -1.0f, 0.0f,         
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,   0.0f,  -1.0f, 0.0f,          
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,   0.0f,  -1.0f, 0.0f,          
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,   0.0f,  -1.0f, 0.0f,          
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,   0.0f,  -1.0f, 0.0f,          
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,   0.0f,  -1.0f, 0.0f,          
    
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,   0.0f,  1.0f, 0.0f,         
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,   0.0f,  1.0f, 0.0f,          
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   0.0f,  1.0f, 0.0f,          
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,   0.0f,  1.0f, 0.0f,          
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,   0.0f,  1.0f, 0.0f,          
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,   0.0f,  1.0f, 0.0f
    };
    this->program = program;
    this->vertex = new Vertex(vertices,sizeof(vertices));
    this->vertex->addVAO(1);
	this->vertex->addVBO(1);
	this->vertex->setAttrib(0,3,8*sizeof(GLfloat),(void*)0);
	this->vertex->setAttrib(1,2,8*sizeof(GLfloat),(void*)(3 * sizeof(float)));
    this->vertex->setAttrib(2,3,8*sizeof(GLfloat),(void*)(5 * sizeof(float)));

    this->texture0 = new Texture(GL_TEXTURE0);
    this->texture0->setParam(GL_TEXTURE_2D,GL_REPEAT,GL_REPEAT);
    this->texture0->setFilter(GL_TEXTURE_2D,GL_LINEAR,GL_LINEAR);
	this->texture0->loadTexture("./beauty.jpg");

	this->texture1 = new Texture(GL_TEXTURE1);
    this->texture1->setParam(GL_TEXTURE_2D,GL_REPEAT,GL_REPEAT);
    this->texture1->setFilter(GL_TEXTURE_2D,GL_LINEAR,GL_LINEAR);
	this->texture1->loadTexture("./1.bmp");

    this->program->use();
    this->program->setInt("texture1",0);
    this->program->setInt("texture2",1);
    // this->enablePolygonMode(true);
}

Cube::~Cube()
{

}

void Cube::update()
{
    texture0->activeTexure();
	texture1->activeTexure();
    glm::mat4 model;
	model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
	this->program->setMat4("model", glm::value_ptr(model)); 
    glDrawArrays(GL_TRIANGLES, 0, 36);
}