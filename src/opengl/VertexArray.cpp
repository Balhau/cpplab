#include "VertexArray.h"
#include "utils.h"

VertexArray::VertexArray()
{
  LOG("VERTEX_ARRAY_START");
  LOG(glGenVertexArrays);
  GLCall(glGenVertexArrays(1,&m_RendererID));
  LOG("VERTEX_ARRAY_END");
}

VertexArray::~VertexArray()
{
  GLCall(glDeleteVertexArrays(1,&m_RendererID));
}

void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout& layout)
{
  vb.Bind();
  const auto &elements = layout.GetElements();
  unsigned int offset=0;
  for (unsigned int i = 0; i < elements.size(); i++)
  {
    const auto &element = elements[i];
    GLCall(glEnableVertexAttribArray(i));
    GLCall(glVertexAttribPointer(i, elements[i].count, element.type,element.normalized, layout.GetStride(), (const void*)offset));
    offset+=element.count * VertexBufferElement::GetSizeOfType(element.type); 
  }
}

void VertexArray::Bind() const
{
  GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
  GLCall(glBindVertexArray(0));
}