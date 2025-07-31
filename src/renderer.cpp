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
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::init( int width, int height){

        glfwInit();
        m_window = glfwCreateWindow(width,height,"Learn Open GL",nullptr,nullptr);
        glfwMakeContextCurrent(m_window);
       glewInit();
       glViewport(0, 0, width, height);

}


void::Renderer::update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}