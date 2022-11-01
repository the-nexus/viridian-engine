#pragma once

class CeruleanRenderer;

class CeruleanEngine
{
public:
    ~CeruleanEngine();

    void Initialize();
    void Loop();

    bool ShouldQuit() const { return m_shouldQuit; }

private:
    CeruleanRenderer* m_renderer = nullptr;
    bool m_shouldQuit = false;
};
