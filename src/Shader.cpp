#include "Shader.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::string Shader::loadFile(std::string path) {
    std::ifstream f(path);
    if (!f) {
        std::cout << "Could not load file " << path << std::endl;
        return "";
    } else {
        std::stringstream ss;
        ss << f.rdbuf();
        std::string ret = ss.str();
        return ret;
    }
}

Shader::Shader(std::string vertPath, std::string fragPath) {
    auto vertStr = loadFile(vertPath);
    auto fragStr = loadFile(fragPath);

    const char *vertSrc = vertStr.c_str();
    const char *fragSrc = fragStr.c_str();

    int success;
    char infoLog[512];

    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertSrc, NULL);
    glCompileShader(vertShader);
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
        std::cout << "Vertex shader error: " << infoLog << std::endl;
    }

    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragSrc, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        std::cout << "Fragment shader error: " << infoLog << std::endl;
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Shader program error: " << infoLog << std::endl;
    }

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
}

Shader::~Shader() { glDeleteProgram(shaderProgram); }

void Shader::useShader() { glUseProgram(shaderProgram); }

void Shader::setUniform1i(std::string uniName, int val) {
    GLuint loc = glGetUniformLocation(shaderProgram, uniName.c_str());
    glUniform1i(loc, val);
}