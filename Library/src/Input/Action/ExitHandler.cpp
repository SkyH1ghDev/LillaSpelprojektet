#include "ExitHandler.hpp"

void ExitHandler::Update(std::optional<std::any> data)
{

    // Makes sure that if it has been set to true,
    // it can't be changed back and makes sure the program exits correctly
    if (m_shouldExit)
    {
        return;
    }

    if (data.has_value())
    {
        m_shouldExit = std::any_cast<bool>(data.value());
    }
}

bool ExitHandler::ShouldExit() const
{
    return this->m_shouldExit;
}

