
#include "GraphicsService.hpp"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace Viridian::Graphics;

GraphicsService::GraphicsService()
{
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "[GraphicsService::GraphicsService] Failed to initialize GLAD" << std::endl;
        return;
    }   
}

GraphicsService::~GraphicsService()
{
    glfwTerminate();
}
