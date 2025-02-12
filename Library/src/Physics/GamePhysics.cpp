#include <istream>
#include "GamePhysics.hpp"

bool GamePhysics::WallEntityXCollision(const float xValue)
{
    if (xValue < this->m_leftWall)
    {
        return true;
    }
    if (xValue > this->m_rightWall)
    {
        return true;
    }
    return false;
}

bool GamePhysics::WallEntityYCollision(const float yValue)
{
    if (yValue < this->m_topWall)
    {
        return true;
    }
    if (yValue > this->m_bottomWall)
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
