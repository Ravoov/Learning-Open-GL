
#include <renderer.h>
int main(void)
{
    
Renderer renderer;

renderer.init(600,600);
   
float vertices[] = {
    0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};  

float color = 0.1f;

Shader ourShader("shaders/basic.vert", "shaders/basic.frag");
ourShader.use();

VertexBuffer vb(vertices,sizeof(vertices));
vertexArray vao(0,3,GL_FLOAT,GL_FALSE,sizeof(float)* 3 , 0, &vb);

IndexBuffer ib(indices , 6);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(renderer.m_window))
    {
        /* Render here */
    renderer.clear();
    renderer.draw(vao,ib,ourShader);
    ourShader.setFloat("u_Color",1.0f,color,color,1.0f);
    color += 0.0001f;
    if(color > 1.0f) color = 0.0f;
    renderer.update();
    }
    glfwTerminate();
    return 0;
}