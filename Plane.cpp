
#include "Plane.h"


Plane::Plane(Program *program)
{
    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.0f, 2.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.0f  // top left 
    };

    unsigned int indices[] = { // 注意索引从0开始! 
        0, 1, 3, // 第一个三角形
        1, 2, 3  // 第二个三角形
    };

    this->program = program;

    this->vertex = new Vertex(vertices,sizeof(vertices));
    this->vertex->addVBO(1);
    this->vertex->addVAO(1);
   
    this->vertex->setAttrib(0,3,8*sizeof(float),(void*)0);
    this->vertex->setAttrib(1,3,8*sizeof(float),(void*)(3 * sizeof(float)));
    this->vertex->setAttrib(2,2,8*sizeof(float),(void*)(6 * sizeof(float)));

    this->vertex->addEBO(1,indices,sizeof(indices));

    this->texture0 = new Texture(GL_TEXTURE0);
	this->texture0->loadTexture("./container.jpg");
    this->texture0->setWrap(GL_TEXTURE_2D,GL_REPEAT,GL_REPEAT);
    this->texture0->setWrap(GL_TEXTURE_2D,GL_LINEAR_MIPMAP_NEAREST,GL_LINEAR);

	this->texture1 = new Texture(GL_TEXTURE1);
	this->texture1->loadTexture("./awesomeface.png");
    this->texture1->setWrap(GL_TEXTURE_2D,GL_REPEAT,GL_CLAMP_TO_EDGE);
    this->texture1->setWrap(GL_TEXTURE_2D,GL_LINEAR_MIPMAP_NEAREST,GL_LINEAR);
    // float borderColor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);


    this->program->use();// don't forget to activate/use the shader before setting uniforms!
    this->program->setInt("texture1",0);
    this->program->setInt("texture2",1);
}

Plane::~Plane()
{

}

void Plane::update()
{
    this->texture0->activeTexure();
    this->texture1->activeTexure();

    // this->program->use();
    glBindVertexArray(this->vertex->getVAO());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}