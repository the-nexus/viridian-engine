
#pragma once

#include <chrono>
#include <limits>
#include <memory>

#include <Graphics/Window.hpp>
#include <Runtime/Program.hpp>
#include <Runtime/ServiceManager.hpp>

namespace Viridian::Demo
{
    class DemoProgram final : public Runtime::Program
    {
        using clock_t = std::chrono::steady_clock;
        using time_point_t = std::chrono::time_point<clock_t>;

    protected:
        void Start() override;
        void Stop() override;
        void Update() override;
        bool NeedsUpdate() const override;

    private:
        Runtime::ServiceManager m_serviceManager;
        std::unique_ptr<Graphics::Window> m_window = nullptr;
        time_point_t m_startTime = time_point_t::min();
    };
}
