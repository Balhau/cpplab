#pragma once

//Force the compilation process to statically link glew
#define GLEW_STATIC

#include "glew.h"
#include <GLFW/glfw3.h>
#include <csignal>


//This should be review to integrate with debugger
#define ASSERT(x) \
  if (!(x))       \
  std::raise(SIGTRAP)

#define GLCall(x) \
  GLClearError(); \
  x;              \
  ASSERT(GLLogCall(#x, __FILE__, __LINE__))

//Discard error flags from openGL state machine
void GLClearError();
bool GLLogCall(const char *function, const char *file, int line);
//This is just for OpenGL4.3 onwards
void ErrorGLCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);