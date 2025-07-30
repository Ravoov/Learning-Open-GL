#pragma once
#include "renderer.h" // Assuming this includes necessary GL/GLFW headers
#include "vertexbuffer.h" // Need VertexBuffer definition

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
    // This replaces the old constructor's attribute setup logic
    void AddAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer, VertexBuffer * vb);

    // Bind and Unbind methods remain the same
    void Bind() const;
    void Unbind() const;
};
