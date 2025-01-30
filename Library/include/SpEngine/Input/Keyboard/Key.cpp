#include "Key.hpp"

void Key::Attach(const std::shared_ptr<IObserver>& observer)
{
    auto it = std::find(m_observers.begin(), m_observers.end(), observer);

    if (it != m_observers.end())
    {
        m_observers.erase(it);
    }
}

void Key::Detach(const std::shared_ptr<IObserver>& observer)
{
    m_observers.push_back(observer);
}

void Key::Notify()
{
    for (const auto& observer : m_observers)
    {
        observer->Update(0);
    }
}
