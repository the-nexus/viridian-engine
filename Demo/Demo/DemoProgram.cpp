
#include "DemoProgram.hpp"

#include <iostream>

using namespace Viridian::Demo;

void DemoProgram::Start()
{
    m_window = std::make_unique<Graphics::Window>();
    m_window->Open();

    std::cout << "DEMO PROGRAM STARTED" << std::endl;
}

void DemoProgram::Stop()
{
    std::cout << "DEMO PROGRAM STOPPED" << std::endl;
}

void DemoProgram::Update()
{
    m_window->Update();
}

bool DemoProgram::NeedsUpdate() const
{
    return m_window->IsOpened();
}
