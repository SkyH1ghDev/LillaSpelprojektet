#pragma once
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <SpEngine/Input/KeyState.hpp>
#include <bitset>
#include <iostream>

class Attack : public IObserver
{
public:
    Attack() = default;
    ~Attack() override = default;
    Attack(const Attack& other) = default;
    Attack& operator=(const Attack& other) = default;
    Attack(Attack&& other) noexcept = default;
    Attack& operator=(Attack&& other) noexcept = default;

    bool GetAttack() const;
    void Update(std::optional<std::any> data) override;

protected:
    bool m_attack;

};

//Returns if true if attack key is pressed, false if not
inline bool Attack::GetAttack() const
{
    return this->m_attack;
}

//Update bool for attack key
inline void Attack::Update(std::optional<std::any> data)
{
    float scale = (std::any_cast<std::bitset<4>>(data.value()) & std::bitset<4>(KeyState_Pressed)).any();
    if (scale == 1)
        this->m_attack = true;
    else
        this->m_attack = false;
}
