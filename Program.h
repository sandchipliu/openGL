
#ifndef _PROGRAM_H_
#define _PROGRAM_H_
#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
    void checkMaxVertexAttribs();
    void setBool(const std::string& name,bool value)const;
    void setInt(const std::string& name,int value) const;
    void setFloat(const std::string& name,float value)const;
    void setVec3(const std::string& name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setVec4(const std::string &name, float x, float y, float z, float w);
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;
    void setMat4(const std::string& name, float value[]) const;
    // void setMat4(const std::string &name, const glm::mat4 &mat) const;

};

#endif