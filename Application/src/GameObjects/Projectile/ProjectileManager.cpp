#include "ProjectileManager.hpp"
#include <algorithm>
#include <unordered_map>

// Initialize static variable
std::unordered_map<ProjectileType, std::vector<std::shared_ptr<Projectile>>> ProjectileManager::projectilePools;

void ProjectileManager::Initialize(ProjectileType type, size_t poolSize) {
    auto& projectiles = projectilePools[type]; // Get the pool for the given type
    projectiles.clear();
    projectiles.reserve(poolSize);

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    for (size_t i = 0; i < poolSize; ++i) {
        auto projectile = std::make_shared<Projectile>(type);
        projectile->SetActive(false);
        projectiles.push_back(projectile);
        testScene->AddGameObject(projectile);
    }
}

void ProjectileManager::AddProjectile(ProjectileType type, DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float speed, float lifetime, float damage) {
    static std::unordered_map<ProjectileType, size_t> lastInactiveIndexMap;

    auto& projectiles = projectilePools[type];

    if (projectiles.empty()) {
        Initialize(type, 10); // Create an initial pool if none exists
    }

    size_t& lastInactiveIndex = lastInactiveIndexMap[type];

    for (size_t i = 0; i < projectiles.size(); ++i) {
        size_t index = (lastInactiveIndex + i) % projectiles.size();
        if (!projectiles[index]->IsActive()) {
            projectiles[index]->Initialize(position, direction, speed, lifetime, damage);
            lastInactiveIndex = (index + 1) % projectiles.size();
            return;
        }
    }

    // Expand the pool if no inactive projectile is found
    size_t oldSize = projectiles.size();
    size_t newSize = oldSize * 2;

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    projectiles.reserve(newSize);

    for (size_t i = oldSize; i < newSize; ++i) {
        auto newProjectile = std::make_shared<Projectile>(type);
        newProjectile->SetActive(false);
        projectiles.push_back(newProjectile);
        testScene->AddGameObject(newProjectile);
    }

    projectiles[oldSize]->Initialize(position, direction, speed, lifetime, damage);
    projectiles[oldSize]->SetActive(true);
    lastInactiveIndex = oldSize;
}
