
#pragma once

#include <array>

namespace Viridian::Graphics
{
    class Color4f
    {
    private:
        static constexpr float FromInteger(unsigned int const value);

    public:
        constexpr Color4f(float const r, float const g, float const b, float const a = 1.f) noexcept;
        constexpr Color4f(unsigned int const r, unsigned int const g, unsigned int const b, unsigned int const a = 255u) noexcept;
        constexpr Color4f(const std::string& hex) noexcept;

        constexpr float GetRed() const noexcept;
        constexpr float GetGreen() const noexcept;
        constexpr float GetBlue() const noexcept;
        constexpr float GetAlpha() const noexcept;

        constexpr void SetRed(float const red) noexcept;
        constexpr void SetGreen(float const green) noexcept;
        constexpr void SetBlue(float const blue) noexcept;
        constexpr void SetAlpha(float const alpha) noexcept;

    private:
        std::array<float, 4> m_components = { 1.f, 1.f, 1.f, 1.f };
    };
}

#include "Color4f.inl"
