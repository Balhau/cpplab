#pragma once
#include <iostream>

class VertexBuffer
{
private:
  unsigned int m_RendererID;

public:
  VertexBuffer(const void* data, unsigned int size);
  ~VertexBuffer();

  void Bind() const;
  void Unbind() const;

  //Overload to enable toString operations
  friend std::ostream& operator<<(std::ostream &stream, VertexBuffer const &vb){
        return stream << "[VertexBuffer rendererID=" << vb.m_RendererID;
  }
};

