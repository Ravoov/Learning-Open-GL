#pragma once
#include "renderer.h"
#include "stb_image/stb_image.h"
class Texture
{

private:
    unsigned int m_RendererID;
    std::string m_FilePath;
    stbi_uc* m_LocalBuffer; // This is typedef’d to unsigned char by stb_image

    int m_Width,m_height;
    int m_BPP;
    
public:
Texture(const std::string& filePath);
~Texture();

void Bind(unsigned int slot = 0) const;
void Unbind() const;

inline int GetWidth() const { return m_Width; }
inline int GetHeight() const { return m_height; }

};

 
