
#include <renderer.h>
#include <Texture.h>
#include <vertexbuffer.h>
int main(void)
{
    
Renderer renderer;

renderer.init(600,600);
   
float vertices[] = {
    0.5f,  0.5f, 0.0f, 0.0f,  // top right
     0.5f, -0.5f, 1.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 1.0f, 1.0f, // bottom left
    -0.5f,  0.5f, 0.0f , 1.0 // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};  





//random
float color = 0.1f;


Shader ourShader("shaders/basic.vert", "shaders/basic.frag");
ourShader.use();

Texture texture("C:/Users/numbe/Documents/Learn Open GL/src/asset.png");
texture.Bind(1);
ourShader.setInt("u_Texture",1);





VertexBuffer vb(vertices,sizeof(vertices));
vertexArray vao(0,4,GL_FLOAT,GL_FALSE,sizeof(float)* 4 , 0, &vb);
glEnableVertexAttribArray(1);
glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(sizeof(float) * 2));
IndexBuffer ib(indices , 6);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(renderer.m_window))
    {
        /* Render here */
    renderer.clear();
    renderer.draw(vao,ib,ourShader);
    texture.Bind(1);
    ourShader.setInt("u_Texture",1);
   
    color += 0.0001f;
    if(color > 1.0f) color = 0.0f;
    renderer.update();
    }
    glfwTerminate();
    return 0;
}