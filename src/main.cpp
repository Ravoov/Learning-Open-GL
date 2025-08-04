#include <renderer.h>
#include <Texture.h>
#include <vertexbuffer.h>
#include <Shader.h>
#include <vertexarray.h>

// Include the header with GLCall macro (if it's in a separate file like debug_utils.h)
// #include "debug_utils.h" // Uncomment if you made a separate debug_utils.h

int main(void)
{
    Renderer renderer;
    renderer.init(600, 600);

 
    float positions[] = {
        // Position (X, Y, Z)   Texture Coordinate (U, V)
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, // Vertex 0: bottom left
         0.5f, -0.5f, -0.5f,    1.0f, 0.0f, // Vertex 1: bottom right
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f, // Vertex 2: top right
        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f  // Vertex 3: top left
    };

    unsigned int indices[] = {
        0, 1, 3,    // first triangle (V0, V1, V3)
        1, 2, 3     // second triangle (V1, V2, V3)
    };

    //std::cout << "Creating shader..." << std::endl;
    Shader ourShader("shaders/basic.vert", "shaders/basic.frag");
    //std::cout << "Shader created. Using shader." << std::endl;
    ourShader.use();
    GLint texCoordLocation = glGetAttribLocation(ourShader.ID, "aTexCoord"); // No GLCall here, it's just a getter
    if (texCoordLocation == -1) {
        std::cerr << "ERROR: Attribute 'aTexCoord' not found in shader program!" << std::endl;
    } 
    //creats texture
    //std::cout << "Creating texture..." << std::endl;
    Texture texture("asset/asset.png"); // Make sure this path is correct!
    //std::cout << "Texture created. Binding texture." << std::endl;
    texture.Bind(0); // Bind to slot 0 (standard practice)
    ourShader.setInt("u_Texture", 0); // Tell shader u_Texture uses slot 0

    VertexBuffer interleavedVb(positions, sizeof(positions)); 
    // --- End VBO creation ---
    // Create IndexBuffe
    //std::cout << "Creating IndexBuffer..." << std::endl;
    IndexBuffer ib(indices, 6);
    // --- VAO and Vertex Attribute Setup (using your vertexArray class) ---
   // std::cout << "Creating VAO..." << std::edl;
    vertexArray quadVao; 
    // Stride is now the size of ONE complete vertex (X, Y, Z, U, V)
    GLsizei vertexStride = sizeof(float) * 5; // 5 floats per vertex (3 for position, 2 for texCoord)

    //std::cout << "Adding position attribute (location 0) to VAO..." << std::endl;
    quadVao.AddAttribute(0, 3, GL_FLOAT, GL_FALSE, vertexStride, (void*)0, &interleavedVb);
    //std::cout << "Adding texture coordinate attribute (location 1) to VAO..." << std::endl;
    quadVao.AddAttribute(1, 2, GL_FLOAT, GL_FALSE, vertexStride, (void*)(sizeof(float) * 3), &interleavedVb);
    
    // Unbind VAO, VBO, and IBO after configuration (good practice)
   // std::cout << "Unbinding VAO, VBO, IBO..." << std::endl;
    quadVao.Unbind();
    interleavedVb.Unbind(); // Unbind the single interleaved VBO
    ib.Unbind();         // Unbind IBO



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

    //std::cout << "Exiting application." << std::endl;
    glfwTerminate();
    return 0;
}
