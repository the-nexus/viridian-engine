#include "core/CeruleanEngine.h"

#include <iostream>

int main()
{
    CeruleanEngine engine;
    engine.Initialize();
    while (!engine.ShouldQuit())
    {
        engine.Loop();
    }
    return 0;
}