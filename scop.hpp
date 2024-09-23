#ifndef SCOP_H
#define SCOP_H
#define GLFW_INCLUDE_NONE
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
// #include <GL/gl.h>
//#include "C:\Sources\glfw-3.4\include\GLFW\glfw3.h"
#include "include\glad.h"
#include "include\glfw3.h"
#include "include\khrplatform.h"
#include "include\object.hpp"

void escape_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// utils.cpp
bool is_obj_file(std::string obj_file);
face create_face(std::string line, std::string material);
v3 create_vector(std::string line);
std::string get_name_from_file(std::string line);
std::string get_material_from_file(std::string line);
bool get_shading_bool(std::string line);
// print functions in utils.cpp
void print_faces(std::vector<face>& indices);
void print_shading(bool shading);
void print_vertices(std::vector<v3>& vertices);
void print_name(std::string name);
#endif
