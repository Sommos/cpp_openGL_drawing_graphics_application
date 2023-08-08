#include "Shader_Program.h"

namespace Shader
{
    // constructor that loads and creates a shader program using the provided vertex and fragment shader files
    Shader_Program::Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
        : m_programID(loadShader(vertexShaderFile, fragmentShaderFile))
    {
        // the shader program ID is initialized by calling the loadShader() function from Shader_Loader.h
    }

    Shader_Program::~Shader_Program()
    {
        glDeleteProgram(m_programID); 
    }

    void Shader_Program::bind()
    {
        glUseProgram(m_programID); 
    }

    void Shader_Program::unbind()
    {
        glUseProgram(0); 
    }
}