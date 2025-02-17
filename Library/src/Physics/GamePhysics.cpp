#include <istream>
#include "GamePhysics.hpp"

int PhysicsEngine::m_leftWall = 40;
int PhysicsEngine::m_rightWall = 600;
int PhysicsEngine::m_topWall = 17;
int PhysicsEngine::m_bottomWall = 320;

bool PhysicsEngine::WallEntityXCollision(const Collider& entity)
{
    DX::XMFLOAT2 pos = entity.GetPosition();
    if (pos.x - entity.GetRadiusX() < m_leftWall)
    {
        return true;
    }
    if (pos.x + entity.GetRadiusX() > m_rightWall)
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::WallEntityYCollision(const Collider& entity)
{
    DX::XMFLOAT2 pos = entity.GetPosition();
    if (pos.y - entity.GetRadiusY() < m_topWall)
    {
        return true;
    }
    if (pos.y + entity.GetRadiusY() > m_bottomWall)
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::ProjectileEntityCollision(const Collider& projectile, const Collider& entity)
{
    DX::XMFLOAT2 projPos = projectile.GetPosition();
    DX::XMFLOAT2 entityPos = entity.GetPosition();
    DX::XMFLOAT2 vec = DX::XMFLOAT2(entityPos.x - projPos.x, entityPos.y - entityPos.y);
    float radiusX1 = projectile.GetRadiusX();
    float radiusX2 = entity.GetRadiusX();
    float radiusY1 = projectile.GetRadiusY();
    float radiusY2 = entity.GetRadiusY();

    float term1 = (vec.x * vec.x) / ((radiusX1 + radiusX2) * (radiusX1 + radiusX2));
    float term2 = (vec.y * vec.y) / ((radiusY1 + radiusY2) * (radiusY1 + radiusY2));

    return (term1 + term2) <= 1;
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

bool PhysicsEngine::WallProjectileCollision(const DX::XMFLOAT2& projPos, const float radius)
{
    if (projPos.x - radius < m_leftWall)
    {
        return true;
    }
    if (projPos.x + radius > m_rightWall)
    {
        return true;
    }
    if (projPos.y - radius < m_topWall)
    {
        return true;
    }
    if (projPos.y + radius > m_bottomWall)
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::EntityEntityCollision(const Collider& projectile, const Collider& entity)
{
    DX::XMFLOAT2 projPos = projectile.GetPosition();
    DX::XMFLOAT2 entityPos = entity.GetPosition();
    DX::XMFLOAT2 vec = DX::XMFLOAT2(entityPos.x - projPos.x, entityPos.y - entityPos.y);
    float radiusX1 = projectile.GetRadiusX();
    float radiusX2 = entity.GetRadiusX();
    float radiusY1 = projectile.GetRadiusY();
    float radiusY2 = entity.GetRadiusY();

    float term1 = (vec.x * vec.x) / ((radiusX1 + radiusX2) * (radiusX1 + radiusX2));
    float term2 = (vec.y * vec.y) / ((radiusY1 + radiusY2) * (radiusY1 + radiusY2));

    return (term1 + term2) <= 1;
}
