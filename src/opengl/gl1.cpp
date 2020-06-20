#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

typedef unsigned int uint;

struct ShaderProgramSource{
    std::string VertexSource;
    std::string FragmentSource;
};

const std::string SHADERS_PATH="src/opengl/res/shaders/Basic.shader";

static ShaderProgramSource ParseShader(const std::string path)
{
    std::ifstream stream(path);
    std::string line;
    enum class ShaderType {
        NONE=-1,VERTEX=0,FRAGMENT=1
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
                type=ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                //Fragment
                type=ShaderType::FRAGMENT;
            }
        }else
        {
            ss[(int)type] << line << '\n';
        }
    }
    return {ss[0].str(),ss[1].str()};
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

    //Print opengl version
    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[6] = {-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, -1.0f};

    //Create buffer
    //Buffer id
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    ShaderProgramSource source = ParseShader(SHADERS_PATH);

    std::cout << "Shaders: " <<  source.VertexSource << std::endl;
    std::cout << std::endl;
    std::cout << source.FragmentSource << std::endl;

    uint shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Legacy OpenGL
        //glBegin(GL_TRIANGLES);
        //glVertex2f(-1.0f, -1.0f);
        //glVertex2f(0.0f, 1.0f);
        //glVertex2f(1.0f, -1.0f);
        //glEnd();

        //Modern OpenGL
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}