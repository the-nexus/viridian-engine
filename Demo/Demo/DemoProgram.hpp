
#pragma once

#include <memory>

#include <Graphics/Window.hpp>
#include <Runtime/Program.hpp>
#include <Runtime/ServiceManager.hpp>

namespace Viridian::Demo
{
    class DemoProgram final : public Runtime::Program
    {
    protected:
        void Start() override;
        void Stop() override;
        void Update() override;
        bool NeedsUpdate() const override;

    private:
        Runtime::ServiceManager m_serviceManager;
        std::unique_ptr<Graphics::Window> m_window = nullptr;
    };
}
