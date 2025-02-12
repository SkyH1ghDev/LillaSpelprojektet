#pragma once
//#include "IMoveBase.hpp"
//#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
//#include <SpEngine/Input/KeyState.hpp>
//#include <bitset>

class ICardBase
{
public:
    ICardBase() = default;
    virtual ~ICardBase() = default;
    ICardBase(const ICardBase& other) = default;
    ICardBase& operator=(const ICardBase& other) = default;
    ICardBase(ICardBase&& other) noexcept = default;
    ICardBase& operator=(ICardBase&& other) noexcept = default;

    
    bool GetUseCard() const;
protected:
    bool m_usecard;
};

inline bool ICardBase::GetUseCard() const
{
    return m_usecard;
}
