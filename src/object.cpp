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
    // print_faces(this->indices);
    // print_vertices(this->vertices);
    // print_shading(this->smooth_shading);
    // print_name(this->name);
    inputFile.close();
    return (0);
}