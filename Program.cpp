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

void Program::checkMaxVertexAttribs()
{
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum  of vertex attributes supported: " << nrAttributes << std::endl;
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

void Program::setVec3(const std::string &name, const glm::vec3 &value) const
{ 
    glUniform3fv(glGetUniformLocation(this->id, name.c_str()), 1, &value[0]); 
}

void Program::setMat4(const std::string& name, float value[]) const 
{
    glUniformMatrix4fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, value);
}

void Program::setVec3(const std::string &name, float x, float y, float z) const
{ 
    glUniform3f(glGetUniformLocation(this->id, name.c_str()), x, y, z); 
}

void Program::setVec4(const std::string &name, const glm::vec4 &value) const
{ 
    glUniform4fv(glGetUniformLocation(this->id, name.c_str()), 1, &value[0]); 
}

void Program::setVec4(const std::string &name, float x, float y, float z, float w) 
{ 
    glUniform4f(glGetUniformLocation(this->id, name.c_str()), x, y, z, w); 
}

void Program::setMat2(const std::string &name, const glm::mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Program::setMat3(const std::string &name, const glm::mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

// void Program::setMat4(const std::string &name, const glm::mat4 &mat) const
// {
//     glUniformMatrix4fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
// }
