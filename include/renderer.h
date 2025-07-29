#pragma once 
#include <GL\glew.h>
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

class Renderer
{
public:
	void draw(const vertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void clear();
    
};