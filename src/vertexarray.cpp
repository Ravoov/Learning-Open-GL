#include "vertexarray.h" // Include its own header
#include <iostream> // For debug output

// Default constructor implementation
vertexArray::vertexArray()
{
    glGenVertexArrays(1, &m_Id);
    glBindVertexArray(m_Id); // Bind it immediately upon creation
    std::cout << "DEBUG: VAO " << m_Id << " created and bound in default constructor." << std::endl;
}

vertexArray::~vertexArray()
{
}

void vertexArray::AddAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer, VertexBuffer * vb)
{
    glBindVertexArray(m_Id); // Ensure this VAO is bound

    vb->Bind(); // Call Bind method, which should also use GLCall internally

    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    std::cout << "DEBUG: Attribute " << index << " added to VAO " << m_Id << "." << std::endl;
}


// AddAttribute method implementation


void vertexArray::Bind() const
{
    glBindVertexArray(m_Id);
    // std::cout << "DEBUG: VAO " << m_Id << " bound." << std::endl; // Optional debug print
}

void vertexArray::Unbind() const
{
    glBindVertexArray(0);
    // std::cout << "DEBUG: VAO " << m_Id << " unbound." << std::endl; // Optional debug print
}
