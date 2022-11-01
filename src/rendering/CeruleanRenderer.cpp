#include "CeruleanRenderer.h"

#include <GLFW/glfw3.h>
#include <iostream>

CeruleanRenderer::CeruleanRenderer()
{
    if (glfwInit())
    {
        m_glInitialized = true;
    }
}

CeruleanRenderer::~CeruleanRenderer()
{
    if (m_glWindow)
    {
        glfwDestroyWindow(m_glWindow);
    }

    glfwTerminate();
}

void CeruleanRenderer::CreateMainWindow(char const* title, int const width, int const height, int const posX, int const posY)
{
    if (!m_glWindow)
    {
        m_glWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    }
}

void CeruleanRenderer::Update()
{
    if (m_glWindow)
    {
        glfwSwapBuffers(m_glWindow);
        glfwPollEvents();
    }
}

bool CeruleanRenderer::ShouldQuit() const
{
    return !m_glWindow || glfwWindowShouldClose(m_glWindow);
}
