#include "Renderer.h"
#include <iostream>

//Discard error flags from openGL state machine
void GLClearError()
{
  while (glGetError() != GL_NO_ERROR)
    ;
}

bool GLLogCall(const char *function, const char *file, int line)
{
  while (GLenum error = glGetError())
  {
    std::cout << "[OpenGL error] ("
              << error << "): " << function << " "
              << file << ":" << line << std::endl;
    return true;
  }
  return false;
} 

void ErrorGLCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
  std::cout << "Source: " << source << "Type: " << type << "Id: " << id << "Severity: " << severity << "Length: " << length << message << std::endl;
}