
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <signal.h>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

typedef unsigned int uint;

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

const std::string SHADERS_PATH = "src/opengl/res/shaders/Basic.shader";

static ShaderProgramSource ParseShader(const std::string path)
{
    std::ifstream stream(path);
    std::string line;
    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                //vertex
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                //Fragment
                type = ShaderType::FRAGMENT;
            }
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }
    return {ss[0].str(), ss[1].str()};
}

static uint CompileShader(uint type, const std::string &source)
{
    uint id = glCreateShader(type);
    std::cout << "Shader ID: " << id << std::endl;
    const char *const src = source.c_str();

    //std::cout << "Source: " << std::endl << src << std::endl << std::endl;
    glShaderSource(id, 1, &src, nullptr);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        std::cout << "Length: " << length << std::endl;
        char *message = (char *)malloc(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile "
                  << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader: " << std::endl;

        std::cout << message << std::endl;
        free(message);
        glDeleteProgram(id);
        return 0;
    }

    return id;
};

/**
 * Creates both shaders, links them and returns an identifier
 */
static uint CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    uint program = glCreateProgram();
    uint vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    uint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
};

int main(void)
{
    GLFWwindow *window;
    //glDebugMessageCallback(ErrorGLCallback,0); Enable when glew installed properly

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "OpenGL Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    //Print opengl version
    std::cout << glGetString(GL_VERSION) << std::endl;

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
    VertexArray va ;
    VertexBuffer vb(positions, 4 * 2 * sizeof(float));
    
    VertexBufferLayout layout;
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);

    IndexBuffer ib(indexes,6);
    ShaderProgramSource source = ParseShader(SHADERS_PATH);

    uint shader = CreateShader(source.VertexSource, source.FragmentSource);
    GLCall(glUseProgram(shader));

    //Find the shader uniform color
    int uniform_location = glGetUniformLocation(shader, "u_color");

    if (uniform_location == -1)
    {
        std::cout << "Error fetching uniform location" << std::endl;
    }

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

        GLCall(glUseProgram(shader));

        GLCall(glUniform4f(uniform_location, 0.2f, 0.3f, 0.8f, 1.0f));

        ib.Bind();

        GLCall(glDrawElements(GL_TRIANGLES, 6 * sizeof(uint), GL_UNSIGNED_INT, nullptr));

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