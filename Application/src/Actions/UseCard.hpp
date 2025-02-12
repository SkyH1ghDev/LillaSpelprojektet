#pragma once
#include "ICardBase.hpp"
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

class UseCard : public ICardBase, public IObserver
{
public:
    UseCard() = default;
    ~UseCard() override = default;
    UseCard(const UseCard& other) = default;
    UseCard& operator=(const UseCard& other) = default;
    UseCard(UseCard&& other) noexcept = default;
    UseCard& operator=(UseCard&& other) noexcept = default;

    void Update(std::optional<std::any> data = std::nullopt)override;

};

inline void UseCard::Update(std::optional<std::any> data)
{
    const float scale = (std::any_cast<std::bitset<4>>(data.value()) & std::bitset<4>(KeyState_Pressed)).any();
    if (scale == 1.0)
    {
        m_usecard = true;
    }
}

