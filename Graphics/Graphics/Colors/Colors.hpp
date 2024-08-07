
#pragma once

#include <array>

#include "Graphics/Colors/Color4f.hpp"

namespace Viridian::Graphics::Colors
{
    // From https://colorswall.com/palette/34517
    std::array<Color4f, 10> constexpr g_viridianPalette = {{
        { 0U, 0U, 0U },
        { 3U, 14U, 10U },
        { 6U, 29U, 21U },
        { 9U, 44U, 31U },
        { 12U, 58U, 41U },
        { 15U, 73U, 52U },
        { 18U, 87U, 62U },
        { 21U, 102U, 72U },
        { 24U, 116U, 82U },
        { 27U, 131U, 93U }
    }};
}
