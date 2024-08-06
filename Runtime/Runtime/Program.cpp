
#include "Runtime/Program.hpp"

using namespace Viridian::Runtime;

int Program::Execute()
{
    try
    {
        Start();

        while (NeedsUpdate())
        {
            Update();
        }

        Stop();
    }
    catch (...)
    {
        return -1;
    }

    return 0;
}
