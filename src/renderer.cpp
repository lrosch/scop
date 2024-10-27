#include "../scop.hpp"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::render_object(GLuint vertex_array, std::vector<v3> vertices)
{
    glBindVertexArray(vertex_array);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    glBindVertexArray(0);
}