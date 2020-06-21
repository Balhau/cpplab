#include "Renderer.h"

void Renderer::draw(const VertexArray& va,const IndexBuffer& ib, const Shader& shader) const {
  shader.Bind();
  va.Bind();
  ib.Bind();
  GLCall(glDrawElements(GL_TRIANGLES,ib.GetCount(),GL_UNSIGNED_INT,nullptr));
}
