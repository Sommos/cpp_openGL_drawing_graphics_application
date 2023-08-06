#include "Model.h"

Model::Model(const std::vector<GLfloat>& vertexPositions)
{
    // generate a vertex array object (VAO)
    glGenVertexArrays(1, &m_vao);
    // bind the VAO
    glBindVertexArray(m_vao); 
    
    // add a vertex buffer object (VBO) for the vertex positions
    addVBO(2, vertexPositions); 

    // unbind the VAO
    glBindVertexArray(0); 
    // unbind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
}

Model::~Model()
{
    // delete the VAO
    glDeleteVertexArrays(1, &m_vao); 

    // delete the VBOs
    glDeleteBuffers(m_buffers.size(), m_buffers.data()); 
}

void Model::bind()
{
    // bind the VAO for rendering
    glBindVertexArray(m_vao); 
}

void Model::unbind()
{
    // unbind the VAO
    glBindVertexArray(0); 
}

void Model::addVBO(int dim, const std::vector<GLfloat>& data)
{
    GLuint vbo;
    // generate a VBO
    glGenBuffers(1, &vbo); 
    // bind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo); 
    // copy the data to the VBO
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), data.data(), GL_STATIC_DRAW); 

    // specify the layout of the vertex attribute
    glVertexAttribPointer(m_vboCount, dim, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0); 
    // enable the vertex attribute
    glEnableVertexAttribArray(m_vboCount++); 

    // store the VBO in the list of buffers
    m_buffers.push_back(vbo); 
}
