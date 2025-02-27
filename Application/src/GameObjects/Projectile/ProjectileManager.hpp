#include "PoolingManager.hpp"
#include "Projectile.hpp"

class ProjectileManager {
public:
    static void AddProjectile(ProjectileType type, DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float speed, float lifetime, float damage, const std::string& name = "Projectile") {
        auto projectile = PoolManager<Projectile, ProjectileType>::GetObject(type, name);
        projectile->Initialize(position, direction, speed, lifetime, damage);
    }

    static void Cleanup(ProjectileType type) {
        PoolManager<Projectile, ProjectileType>::Cleanup(type);
    }
};