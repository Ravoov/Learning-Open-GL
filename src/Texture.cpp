#include "Texture.h"
#include "stb_image/stb_image.h"
#include <iostream>
#include <string>
#include <cstring>
Texture::Texture(const std::string &filePath)

    : m_FilePath(filePath),m_LocalBuffer(NULL),m_Width(0),m_height(0)
{
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filePath.c_str(), &m_Width, &m_height, &m_BPP, 0);
std::cerr << "Trying to load texture at: " << filePath << std::endl;
if (!data) {
    std::cerr << " Failed to load texture at: " << filePath << std::endl;
     std::cerr << "Error reason: " << stbi_failure_reason() << std::endl;
} else {
    std::cout << " Loaded texture: " << filePath
              << " (" << m_Width << "x" << m_height << ", " << m_BPP << " channels)\n";
}
   // m_LocalBuffer = stbi_load(filePath.c_str(), &m_Width, &m_height, &m_BPP, 4);
    
    
    
    
    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D,m_RendererID);
// Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
    glBindTexture(GL_TEXTURE_2D,0);
    if(m_LocalBuffer)
    {
        stbi_image_free(m_LocalBuffer);
    }



}

Texture::~Texture()
{
    glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0+slot);
    glBindTexture(GL_TEXTURE_2D,m_RendererID);

}

void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D,0);
}

