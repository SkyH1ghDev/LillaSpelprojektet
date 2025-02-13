#pragma once
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
    void Update(std::optional<std::any> data) override;

protected:
    bool m_useCard;

};

//Returns if true if attack key is pressed, false if not
inline bool UseCard::GetUseCard() const
{
    return this->m_useCard;
}

//Update bool for attack key
inline void UseCard::Update(std::optional<std::any> data)
{
    float scale = (std::any_cast<std::bitset<4>>(data.value()) & std::bitset<4>(KeyState_Pressed)).any();
    if (scale == 1)
        this->m_useCard = true;
    else
        this->m_useCard = false;
}
