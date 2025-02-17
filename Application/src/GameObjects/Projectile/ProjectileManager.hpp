#pragma once
#include <vector>
#include <memory>
#include "Projectile.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

class ProjectileManager {
public:
    static void Initialize(size_t poolSize);
    static void AddProjectile(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float speed, float lifetime);

private:
    static std::vector<std::shared_ptr<Projectile>> projectiles;
};
