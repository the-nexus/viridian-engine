
#include "DemoProgram.hpp"

using namespace Viridian::Demo;

void DemoProgram::Start()
{
    m_window = std::make_unique<Graphics::Window>();
    m_window->Open();
    
    m_startTime = clock_t::now();
    std::cout << "DEMO PROGRAM STARTED" << std::endl;
}

void DemoProgram::Stop()
{
    std::cout << "DEMO PROGRAM STOPPED" << std::endl;
}

void DemoProgram::Update()
{
    m_window->Update();

    if (m_window->IsOpened())
    {
        time_point_t const currentTime = clock_t::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_startTime).count() >= 5000U)
        {
            m_window->Close();
        }
    }
}

bool DemoProgram::NeedsUpdate() const
{
    return m_window->IsOpened();
}
