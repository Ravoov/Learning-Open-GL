#include <renderer.h>
#include <Texture.h>
#include <vertexbuffer.h>
#include <Shader.h>
#include <vertexarray.h> // Ensure this is included

int main(void)
{
    Renderer renderer;
    renderer.init(600, 600);

    // Your vertex data arrays (positions, texCoords, indices)
    float positions[] = {
         // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };

  
    unsigned int indices[] = {
        0, 1, 3,    // first triangle
        1, 2, 3     // second triangle
    };

    // Create Shader and Texture objects
    Shader ourShader("shaders/basic.vert", "shaders/basic.frag");
    ourShader.use(); // Use the shader before setting uniforms

    Texture texture("asset/asset.png");
    texture.Bind(0); // Bind to slot 0 (standard practice)
    ourShader.setInt("u_Texture", 0); // Tell shader u_Texture uses slot 0

    // --- Create VBOs for each separate array ---
    VertexBuffer positionVb(positions, sizeof(positions));
    VertexBuffer texCoordVb(texCoords, sizeof(texCoords));
    // --- End VBO creation ---

    // Create IndexBuffer
    IndexBuffer ib(indices, 6);

    // --- VAO and Vertex Attribute Setup (using your vertexArray class) ---

    // 1. Create ONE vertexArray object.
    // Its default constructor will generate and bind the VAO.
    vertexArray quadVao; 

    // 2. Add the position attribute to this VAO.
    // The AddAttribute method will ensure quadVao is bound and then configure attribute 0.
    quadVao.AddAttribute(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0, &positionVb);

    // 3. Add the texture coordinate attribute to this SAME VAO.
    // AddAttribute will again ensure quadVao is bound and then configure attribute 1.
    quadVao.AddAttribute(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0, &texCoordVb);
    
    // Unbind VAO, VBOs, and IBO after configuration (good practice)
    quadVao.Unbind();
    positionVb.Unbind(); // Unbind position VBO
    texCoordVb.Unbind(); // Unbind texture coordinate VBO
    ib.Unbind();         // Unbind IBO

    // --- End VAO and Vertex Attribute Setup ---

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(renderer.m_window))
    {
        /* Render here */
        renderer.clear();

        // Bind the shader and texture for drawing
        ourShader.use();
        texture.Bind(0); // Bind texture to slot 0

        // Bind the SINGLE VAO that contains ALL attribute configurations
        renderer.draw(quadVao, ib, ourShader); // Pass the single VAO to your renderer

        renderer.update();
    }

    // Cleanup (VBOs, IBO, and VAO will be deleted by their destructors if they are RAII classes)
    glfwTerminate();
    return 0;
}
