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

    /**
     * Binds action to key
     *
     * @param observer Action to bind to key
     */
    void Attach(const std::shared_ptr<IObserver>& observer) override;

    /**
     * Unbinds action from key
     *
     * @param observer Action to unbind from key
     */
    void Detach(const std::shared_ptr<IObserver>& observer) override;

    /**
     * Execute key action
     */
    void Notify() override;

};
