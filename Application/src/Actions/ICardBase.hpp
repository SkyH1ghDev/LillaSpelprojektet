#pragma once
#include "IMoveBase.hpp"
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

class UseCard : public IObserver
{
public:
    UseCard() = default;
    ~UseCard() override = default;
    UseCard(const UseCard& other) = default;
    UseCard& operator=(const UseCard& other) = default;
    UseCard(UseCard&& other) noexcept = default;
    UseCard& operator=(UseCard&& other) noexcept = default;

    
    bool GetUseCard() const;
protected:
    bool m_usecard=true;
};

inline bool UseCard::GetUseCard() const
{
    return m_usecard;
}
