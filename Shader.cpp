#include "Shader.h"

Shader::Shader(GLenum shaderType,const char *path)
{
    std::string strCode = this->loadFile(path);
    if(!strCode.empty()){
        this->createByCode(shaderType,strCode.c_str());
    }
}

Shader::~Shader()
{
}

std::string Shader::loadFile(const char* path)
{
    std::string strCode = "";
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        shaderFile.open(path);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        strCode = shaderStream.str();
    }catch(std::ifstream::failure){
        std::cout<< path<<" load shader file fail" <<std::endl;
    }
    return strCode;
}

void Shader::createByCode(GLenum shaderType, const char *strShader)
{
    int success;
    char infoLog[512];
    this->id = glCreateShader(shaderType);
    glShaderSource(id,1,&strShader,NULL);
    glCompileShader(id);
    glGetShaderiv(id,GL_COMPILE_STATUS,&success);
    if(!success){
        glGetShaderInfoLog(id,sizeof(infoLog),NULL,infoLog);
        // std::cout << strShader << std::endl;
        std::cout << "compile "<< shaderType <<" shader failed! " << infoLog << std::endl;
    }
}

GLuint Shader::getID()
{
    return this->id;
}

void Shader::clear()
{
    glDeleteShader(this->id);
}