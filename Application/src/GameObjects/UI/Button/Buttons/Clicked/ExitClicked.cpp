#include "ExitClicked.hpp"
#include <SpEngine/Input/Action/ExitHandler.hpp>

void ExitClicked::Clicked(int value)
{
	ExitHandler::Exit();
}
