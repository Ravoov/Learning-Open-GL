#include <renderer.h>



void Renderer::draw(const vertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    shader.use();
    
    va.Bind();
    ib.Bind();
   
    glDrawElements(GL_TRIANGLES,ib.GetCount(),GL_UNSIGNED_INT,nullptr);
}

void::Renderer::clear()
{
     glClear(GL_COLOR_BUFFER_BIT);
}

