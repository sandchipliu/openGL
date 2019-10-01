#include "Program.h"
#include <iostream>

Program::Program()
{
    this->id = glCreateProgram();
    if(this->id == GL_INVALID_VALUE){
        std::cout << "program id is invald";
    }
}

Program::~Program()
{
}

GLuint Program::getID()
{
    return this->id;
}

void Program::attachShader(GLuint shader)
{
    glAttachShader(this->id,shader);
}

GLboolean Program::link()
{
    int success;
    char log[512];
    glLinkProgram(this->id);
    glGetProgramiv(this->id,GL_LINK_STATUS,&success);
    if(!success){
        glGetProgramInfoLog(this->id,sizeof(log),NULL,log);
        std::cout<<log<<std::endl;
        return GL_FALSE;
    }
    return GL_TRUE;
}

void Program::use()
{
    glUseProgram(this->id);
}

void Program::clear()
{
    glDeleteProgram(this->id);
}

void Program::setBool(const std::string& name,bool value)const
{
    glUniform1i(glGetUniformLocation(this->id,name.c_str()),(int)value);
}

void Program::setInt(const std::string& name,int value)const
{
    glUniform1i(glGetUniformLocation(this->id,name.c_str()),value);
}

void Program::setFloat(const std::string& name,float value)const
{
    glUniform1f(glGetUniformLocation(this->id,name.c_str()),value);
}

void Program::setMat4(const std::string& name, float value[]) const {
    glUniformMatrix4fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, value);
}

// void Program::setVec3(const std::string& name,float value) const{
    
// }