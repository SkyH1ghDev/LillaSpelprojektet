#include "OnMouseClick.hpp"

#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

void OnMouseClick::Update(std::optional<std::any> data)
{
    if (data.has_value())
    {
        m_isClicked = (std::any_cast<std::bitset<4>>(data.value()) == std::bitset<4>(KeyState_Pressed)) ? 1.0f : 0.0f;
    }
}


