#include <istream>
#include "GamePhysics.hpp"

DX::XMFLOAT2 GamePhysics::WallEntityCollision(const DX::XMFLOAT2& position)
{
    DX::XMFLOAT2 returnVec = position;
    if (position.x < this->m_leftWall)
    {
        returnVec.x = this->m_leftWall;
    }
    if (position.y < this->m_topWall)
    {
        returnVec.y = this->m_topWall;
    }
    if (position.x > this->m_rightWall)
    {
        returnVec.x = this->m_rightWall;
    }
    if (position.y > this->m_bottomWall)
    {
        returnVec.y = this->m_bottomWall;
    }
    return returnVec;
}
