#pragma once

#include <GL/glew.h>

#include <string>

class Shader {
  public:
    Shader(std::string vertPath, std::string fragPath);
    ~Shader();

    void useShader();

    void setUniform1f(std::string uniName, float val);

  protected:
    std::string loadFile(std::string path);
    GLuint shaderProgram;
};