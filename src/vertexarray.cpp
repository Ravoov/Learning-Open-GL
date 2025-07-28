#include "vertexarray.h"
// No need to include GLEW/GLFW again if vertexarray.h already includes them,
// but it doesn't hurt. Ensure it's done somewhere.

vertexArray::vertexArray(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer,VertexBuffer * vb )
{
    glGenVertexArrays(1, &m_Id); // Generate the VAO ID and store it in m_Id
    glBindVertexArray(m_Id);    // Bind the VAO
    


    vb->Bind();

    // The 'index' parameter passed to the constructor is the attribute index
    glEnableVertexAttribArray(index); // CORRECT: Use the 'index' for enabling

    // Configure the vertex attribute pointer for the currently bound VAO
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void vertexArray::Bind() // Corrected return type
{
    glBindVertexArray(m_Id);
}

void vertexArray::Unbind() // Corrected return type
{
    glBindVertexArray(0); // CORRECT: Unbind by binding to 0
}

vertexArray::~vertexArray()
{
    glDeleteVertexArrays(1, &m_Id); // CORRECT: Pass address of m_Id
}