#pragma once

#include <string>

struct ShaderProgramSource
{
  std::string VertexSource;
  std::string FragmentSource;
};

/**
 * Class to abstrac shaders
 */
class Shader
{
private:
  unsigned int m_RendererID;
  std::string m_FilePath;
  ShaderProgramSource ParseShader(const std::string &filepath);
  unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
  unsigned int CompileShader(unsigned int type, const std::string &source);
  unsigned int GetUniformLocation(const std::string &name);

public:
  Shader(const std::string &filepath);
  ~Shader();

  void Bind();
  void Unbind();

  //Set uniforms
  void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
};