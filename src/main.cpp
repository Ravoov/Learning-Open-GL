#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Shader.h>
#include <iostream>
#include <vertexbuffer.h>
#include <indexbuffer.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
   
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glewInit();


 Shader ourShader("shaders/basic.vert", "shaders/basic.frag");
    ourShader.use();
    ourShader.setFloat("u_Color",1.0f,1.5f,0.0f,1.0f);




    //positon for floats
   
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

float texCoords[] = {
    0.0f, 0.0f,  // lower-left corner  
    0.0f,0.5f,
    0.5,0.5,
    0.0,0.5
    // top-center corner
};
   
unsigned int vao;
glGenVertexArrays(1,&vao);
glBindVertexArray(vao);



VertexBuffer vb(vertices,sizeof(vertices));

glEnableVertexAttribArray(0);
glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,0);

IndexBuffer ib(indices , 6);




    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        
    ib.Bind();
    vb.Bind();
    // Bind VAO and draw
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}