
#ifndef _SHADER_H_
#define _SHADER_H_

#include <glad/glad.h>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>

class Shader
{
private:
    GLuint id;
    std::string loadFile(const char*path);
public:
    Shader(GLenum shaderType,const char *path);
    ~Shader();
    GLuint getID();
    void createByCode(GLenum shaderType,const char*strShader);
    void clear();
};

#endif