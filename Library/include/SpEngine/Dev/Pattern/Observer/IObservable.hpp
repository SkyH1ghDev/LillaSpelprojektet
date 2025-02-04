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

    /**
     * Adds observer to the observer vector
     *
     * @param observer Observer to be attached to the observable object
     */
    virtual void Attach(const std::shared_ptr<IObserver>& observer) = 0;

    /**
     * Removes observer from the observer vector
     *
     * @param observer Observer to be detached from the observable object
     */
    virtual void Detach(const std::shared_ptr<IObserver>& observer) = 0;

    /**
     * Notifies the observers that something has occured
     */
    virtual void Notify(std::optional<std::any> data = std::nullopt) = 0;

    /**
     * Returns data to be sent to the IObserver objects
     *
     * @return Data
     */

protected:
    std::vector<std::shared_ptr<IObserver>> m_observers;

};
