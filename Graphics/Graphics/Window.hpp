
#pragma once

#include <array>
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
        static void OnGlfwWindowResized(GLFWwindow* glfwWindow, int const width, int const height);

        Window();
        ~Window();

        void Open();
        void Close();
        void Update();

        bool IsOpened() const { return m_isOpened; }

    private:
        std::unique_ptr<GLFWwindow, GLFWwindowDestructor> m_glfwWindow = nullptr;
        std::array<int, 2> m_size = { 800, 600 };
        bool m_isOpened = false;
    };
}
