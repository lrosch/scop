#ifndef RENDERER_HPP
#define RENDERER_HPP

class Renderer{
    public:
        Renderer();
        ~Renderer();
        void render_object(GLuint vertex_array, std::vector<v3> vertices);
};

#endif