#include "core/Engine.h"
#include <iostream>

int main()
{
    Cerulean::Core::Engine engine;

    engine.Initialize();
    while (!engine.ShouldQuit())
    {
        engine.Loop();
    }

    return 0;
}