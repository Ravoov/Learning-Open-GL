#include "vertexarray.h" // Include its own header
#include <iostream> // For debug output

// Default constructor implementation
vertexArray::vertexArray()
{
    glGenVertexArrays(1, &m_Id);
    glBindVertexArray(m_Id); // Bind it immediately upon creation
    std::cout << "DEBUG: VAO " << m_Id << " created and bound in default constructor." << std::endl;
}

// Destructor
vertexArray::vertexArray()
{
    GLCall(glGenVertexArrays(1, &m_Id));
    GLCall(glBindVertexArray(m_Id));
    std::cout << "DEBUG: VAO " << m_Id << " created and bound in default constructor." << std::endl;
}

void vertexArray::AddAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer, VertexBuffer * vb)
{
    GLCall(glBindVertexArray(m_Id)); // Ensure this VAO is bound

    GLCall(vb->Bind()); // Call Bind method, which should also use GLCall internally

    GLCall(glEnableVertexAttribArray(index));
    GLCall(glVertexAttribPointer(index, size, type, normalized, stride, pointer));
    std::cout << "DEBUG: Attribute " << index << " added to VAO " << m_Id << "." << std::endl;
}


// AddAttribute method implementation
void vertexArray::AddAttribute(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer, VertexBuffer * vb)
{
    // Crucially, ensure *this* VAO is bound before adding attributes to it.
    // The default constructor already binds it, but explicit bind here makes it robust.
    glBindVertexArray(m_Id);

    // Bind the VBO associated with this attribute
    // (This VBO will be associated with the currently bound VAO)
    vb->Bind();

    // Enable the vertex attribute array at the specified index (location)
    glEnableVertexAttribArray(index);

    // Configure the vertex attribute pointer for the currently bound VAO
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);

    // It's generally okay to leave the VBO bound to GL_ARRAY_BUFFER here.
    // When the VAO is unbound, OpenGL "remembers" the VBO binding and attribute setup.
    std::cout << "DEBUG: Attribute " << index << " added to VAO " << m_Id << "." << std::endl;
}

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
