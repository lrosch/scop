#include "../scop.hpp"

Object::Object()
{
}

Object::Object(std::string object_file)
{
    this->object_file = object_file;
    if (fill_in_from_object_file())
        exit(EXIT_FAILURE);
}

Object::~Object()
{
    glDeleteVertexArrays(1, &this->Vertex_array);
    glDeleteBuffers(1, &this->Vertex_buffer);
    glDeleteBuffers(1, &this->Element_buffer);
}

void Object::populate_buffers()
{
    // glGenVertexArrays(1, &this->Vertex_array);
    // glBindVertexArray(this->Vertex_array);
    glGenBuffers(1, &this->Vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->Vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(v3), this->vertices.data(), GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    /* this tells how to interpret the vertex data -> 0: start at vertex 0, 3: has 3 attributes (x,y,z)
       GL_FLOAT: data is float, GL_FALSE: dont normalize input, 
       sizeof(v3): has v3 many bytes so 1 vertex is v3 size
       (void*)0: specifies offset in this case 0 */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(v3), (const void *)0);
    glBindVertexArray(GL_ARRAY_BUFFER, 0);
}

int Object::fill_in_from_object_file()
{
    std::ifstream inputFile(this->object_file);
    if (!inputFile.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        std::exit(1); 
    }
    std::string line;
    std::string current_material;
    current_material = "None";
    while(std::getline(inputFile, line))
    {
        if (!line.empty())
        {
            try 
            {
                if (line[0] == 'f')
                    this->indices.push_back(create_face(line, current_material));
                else if (line[0] == 'v')
                    this->vertices.push_back(create_vector(line));
                else if (line[0] == 'o')
                    this->name = get_name_from_file(line);
                else if (line[0] == 's')
                    this->smooth_shading = get_shading_bool(line);
                else if (line.substr(0, 6) == "usemtl")
                    current_material = get_material_from_file(line);
            } catch (const std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
                inputFile.close();
                return EXIT_FAILURE;
            }
        }
    }
    /* print_faces(this->indices); /*
    print_vertices(this->vertices);
    print_shading(this->smooth_shading);
    print_name(this->name); */
    inputFile.close();
    return (0);
}