#include "Texture.h"
#include "stb_image.h"
#include <iostream>

Texture::Texture(GLenum texture)
{
    this->texture = texture;
    glGenTextures(1,&this->id);
    glActiveTexture(texture);
    glBindTexture(GL_TEXTURE_2D,this->id);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

Texture::~Texture()
{
}

GLuint Texture::getID()
{
    return this->id;
}

bool Texture::loadTexture(const char* name)
{
    int width,height,nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(name,&width,&height,&nrChannels,0);
    GLint format = nrChannels == 3 ? GL_RGB : GL_RGBA;
    if(data){
        glTexImage2D(GL_TEXTURE_2D,0,format,width,height,0,format,GL_UNSIGNED_BYTE,data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        std::cout << "load imager failed" << std::endl;
        return false;
    }
    stbi_image_free(data);
    return true;
}

void Texture::activeTexure()
{
    glActiveTexture(this->texture);
    glBindTexture(GL_TEXTURE_2D,this->id);
}