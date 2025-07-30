#pragma once 

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Shader.h"
#include "vertexarray.h"
#include "indexbuffer.h"
#pragma once

#include <iostream>
#include <GL/glew.h> // Make sure GLEW is included for GLenum etc.

// Macro for breaking into debugger (adjust for your compiler/IDE)
#ifdef _MSC_VER
#define ASSERT(x) if (!(x)) __debugbreak();
#else // For GCC/Clang
#define ASSERT(x) if (!(x)) { std::cerr << "Assertion failed: " << #x << " at " << __FILE__ << ":" << __LINE__ << std::endl; asm("int $3"); }
#endif

// Macro to clear previous OpenGL errors, execute a GL call, and then check for new errors
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

// Function prototypes
void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
class Renderer
{

    
public:
	void draw(const vertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void clear();
    void init( int width, int height);
    void update();

    GLFWwindow* m_window;
    
};