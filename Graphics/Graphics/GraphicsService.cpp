
#include "GraphicsService.hpp"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace Viridian::Graphics;

GraphicsService::GraphicsService()
{
    glfwInit();
}

GraphicsService::~GraphicsService()
{
    glfwTerminate();
}
