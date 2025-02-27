#pragma once

#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>

class ExitHandler
{
public:
    ExitHandler() = default;
    static void Exit();
    static bool ShouldExit();

private:
    static bool exitGame;

};
