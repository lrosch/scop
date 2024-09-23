#include "../scop.hpp"

bool is_obj_file(std::string obj_file)
{
  if(obj_file.substr(obj_file.find_last_of(".") + 1) == "obj") 
    return (true);
  else 
    return (false);
}

face create_face(std::string line, std::string material)
{
  std::istringstream iss(line);
  std::string prefix;
  std::vector<int> values;
  face return_face;
  int value;

  iss >> prefix;
  while(iss >> value)
    values.push_back(value);
  if (values.size() == 3)
  {
    return_face.a = values[0];
    return_face.b = values[1];
    return_face.c = values[2];
  }
  else if (values.size() == 4)
  {
    return_face.a = values[0];
    return_face.b = values[1];
    return_face.c = values[2];
    return_face.d = values[3];
    return_face.fourth_val = true;
  }
  else
    throw std::runtime_error("Invalid input format. Expected 3 or 4 values.");
  return_face.material = material;
  return (return_face);
}

v3 create_vector(std::string line)
{
  v3 return_vector;
  std::istringstream iss(line);
  std::string prefix;
  std::vector<float> values;
  float value;

  iss >> prefix;
  while(iss >> value)
    values.push_back(value);

  if (values.size() == 3)
  {
    return_vector.x = values[0];
    return_vector.y = values[1];
    return_vector.z = values[2];
  }
  else
    throw std::runtime_error("Invalid input format. Expected 3 values.");
  return (return_vector);
}

std::string get_name_from_file(std::string line)
{
  std::string name;
  std::string prefix;
  std::string value;
  std::istringstream iss(line);

  iss >> prefix;
  iss >> name;
  return (name);
}

bool get_shading_bool(std::string line)
{
  bool shading = false;
  std::string material;
  std::string prefix;
  std::string value;
  std::istringstream iss(line);

  iss >> prefix;
  iss >> value;

  if (value == "true" || value == "TRUE")
    shading = true;

  return (shading);
}

std::string get_material_from_file(std::string line)
{
  std::string material;
  std::string prefix;
  std::string value;
  std::istringstream iss(line);

  iss >> prefix;
  iss >> material;
  return(material);
} 

void print_faces(std::vector<face>& indices) {
    for (const auto& f : indices) {
        std::cout << "face: " << "a: " << f.a << ", b: " << f.b << ", c: " << f.c << ", d: " << f.d
                  << ", fourth_val: " << (f.fourth_val ? "true" : "false")
                  << ", material: " << f.material << std::endl;
    }
}

void print_vertices(std::vector<v3>& vertices) {
    for (const auto& v : vertices)
        std::cout << "vertice: " << "a: " << v.x << ", b: " << v.y << ", c: " << v.z << std::endl;
}

void print_shading(bool shading)
{
  std::cout << "shading: " << (shading ? "true" : "false") << std::endl;
}

void print_name(std::string name)
{
  std::cout << "name: " << name << std::endl;
}