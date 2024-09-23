#include "../scop.hpp"

void escape_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void move_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_A && action == GLFW_PRESS)
        printf("A");
}