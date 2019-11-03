
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>

class Texture
{
private:
    GLuint id;
    GLenum texture;
public:
    Texture(GLenum texture);
    ~Texture();
    bool loadTexture(const char* name);
    void setParam(GLenum target, GLenum pname, GLint param);
    void setWrap(GLenum target, const GLint sParams, const GLint tParams);
    void setFilter(GLenum target, const GLint minParams, const GLint magParams);
    void activeTexure();
    void enableMipmap();
    GLuint getID();
    
};

#endif