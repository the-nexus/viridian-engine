#include "CeruleanEngine.h"
#include "../rendering/CeruleanRenderer.h"

CeruleanEngine::~CeruleanEngine()
{
    if (m_renderer)
    {
        delete m_renderer;
    }
}

void CeruleanEngine::Initialize()
{
    m_renderer = new CeruleanRenderer();
    if (m_renderer->IsInitialized())
    {
        m_renderer->CreateMainWindow("Cerulean Engine", 1280, 720, 100, 100);
    }
}

void CeruleanEngine::Loop()
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
