
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
    void activeTexure();
    GLuint getID();
    
};

#endif