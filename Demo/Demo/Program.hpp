
#pragma once

#include <chrono>
#include <limits>
#include <memory>

#include <Graphics/Window.hpp>
#include <Runtime/Program.hpp>

namespace Viridian::Demo
{
    class Program final : public Runtime::IProgram
    {
        using clock_t = std::chrono::steady_clock;
        using time_point_t = std::chrono::time_point<clock_t>;

    public:
        void Start() override;
        void Stop() override;
        void Update() override;
        bool NeedsUpdate() const override;

    private:
        std::unique_ptr<Graphics::Window> m_window = nullptr;
        time_point_t m_startTime = time_point_t::min();
    };
}
