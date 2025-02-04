#pragma once

#include <DirectXMath.h>

namespace DX = DirectX;

class IMoveBase
{
public:
    IMoveBase() = default;
    virtual ~IMoveBase() = default;
    IMoveBase(const IMoveBase& other) = default;
    IMoveBase& operator=(const IMoveBase& other) = default;
    IMoveBase(IMoveBase&& other) noexcept = default;
    IMoveBase& operator=(IMoveBase&& other) noexcept = default;

    DX::XMVECTOR GetMoveDirection() const;

protected:
    DX::XMVECTOR m_moveDirection;

};

inline DX::XMVECTOR IMoveBase::GetMoveDirection() const
{
    return m_moveDirection;
}

