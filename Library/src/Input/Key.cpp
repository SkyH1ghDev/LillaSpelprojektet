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
        observer->Update();
    }
}
