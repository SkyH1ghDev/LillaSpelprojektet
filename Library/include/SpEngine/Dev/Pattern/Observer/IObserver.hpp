#pragma once
#include <any>

class IObserver
{
public:
    IObserver() = default;
    virtual ~IObserver() = default;
    IObserver(const IObserver& other) = default;
    IObserver& operator=(const IObserver& other) = default;
    IObserver(IObserver&& other) noexcept = default;
    IObserver& operator=(IObserver&& other) noexcept = default;

    virtual void Update(std::any data) = 0;
};
