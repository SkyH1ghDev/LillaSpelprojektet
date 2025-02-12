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
    m_usecard = true;
}

