#pragma once
#include <memory>

#include <SpEngine/Assets/IGameObject.hpp>

enum class ProjectileType {
    Base,
};

#include "IProjectileMove.hpp"
#include "IProjectileVisible.hpp"
#include "IProjectileHit.hpp"

class Projectile : public IGameObject
{
public:

    Projectile() = default;
    ~Projectile() override = default;
    Projectile(const Projectile& other) = default;
    Projectile& operator=(const Projectile& other) = default;
    Projectile(Projectile&& other) noexcept = default;
    Projectile& operator=(Projectile&& other) noexcept = default;

    Projectile(ProjectileType projectileType, DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float velocity, float lifetime);

    void PerformMove(const DX::XMFLOAT2& direction, float velocity);
    void PerformVisible(ProjectileState projectileState) { if (m_visible) m_visible->Visible(m_textureName, projectileState, m_layerFloat, m_scaleFloat); }
    bool PerformHit() { if (m_hit) m_hit->Hit(); }
    

    void Update() override;
    void OnStart() override;

    ProjectileType GetType() const { return m_type; }

private:
    std::shared_ptr<IProjectileMove> m_move;
    std::shared_ptr<IProjectileVisible> m_visible;
    std::shared_ptr<IProjectileHit> m_hit;
    ProjectileType m_type;
    DX::XMFLOAT2 m_setPosition;
    DX::XMFLOAT2 m_direction;
    float m_velocity;
    float m_lifetime;
};
