
#ifndef _PROGRAM_H_
#define _PROGRAM_H_
#include <glad/glad.h>
#include <string>

class Program
{
private:
    GLuint id;

public:
    Program();
    ~Program();
    GLuint getID();
    void attachShader(GLuint shader);
    GLboolean link();
    void clear();
    void use();
    void setBool(const std::string& name,bool value)const;
    void setInt(const std::string& name,int value) const;
    void setFloat(const std::string& name,float value)const;
    void setMat4(const std::string& name, float value[]) const;
};

#endif