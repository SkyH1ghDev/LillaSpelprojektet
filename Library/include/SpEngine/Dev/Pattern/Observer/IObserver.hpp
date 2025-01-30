#pragma once
#include <any>
#include <optional>

class IObserver
{
public:
    IObserver() = default;
    virtual ~IObserver() = default;
    IObserver(const IObserver& other) = default;
    IObserver& operator=(const IObserver& other) = default;
    IObserver(IObserver&& other) noexcept = default;
    IObserver& operator=(IObserver&& other) noexcept = default;

    /**
     * Updates the observer with relevant data
     *
     * @param[Optional, In] data Data that could be relevant for the update
     */
    virtual void Update(std::optional<std::any> data = std::nullopt) = 0;
};
