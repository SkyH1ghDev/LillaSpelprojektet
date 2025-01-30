#pragma once
#include <SpEngine/Dev/Pattern/Observer/IObservable.hpp>

class Key : public IObservable
{
public:
    Key() = default;
    ~Key() override = default;
    Key(const Key& other) = default;
    Key& operator=(const Key& other) = default;
    Key(Key&& other) noexcept = default;
    Key& operator=(Key&& other) noexcept = default;

    void Attach(const std::shared_ptr<IObserver>& observer) override;
    void Detach(const std::shared_ptr<IObserver>& observer) override;
    void Notify() override;

};
