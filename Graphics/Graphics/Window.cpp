
#include "Window.hpp"

using namespace Viridian::Graphics;

Window::~Window()
{
    if (m_isOpened)
    {
        Close();
    }
}

void Window::Open()
{
    m_isOpened = true;

    // TODO: WINDOW CREATION
}

void Window::Close()
{
    m_isOpened = false;

    // TODO: WINDOW DELETION
}

void Window::Update()
{
    if (!m_isOpened)
    {
        return;
    }

    // TODO: RENDER LOOP
}
