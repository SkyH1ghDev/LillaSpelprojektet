#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "Projectile.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

class ProjectileManager {
public:
    static void Initialize(ProjectileType type, size_t poolSize);
    static void AddProjectile(ProjectileType type, DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float speed, float lifetime);

private:
    static std::unordered_map<ProjectileType, std::vector<std::shared_ptr<Projectile>>> projectilePools;
    static std::unordered_map<ProjectileType, size_t> lastInactiveIndexMap; // Tracks the last used inactive projectile
};
