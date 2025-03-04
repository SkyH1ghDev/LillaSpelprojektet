
#pragma once

#include "Projectile.hpp"
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include <SpEngine/Manager/SceneManager.hpp>
#include "PoolManager.hpp"

class ProjectileManager {
public:
    static void AddProjectile(ProjectileType type, DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float speed, float lifetime, float damage, const std::string& name = "Projectile") {
        auto projectile = PoolManager<Projectile, ProjectileType>::GetObject(type);
        projectile->Initialize(position, direction, speed, lifetime, damage);
    }

    static void Cleanup(ProjectileType type) {
        PoolManager<Projectile, ProjectileType>::Cleanup(type);
    }
};