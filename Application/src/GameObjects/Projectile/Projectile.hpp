#pragma once
#include <memory>

#include <SpEngine/Assets/Game/IGameObject.hpp>

enum class ProjectileType {
    Base,
    BishopBall,
    PawnPellet,
    ScatterPellet,
    SniperBullet
};

#include "IProjectileMove.hpp"
#include "IProjectileVisible.hpp"
#include "IProjectileHit.hpp"
#include "IProjectileSetCollider.hpp"

class Projectile : public IGameObject
{
public:

    Projectile() = default;
    ~Projectile() override = default;
    Projectile(const Projectile& other) = default;
    Projectile& operator=(const Projectile& other) = default;
    Projectile(Projectile&& other) noexcept = default;
    Projectile& operator=(Projectile&& other) noexcept = default;

    Projectile(ProjectileType projectileType);
    void Initialize(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float velocity, float lifetime, float damage);
    void PerformMove(const DX::XMFLOAT2& direction, float velocity);
    void PerformVisible(ProjectileState projectileState) { if (m_visible) m_visible->Visible(m_textureName, m_position, projectileState, m_layerFloat, m_scaleFloat); }
    void PerformHit() { if (m_hit) m_hit->Hit(this->m_isActive, this->m_shouldRender, this->m_isAlive); }
    void PerformSetCollider();
    
    void Update() override;
    void OnStart() override;

    ProjectileType GetType() const { return m_type; }

    float GetDamage() const;

private:
    std::shared_ptr<IProjectileMove> m_move;
    std::shared_ptr<IProjectileVisible> m_visible;
    std::shared_ptr<IProjectileHit> m_hit;
    std::shared_ptr<IProjectileSetCollider> m_setCollider;
    ProjectileType m_type;
    DX::XMFLOAT2 m_setPosition;
    DX::XMFLOAT2 m_direction;
    float m_velocity;
    float m_lifetime;
    float m_damageAmp = 1.0;
    float m_damage = 0.0;
};
