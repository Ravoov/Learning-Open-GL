#pragma once 

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

class Renderer
{

    
public:
	void draw(const vertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void clear();
    void init( int width, int height);
    void update();

    GLFWwindow* m_window;
    
};