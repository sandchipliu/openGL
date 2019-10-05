
#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <glad/glad.h>

class Vertex
{
private:
    GLuint vertexLen;
    GLfloat *vertices;
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
public:
    Vertex(GLfloat vertices[],GLuint vertexLen);
    ~Vertex();
    GLuint getVAO();
    GLuint getVBO();
    GLuint getEBO();
    void showMaxVertexAttribs();
    void addVAO(GLuint index);
    void addVBO(GLuint index);
    void addEBO(GLuint index,GLuint *indices,GLuint indexLen);
    void setAttrib(GLuint index, GLint size,GLsizei stride, const void *ptr);
};



#endif