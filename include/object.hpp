#ifndef OBJECT_HPP
#define OBJECT_HPP

struct v3 
{
    float x;
    float y;
    float z;
};

struct face
{
    int indices[4];
    int count;
    std::string material;
};

class Object{
    public:
        std::string object_file;
        std::vector<v3> vertices;
        std::vector<face> indices;
        bool smooth_shading;
        std::string name;

        GLuint Vertex_array;
        GLuint Vertex_buffer;
        GLuint Element_buffer;
        std::vector<unsigned int> indexBuffer;
        
        Object();
        Object(std::string file);
        ~Object();
        int fill_in_from_object_file();
        void populate_buffers();
};

#endif