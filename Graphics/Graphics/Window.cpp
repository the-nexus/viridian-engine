
#include "Window.hpp"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace Viridian::Graphics;

void GLFWwindowDestructor::operator()(GLFWwindow* glfwWindow)
{
    glfwDestroyWindow(glfwWindow);
}

Window::Window()
{
    m_glfwWindow = std::unique_ptr<GLFWwindow, GLFWwindowDestructor> { glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr) };
    if (!m_glfwWindow)
    {
        std::cerr << "[Window::Window] GLFW window does not exist" << std::endl;
        return;
    } 
}

Window::~Window()
{
    if (m_isOpened)
    {
        Close();
    }
}

void Window::Open()
{
    if (!m_glfwWindow)
    {
        std::cerr << "[Window::Open] GLFW window does not exist" << std::endl;
        return;
    }
    
    glfwMakeContextCurrent(m_glfwWindow.get());
    
    m_isOpened = true;
}

void Window::Close()
{
    m_glfwWindow.reset();
    m_isOpened = false;
}

void Window::Update()
{
    if (!m_isOpened)
    {
        return;
    }

    if (glfwWindowShouldClose(m_glfwWindow.get()))
    {
        Close();
        return;
    }

    // TODO: RENDER LOOP
}
