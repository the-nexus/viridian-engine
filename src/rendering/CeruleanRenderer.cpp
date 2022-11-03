#include "CeruleanRenderer.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
        if (m_glWindow)
        {
            glfwMakeContextCurrent(m_glWindow);
        }
    }
}

void CeruleanRenderer::Update()
{
    if (!m_glWindow)
    {
        return;
    }

    // int width, height;
    // glfwGetWindowSize(m_glWindow, &width, &height);
    // height = height > 0 ? height : 1;

    // glViewport(0, 0, width, height);

    // glClearColor(0.f, 0.f, 0.f, 0.f);
    // glClear(GL_COLOR_BUFFER_BIT);

    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // gluPerspective(65.f, width / height, 0.001f, 1000.f);

    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // gluLookAt(
    //     0.f, 1.f, 0.f,
    //     0.f, 20.f, 0.f,
    //     0.f, 0.f, 1.f
    // );

    // glPushMatrix();
    // glTranslatef(0.f, 10.f, 0.f);

    // glBegin(GL_TRIANGLES);
    // {
    //     glColor3f(1.f, 0.f, 0.f);
    //     glVertex3f(-5.f, 0.f, -4.f);

    //     glColor3f(0.f, 1.f, 0.f);
    //     glVertex3f(5.f, 0.f, -4.f);

    //     glColor3f(0.f, 0.f, 1.f);
    //     glVertex3f(0.f, 0.f, 6.f);
    // }
    // glEnd();

    // glPopMatrix();

    glfwSwapBuffers(m_glWindow);
    glfwPollEvents();
}

bool CeruleanRenderer::ShouldQuit() const
{
    return !m_glWindow || glfwWindowShouldClose(m_glWindow);
}
