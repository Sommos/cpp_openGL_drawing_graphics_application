#ifndef SHADER_PROGRAM_H_INCLUDED
#define SHADER_PROGRAM_H_INCLUDED

#include "Shader_Loader.h"
#include <GL/glew.h>
#include <string>

namespace Shader
{
    class Shader_Program
    {
        public:
            Shader_Program(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
            ~Shader_Program();
            void bind();
            void unbind();

        private:
            GLuint m_programID;
    };
}
#endif