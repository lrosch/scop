#include "../scop.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Not enough arguments" << std::endl;
        return(1);
    }
    std::string object_file = argv[1];
    if (!is_obj_file(object_file))
    {
        std::cout << "Wrong file Type" << std::endl;
        return (1);
    }
    Object object(object_file);
    Renderer renderer;
    
    if (glfwInit() == GLFW_FALSE) 
    {
        std::cout << "Failed to initialize glfw" << std::endl;
        glfwTerminate();
        return (1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(640, 480, "scop", nullptr, nullptr);
    if (!window) 
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return (1);
    }
    std::cout << "Window-creation worked properly" << std::endl;
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, escape_callback);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return (1);
    }
    std::cout << "GLAD successfully initialized" << std::endl;
    object.populate_buffers();
    while (!glfwWindowShouldClose(window))
    {
        glDrawArrays(GL_TRIANGLES, 0, object.vertices.size()); // doesnt work yet
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return (0);
}
