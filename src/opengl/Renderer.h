#pragma once

//Force the compilation process to statically link glew
#define GLEW_STATIC

#include "glew.h"
#include <GLFW/glfw3.h>
#include <csignal>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
  void draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const;
};