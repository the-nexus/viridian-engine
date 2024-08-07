
#include "Window.hpp"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Graphics/Colors/Colors.hpp"

using namespace Viridian::Graphics;

void GLFWwindowDestructor::operator()(GLFWwindow* glfwWindow)
{
    glfwDestroyWindow(glfwWindow);
}

void Window::OnGlfwWindowResized(GLFWwindow* glfwWindow, int const width, int const height)
{
    glfwMakeContextCurrent(glfwWindow);
    glViewport(0, 0, width, height);
}

Window::Window()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "[Window::Open] Failed to initialize GLAD" << std::endl;
        return;
    }

    glViewport(0, 0, m_size[0], m_size[1]);
    glfwSetFramebufferSizeCallback(m_glfwWindow.get(), Window::OnGlfwWindowResized);

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

    glfwGetFramebufferSize(m_glfwWindow.get(), &m_size[0], &m_size[1]);

    Color4f constexpr clearColor = Colors::g_viridianPalette[1];
    glClearColor(clearColor.GetRed(), clearColor.GetGreen(), clearColor.GetBlue(), clearColor.GetAlpha());
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(m_glfwWindow.get());
    glfwPollEvents();
}
