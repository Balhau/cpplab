
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <signal.h>

#include "Shader.h"
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "utils.h"

const std::string SHADERS_PATH = "src/opengl/res/shaders/Basic.shader";

int main(void)
{
    LOG("Start OpenGL Demo");
    GLFWwindow *window;
    //glDebugMessageCallback(ErrorGLCallback,0); Enable when glew installed properly

    /* Initialize the library */
    LOG("Initialize glfw");
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    LOG("Create Window");
    window = glfwCreateWindow(640, 480, "OpenGL Window", NULL, NULL);
    if (!window)
    {
        LOG("Terminate because not window");
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    LOG("GLFW Make context");
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    //Print opengl version
    LOG("GL_VERSION: " << glGetString(GL_VERSION));

    float positions[] =
        {
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.5f, 0.5f,
            -0.5f, 0.5f};

    unsigned int indexes[] = {
        0, 1, 2, 2, 3, 0};

    //Create buffer
    //Buffer id

    LOG("VertexArray defining");
    VertexArray va;
    LOG("VertexArray defined");

    LOG("VertexBuffer to be created");
    VertexBuffer vb(positions, 4 * 2 * sizeof(float));
    //LOG("Create VertexBuffer: " << vb);
    
    VertexBufferLayout layout;
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);

    IndexBuffer ib(indexes,6);

    Shader shader(SHADERS_PATH);
    shader.Bind();
    shader.SetUniform4f("u_Color",0.2f, 0.3f, 0.8f, 1.0f);

    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();  

    Renderer renderer;

    float red = 0.0f;
    float increment = 0.05f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        // Legacy OpenGL
        //glBegin(GL_TRIANGLES);
        //glVertex2f(-1.0f, -1.0f);
        //glVertex2f(0.0f, 1.0f);
        //glVertex2f(1.0f, -1.0f);
        //glEnd();

        //Modern OpenGL
        //without index buffer
        //glDrawArrays(GL_TRIANGLES, 0, 12);
        //GLClearError();

        //GLCall(glUseProgram(shader));

        //GLCall(glUniform4f(uniform_location, 0.2f, 0.3f, 0.8f, 1.0f));

        //ib.Bind();

        //GLCall(glDrawElements(GL_TRIANGLES, 6 * sizeof(uint), GL_UNSIGNED_INT, nullptr));

        shader.Bind();
        shader.SetUniform4f("u_Color",red, 0.3f, 0.8f, 1.0f);

        renderer.draw(va,ib,shader);

        if (red > 1.0f)
            increment = -0.05f;
        else if (red < 0.0f)
            increment = 0.05f;
        red += increment;

        //GLCheckError();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    
    return 0;
}
