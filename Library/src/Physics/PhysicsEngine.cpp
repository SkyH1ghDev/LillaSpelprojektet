#include <istream>
#include "PhysicsEngine.hpp"

int PhysicsEngine::m_leftWall = 40;
int PhysicsEngine::m_rightWall = 600;
int PhysicsEngine::m_topWall = 17;
int PhysicsEngine::m_bottomWall = 320;

bool PhysicsEngine::WallEntityXCollision(std::shared_ptr<Collider> entity)
{
    DX::XMFLOAT2 pos = entity->GetPosition();
    if (pos.x - entity->GetRadiusX() < m_leftWall)
    {
        return true;
    }
    if (pos.x + entity->GetRadiusX() > m_rightWall)
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::WallEntityYCollision(std::shared_ptr<Collider> entity)
{
    DX::XMFLOAT2 pos = entity->GetPosition();
    if (pos.y - entity->GetRadiusY() < m_topWall)
    {
        return true;
    }
    if (pos.y + entity->GetRadiusY() > m_bottomWall)
    {
        return true;
    }
    return false;
}

bool PhysicsEngine::ColliderColliderCollision(std::shared_ptr<Collider> col1, std::shared_ptr<Collider> col2)
{

    DX::XMFLOAT2 projPos = col1->GetPosition();
    DX::XMFLOAT2 entityPos = col2->GetPosition();
    DX::XMFLOAT2 vec = DX::XMFLOAT2(entityPos.x - projPos.x, entityPos.y - projPos.y);
    float radiusX1 = col1->GetRadiusX();
    float radiusX2 = col2->GetRadiusX();
    float radiusY1 = col1->GetRadiusY();
    float radiusY2 = col2->GetRadiusY();

    float term1 = (vec.x * vec.x) / ((radiusX1 + radiusX2) * (radiusX1 + radiusX2));
    float term2 = (vec.y * vec.y) / ((radiusY1 + radiusY2) * (radiusY1 + radiusY2));

    return (term1 + term2) <= 1;
}

bool PhysicsEngine::WallProjectileCollision(std::shared_ptr<Collider> projectile)
{
    DX::XMFLOAT2 projPos = projectile->GetPosition();
    float radius = projectile->GetRadius();

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

bool PhysicsEngine::ProjectileProjectileCollision(std::shared_ptr<Collider> col1, std::shared_ptr<Collider> col2)
{
    DX::XMFLOAT2 projPos1 = col1->GetPosition();
    DX::XMFLOAT2 projPos2 = col2->GetPosition();
    float radius1 = col1->GetRadius();
    float radius2 = col2->GetRadius();

    DX::XMFLOAT2 vec = DX::XMFLOAT2(projPos2.x - projPos1.x, projPos2.y - projPos1.y);
    float lenVec = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    if (lenVec < (radius1 + radius2))
    {
        return true;
    }
    return false;
}
