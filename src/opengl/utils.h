#pragma once
#include <iostream>
#include <GL/glew.h> 
#include <csignal>

#if IS_DEBUG==1
  #define LOG(x) std::cout << x << std::endl
#else
  #define LOG(x)
#endif

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
void GLPrintVersion();
bool GLLogCall(const char *function, const char *file, int line);
//This is just for OpenGL4.3 onwards
void ErrorGLCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);