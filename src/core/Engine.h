#pragma once
#include "../graphics/Renderer.h"

namespace Cerulean::Core
{
    class Engine
    {
    public:
        ~Engine();

        void Initialize();
        void Loop();

        bool ShouldQuit() const { return m_shouldQuit; }

    private:
        Graphics::Renderer* m_renderer = nullptr;
        bool m_shouldQuit = false;
    };
}
