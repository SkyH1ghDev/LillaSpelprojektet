#include "Key.hpp"

#include <iostream>

void Key::Attach(const std::shared_ptr<IObserver>& observer)
{
    auto it = std::find(m_observers.begin(), m_observers.end(), observer);

    // Checks so that object doesn't already exist
    if (it == m_observers.end())
    {
        m_observers.push_back(observer);
    }
}

void Key::Detach(const std::shared_ptr<IObserver>& observer)
{
    auto it = std::find(m_observers.begin(), m_observers.end(), observer);

    if (it != m_observers.end())
    {
        m_observers.erase(it);
    }
}

void Key::Notify()
{
    std::cout << "Key Pressed, Adress(" << this << ")\n";

    for (const auto& observer : m_observers)
    {
        observer->Update();
    }
}
