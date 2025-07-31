#pragma once 

// Explicitly include GLEW for OpenGL types (GLuint, GLenum, etc.)
#include <GL/glew.h> 

// Include VertexBuffer definition, as vertexArray uses VertexBuffer pointers
#include "vertexbuffer.h" 

class vertexArray
{
private:
    unsigned int m_Id; // VAO ID

public:
    // Default constructor: Generates and binds the VAO
    vertexArray();

    // Destructor
    ~vertexArray();

    // Method to add an attribute to this *already bound* VAO
    void AddAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer, VertexBuffer * vb);

    // Bind and Unbind methods
    void Bind() const;
    void Unbind() const;
};
