#include "ExitHandler.hpp"

#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

bool ExitHandler::exitGame = false;

void ExitHandler::Exit()
{
    exitGame = true;
}

bool ExitHandler::ShouldExit()
{
    return exitGame;
}

