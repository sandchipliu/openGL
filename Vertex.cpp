
#include "Vertex.h"
#include <iostream>

Vertex::Vertex(GLfloat vertices[],GLuint vertexLen)
{
    this->vertices = vertices;
    this->vertexLen = vertexLen;
}

Vertex::~Vertex()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Vertex::addVAO(GLuint index)
{
    glGenVertexArrays(index,&this->VAO);
    glBindVertexArray(this->VAO);

}
    
void Vertex::addVBO(GLuint index)
{   
    glGenBuffers(index,&this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER,this->VBO);
    glBufferData(GL_ARRAY_BUFFER,this->vertexLen*sizeof(GLfloat),this->vertices,GL_STATIC_DRAW);
}

void Vertex::addEBO(GLuint index,GLuint *indices,GLuint indexLen)
{
    glGenBuffers(index,&this->EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indexLen,indices,GL_STATIC_DRAW);
}

GLuint Vertex::getVAO()
{
    return this->VAO;
}

GLuint Vertex::getVBO()
{
    return this->VBO;
}

GLuint Vertex::getEBO()
{
    return this->EBO;
}

void Vertex::setAttrib(GLuint index, GLint size,GLsizei stride, const void *ptr)
{
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index,size,GL_FLOAT,GL_FALSE,stride,ptr);
}