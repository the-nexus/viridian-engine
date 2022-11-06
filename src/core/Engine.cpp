#include "Engine.h"
#include "../graphics/Renderer.h"

using namespace Viridian;

Core::Engine::~Engine()
{
    if (m_renderer)
    {
        delete m_renderer;
    }
}

void Core::Engine::Initialize()
{
    m_renderer = new Graphics::Renderer();
    if (m_renderer->IsInitialized())
    {
        m_renderer->CreateMainWindow("Viridian Engine", 1280, 720, 100, 100);
    }
}

void Core::Engine::Loop()
{
    if (!m_renderer || m_renderer->ShouldQuit())
    {
        m_shouldQuit = true;
    }
    else if (!m_shouldQuit)
    {
        m_renderer->Update();
    }
}
