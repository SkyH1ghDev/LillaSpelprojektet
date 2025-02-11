#include <istream>
#include "GamePhysics.hpp"

bool GamePhysics::WallEntityCollision(const DX::XMFLOAT2& position)
{
    if (position.x < this->m_leftWall)
    {
        return true;
    }
    if (position.y < this->m_topWall)
    {
        return true;
    }
    if (position.x > this->m_rightWall)
    {
        return true;
    }
    if (position.y > this->m_bottomWall)
    {
        return true;
    }
    return false;
}

bool GamePhysics::ProjectileProjectileCollision(const DX::XMFLOAT2& projPos1, const DX::XMFLOAT2& projPos2, const float radius1, const float radius2)
{
    DX::XMFLOAT2 vec = DX::XMFLOAT2(projPos2.x - projPos1.x, projPos2.y - projPos1.y);
    float lenVec = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    if (lenVec < (radius1 + radius2))
    {
        return true;
    }
    return false;
}
