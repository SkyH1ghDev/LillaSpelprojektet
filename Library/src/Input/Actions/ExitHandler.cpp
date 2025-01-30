#include "ExitHandler.hpp"

void ExitHandler::Update(std::optional<std::any> data)
{
    this->m_shouldExit = true;
}

bool ExitHandler::ShouldExit()
{
    return this->m_shouldExit;
}

