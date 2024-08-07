
#include <ratio>

namespace Viridian::Graphics
{
    constexpr float Color4f::FromInteger(unsigned int const value)
    {
        constexpr float conversionRatio = 1.f / 255.f;
        return static_cast<float>(value) * conversionRatio;
    }

    constexpr Color4f::Color4f(float const r, float const g, float const b, float const a) noexcept
        : m_components({ r, g, b, a })
    {}

    constexpr Color4f::Color4f(unsigned int const r, unsigned int const g, unsigned int const b, unsigned int const a) noexcept
        : m_components({ FromInteger(r), FromInteger(g), FromInteger(b), FromInteger(a) })
    {}

    constexpr Color4f::Color4f(const std::string& hex) noexcept
        : m_components({})
    {}

    constexpr float Color4f::GetRed() const noexcept { return m_components[0]; }
    constexpr float Color4f::GetGreen() const noexcept { return m_components[1]; }
    constexpr float Color4f::GetBlue() const noexcept { return m_components[2]; }
    constexpr float Color4f::GetAlpha() const noexcept { return m_components[3]; }

    constexpr void Color4f::SetRed(float const red) noexcept { m_components[0] = red; }
    constexpr void Color4f::SetGreen(float const green) noexcept { m_components[1] = green; }
    constexpr void Color4f::SetBlue(float const blue) noexcept { m_components[2] = blue; }
    constexpr void Color4f::SetAlpha(float const alpha) noexcept { m_components[3] = alpha; }
}
