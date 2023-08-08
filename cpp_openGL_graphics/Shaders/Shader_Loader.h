#ifndef SHADER_LOADER_H_INCLUDED
#define SHADER_LOADER_H_INCLUDED

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Shader
{
    GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
}
#endif