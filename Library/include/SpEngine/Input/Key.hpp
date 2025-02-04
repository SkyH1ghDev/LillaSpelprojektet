#pragma once

#include <SpEngine/Dev/Pattern/Observer/IObservable.hpp>
#include <bitset>
#include <SpEngine/Input/KeyState.hpp>


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
    void Notify(std::optional<std::any> data = std::nullopt) override;

    /**
     * Returns the state of the key. Possible values:
     *
     * 0 0 0 1 - NotPressed \n
     * 0 0 1 1 - Released \n
     * 0 1 0 0 - Pressed \n
     * 1 1 0 0 - Held \n
     *
     * @return Key State
     */
    std::bitset<4> GetKeyState() const;

    void ChangeKeyState(bool isPressed);

private:
    std::bitset<4> m_keyState = KeyState_NotPressed;

};

inline std::bitset<4> Key::GetKeyState() const
{
    return m_keyState;
}
