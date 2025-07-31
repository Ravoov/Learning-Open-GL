#include "Texture.h"
#include <iostream>
#include <string>
#include <cstring> // For memset if needed, though not directly used here

// Make sure you have included stb_image.h somewhere, usually in Texture.h
// #define STB_IMAGE_IMPLEMENTATION // Only in ONE .cpp file, often here or main.cpp
// #include "stb_image.h" // Include the stb_image header

Texture::Texture(const std::string &filePath)
    : m_FilePath(filePath), m_LocalBuffer(NULL), m_Width(0), m_height(0), m_BPP(0), m_RendererID(0) // Initialize m_BPP and m_RendererID
{
    stbi_set_flip_vertically_on_load(true); // Flip textures vertically for OpenGL

    // Load the image data ONCE directly into m_LocalBuffer
    m_LocalBuffer = stbi_load(filePath.c_str(), &m_Width, &m_height, &m_BPP, 4); // Force 4 channels (RGBA)

    // Check if loading was successful immediately
    if (!m_LocalBuffer) {
        std::cerr << "ERROR: Failed to load texture: " << filePath << std::endl;
        std::cerr << "stb_image error: " << stbi_failure_reason() << std::endl;
        // No need for a second stbi_failure_reason() print
        // You might want to handle this error more gracefully, e.g., load a default texture
        return; // Exit constructor if loading failed
    }

    std::cout << "Loaded texture: " << filePath
              << " (" << m_Width << "x" << m_height << ", " << m_BPP << " channels)\n";
    
    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // Use CLAMP_TO_EDGE for non-tiling images
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Prevents issues if UVs go slightly out of 0-1 range
    
    // Set texture filtering parameters
    // GL_LINEAR_MIPMAP_LINEAR requires mipmaps to be generated
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload the texture data to the GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
    
    // Generate mipmaps AFTER glTexImage2D
    glGenerateMipmap(GL_TEXTURE_2D);

    // Unbind the texture after configuration
    glBindTexture(GL_TEXTURE_2D, 0);

    // Free the local CPU buffer after uploading to GPU
    stbi_image_free(m_LocalBuffer);
    m_LocalBuffer = NULL; // Set to NULL to prevent double-free or dangling pointer
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
