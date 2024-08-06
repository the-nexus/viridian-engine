
#pragma once

#include <iostream>
#include <memory>

class GLFWwindow;

namespace Viridian::Graphics
{

    struct GLFWwindowDestructor
    {
        void operator()(GLFWwindow* glfwWindow);
    };

    class Window
    {
    public:
        Window();
        ~Window();

        void Open();
        void Close();
        void Update();

        bool IsOpened() const { return m_isOpened; }

    private:
        std::unique_ptr<GLFWwindow, GLFWwindowDestructor> m_glfwWindow = nullptr;
        bool m_isOpened = false;
    };
}
