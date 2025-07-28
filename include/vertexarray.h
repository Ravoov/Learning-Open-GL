#pragma once 
#include<GL/glew.h>
#include"vertexbuffer.h"
class vertexArray
{
private:
    unsigned int m_Id;
public:
    vertexArray(GLuint index,GLint size,GLenum type,GLboolean normalized,GLsizei stride,const GLvoid * pointer, VertexBuffer * vb);
    ~vertexArray();

    void Bind();
    void Unbind();

};
