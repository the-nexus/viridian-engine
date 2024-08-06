
#pragma once

#include <iostream>

namespace Viridian::Graphics
{
    class Window
    {
    public:
        Window() = default;
        ~Window();

        void Open();
        void Close();
        void Update();

        bool IsOpened() const { return m_isOpened; }

    private:
        bool m_isOpened = false;
    };
}
