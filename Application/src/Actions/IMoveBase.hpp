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

    DX::XMFLOAT2 GetMoveDirection() const;

protected:
    DX::XMFLOAT2 m_moveDirection;

};

inline DX::XMFLOAT2 IMoveBase::GetMoveDirection() const
{
    return m_moveDirection;
}

