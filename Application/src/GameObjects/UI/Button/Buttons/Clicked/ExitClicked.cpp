#include "ExitClicked.hpp"
#include <SpEngine/Input/Action/ExitHandler.hpp>

void ExitClicked::Clicked()
{
	ExitHandler::Exit();
}
