#pragma once

struct GLFWwindow;

namespace Viridian::Graphics
{
    class Renderer
    {
    public:
        Renderer();
        ~Renderer();

        void CreateMainWindow(char const* title, int const width, int const height, int const posX, int const posY);
        void Update();

        bool IsInitialized() const { return m_glInitialized; }
        bool ShouldQuit() const;

    private:
        GLFWwindow* m_glWindow = nullptr;
        bool m_glInitialized = false;
    };
}
