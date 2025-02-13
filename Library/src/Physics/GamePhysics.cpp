#include <istream>
#include "GamePhysics.hpp"

int PhysicsEngine::m_leftWall = 40;
int PhysicsEngine::m_rightWall = 600;
int PhysicsEngine::m_topWall = 17;
int PhysicsEngine::m_bottomWall = 320;

bool PhysicsEngine::WallEntityXCollision(const float xPos, const float radius, const float ARM)
{
    if (xPos - (ARM * radius) < m_leftWall)
    {
        return true;
    }
    if (xPos + (ARM * radius) > m_rightWall)
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::WallEntityYCollision(const float yPos, const float radius, const float ARM)
{
    if (yPos - (ARM * radius) < m_topWall)
    {
        return true;
    }
    if (yPos + (ARM * radius) > m_bottomWall)
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::ProjectileProjectileCollision(const DX::XMFLOAT2& projPos1, const DX::XMFLOAT2& projPos2, const float radius1, const float radius2)
{
    DX::XMFLOAT2 vec = DX::XMFLOAT2(projPos2.x - projPos1.x, projPos2.y - projPos1.y);
    float lenVec = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    if (lenVec < (radius1 + radius2))
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::WallProjectileXCollision(const float xPos, const float radius, const float ARM)
{
    if (xPos - (ARM * radius) < m_leftWall)
    {
        return true;
    }
    if (xPos + (ARM * radius) > m_rightWall)
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::WallProjectileYCollision(const float yPos, const float radius, const float ARM)
{
    if (yPos - (ARM * radius) < m_topWall)
    {
        return true;
    }
    if (yPos + (ARM * radius) > m_bottomWall)
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::EntityEntityCollision(const DX::XMFLOAT2& entPos1, const DX::XMFLOAT2& entPos2, const float radiusX1, const float radiusY1, const float radiusX2, const float radiusY2)
{
    DX::XMFLOAT2 vec = DX::XMFLOAT2(entPos2.x - entPos1.x, entPos2.y - entPos1.y);

    float term1 = (vec.x * vec.x) / ((radiusX1 + radiusX2) * (radiusX1 + radiusX2));
    float term2 = (vec.y * vec.y) / ((radiusY1 + radiusY2) * (radiusY1 + radiusY2));

    return (term1 + term2) <= 1;
}
