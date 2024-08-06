
#pragma once

namespace Viridian::Runtime
{
    class Program
    {
    public:
        int Execute();

    protected:
        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual void Update() = 0;
        virtual bool NeedsUpdate() const = 0;
    };
}
