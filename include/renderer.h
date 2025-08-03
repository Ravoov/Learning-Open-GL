#pragma once 

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Shader.h"
#include "vertexarray.h"
#include "indexbuffer.h"

#include <iostream>
#include <GL/glew.h> 
// Make sure GLEW is included for GLenum etc.

class Renderer
{
private:
    unsigned int m_width, m_height;
    bool m_isRunning;
    \
public:
	void draw(const vertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void clear();
    void init( int width, int height);
    void update();
    GLFWwindow* m_window;
    
};