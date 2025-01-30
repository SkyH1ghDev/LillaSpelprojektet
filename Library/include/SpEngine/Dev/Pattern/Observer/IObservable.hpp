#pragma once

#include <memory>
#include <vector>

#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>

class IObservable
{
public:
    IObservable() = default;
    virtual ~IObservable() = default;
    IObservable(const IObservable& other) = default;
    IObservable& operator=(const IObservable& other) = default;
    IObservable(IObservable&& other) noexcept = default;
    IObservable& operator=(IObservable&& other) noexcept = default;

    virtual void Attach(const std::shared_ptr<IObserver>& observer) = 0;
    virtual void Detach(const std::shared_ptr<IObserver>& observer) = 0;
    virtual void Notify() = 0;

protected:
    std::vector<std::shared_ptr<IObserver>> m_observers;

};
