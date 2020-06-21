#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "Shader.h"
#include "Renderer.h"
#include "utils.h"

Shader::Shader(const std::string &filepath)
    : m_FilePath(filepath), m_RendererID(0)
{
  ShaderProgramSource source = ParseShader(m_FilePath);
  m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader()
{
}

void Shader::Bind() const
{
  GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const
{
  GLCall(glUseProgram(0));
}

//Set uniforms
void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3)
{
  GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}
unsigned int Shader::GetUniformLocation(const std::string &name)
{
  if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
    return m_UniformLocationCache[name];

  GLCall(unsigned int location = glGetUniformLocation(m_RendererID, name.c_str()));

  if (location == -1)
    LOG("Warning: uniform" << name << " doesn't exist");

  m_UniformLocationCache[name] = location;
  return location;
}

/**
 * Creates both shaders, links them and returns an identifier
 */
unsigned int Shader::CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
  unsigned int program = glCreateProgram();
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return program;
}

unsigned int Shader::CompileShader(unsigned int type, const std::string &source)
{
  unsigned int id = glCreateShader(type);
  LOG("Shader ID: " << id);
  const char *const src = source.c_str();
  LOG("Source: " << std::endl
                 << src << std::endl);
  glShaderSource(id, 1, &src, nullptr);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);

  if (result == GL_FALSE)
  {
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

    LOG("Length: " << length);

    char *message = (char *)malloc(length * sizeof(char));
    glGetShaderInfoLog(id, length, &length, message);

    LOG("Failed to compile "
        << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader: " << std::endl);

    LOG(message);
    free(message);
    glDeleteProgram(id);
    return 0;
  }
  return id;
}

ShaderProgramSource Shader::ParseShader(const std::string &path)
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