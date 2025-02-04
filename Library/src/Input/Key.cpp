#include "Key.hpp"

#include <iostream>

void Key::Attach(const std::shared_ptr<IObserver>& observer)
{
    if (const auto& it = std::ranges::find(m_observers, observer); it == m_observers.end())
    {
        m_observers.push_back(observer);
    }
}

void Key::Detach(const std::shared_ptr<IObserver>& observer)
{
    if (const auto& it = std::ranges::find(m_observers, observer); it != m_observers.end())
    {
        m_observers.erase(it);
    }
}

void Key::Notify(std::optional<std::any> data)
{
    for (const auto& observer : m_observers)
    {
        observer->Update(data);
    }
}

void Key::ChangeKeyState(bool isPressed)
{
    if (isPressed)
    {
        switch (m_keyState.to_ulong())
        {
            case KeyState_Pressed:
                m_keyState = KeyState_Held;
                break;
            case KeyState_NotPressed:
                m_keyState = KeyState_Pressed;
                break;
            case KeyState_Held:
                m_keyState = KeyState_Held;
                break;
            case KeyState_Released:
                m_keyState = KeyState_Pressed;
                break;

            default:
                break;
        }
    }
    else
    {
        switch (m_keyState.to_ulong())
        {
            case KeyState_Pressed:
                m_keyState = KeyState_Released;
                break;
            case KeyState_NotPressed:
                m_keyState = KeyState_NotPressed;
                break;
            case KeyState_Held:
                m_keyState = KeyState_Released;
                break;
            case KeyState_Released:
                m_keyState = KeyState_NotPressed;
                break;

            default:
                break;
        }
    }
}
