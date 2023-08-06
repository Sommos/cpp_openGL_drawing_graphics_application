#include "Shader_Loader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace Shader
{
    // compiles a shader from source code and returns the shader ID
    GLuint compileShader(const GLchar* source, GLenum type)
    {
        auto id = glCreateShader(type); // Create a shader object of the specified type

        glShaderSource(id, 1, &source, nullptr); // Attach the shader source code to the shader object
        glCompileShader(id); // Compile the shader

        GLint isSuccess;
        GLchar infoLog[512];

        glGetShaderiv(id, GL_COMPILE_STATUS, &isSuccess); // Check if the shader compilation was successful

        if (!isSuccess)
        {
            glGetShaderInfoLog(id, 512, nullptr, infoLog); // Get the compilation error log
            throw std::runtime_error("Error compiling shader: " + std::string(infoLog)); // Throw an exception with the error message
        }

        return id; // return the shader ID
    }

    // reads the shader source code from a file and returns it as a string
    std::string getSource(const std::string& sourceFile)
    {
        // open the shader file
        std::ifstream inFile("Data/Shaders/" + sourceFile + ".glsl"); 
        std::string source;
        std::stringstream stringStream;

        if (!inFile.is_open())
        {
            // throw an exception if the file cannot be opened
            throw std::runtime_error("Could not open file: " + sourceFile); 
        }

        // read the file content into a string stream
        stringStream << inFile.rdbuf(); 
        // convert the string stream to a string
        source = stringStream.str(); 

        // return the shader source code
        return source; 
    }

    // creates a shader program using the provided vertex and fragment shaders
    GLuint createProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
    {
        // create a shader program
        auto id = glCreateProgram(); 

        // attach the vertex shader to the program
        glAttachShader(id, vertexShaderID); 
        // attach the fragment shader to the program
        glAttachShader(id, fragmentShaderID); 

        // link the shader program
        glLinkProgram(id); 

        // return the shader program ID
        return id; 
    }

    // loads and creates a shader program from vertex and fragment shader files
    GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
    {
        // get the vertex shader source code
        auto vertexSource = getSource(vertexShaderFile);
        // get the fragment shader source code
        auto fragmentSource = getSource(fragmentShaderFile); 

        // compile the vertex shader
        auto vertexShaderID = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
        // compile the fragment shader
        auto fragmentShaderID = compileShader(vertexSource.c_str(), GL_FRAGMENT_SHADER); 

        // create the shader program
        auto programID = createProgram(vertexShaderID, fragmentShaderID); 

        // delete the vertex shader object
        glDeleteShader(vertexShaderID); 
        // delete the fragment shader object
        glDeleteShader(fragmentShaderID); 

        // return the shader program ID
        return programID; 
    }
}
