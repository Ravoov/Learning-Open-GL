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

void Renderer::init( int width, int height){

        glfwInit();
        m_window = glfwCreateWindow(width,height,"Learn Open GL",nullptr,nullptr);
        glfwMakeContextCurrent(m_window);
       glewInit();
}


void::Renderer::update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}