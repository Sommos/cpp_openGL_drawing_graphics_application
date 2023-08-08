#include "Shader_Program.h"
#include "Shader_Loader.h"

namespace Shader
{
    // constructor that loads and creates a shader program using the provided vertex and fragment shader files
    Shader_Program::Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
        : m_programID(loadShader(vertexShaderFile, fragmentShaderFile))
    {
        // the shader program ID is initialized by calling the loadShader() function from Shader_Loader.h
    }

    // destructor that deletes the shader program
    Shader_Program::~Shader_Program()
    {
        // delete the shader program object
        glDeleteProgram(m_programID); 
    }

    // binds the shader program for rendering
    void Shader_Program::bind()
    {
        // use the shader program for rendering
        glUseProgram(m_programID); 
    }

    // unbinds the shader program
    void Shader_Program::unbind()
    {
        // stop using any shader program (unbind)
        glUseProgram(0); 
    }
}
