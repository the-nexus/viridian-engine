
#pragma once

namespace Viridian::Runtime
{
    class IProgram
    {
    public:
        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual void Update() = 0;
        virtual bool NeedsUpdate() const = 0;
    };

    template <typename T, typename ...Args>
    int ExecuteProgram(Args&& ...args);
}

template <typename T, typename ...Args>
int Viridian::Runtime::ExecuteProgram(Args&& ...args)
{
    T program { args... };
    
    program.Start();

    while (program.NeedsUpdate())
    {
        program.Update();
    }

    program.Stop();

    return 0;
}