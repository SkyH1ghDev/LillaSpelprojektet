#include "ProjectileManager.hpp"
#include <algorithm>

// Initialize static variable
std::vector<std::shared_ptr<Projectile>> ProjectileManager::projectiles;

void ProjectileManager::Initialize(size_t poolSize) {
    projectiles.clear(); // Clear any existing projectiles
    projectiles.reserve(poolSize); // Reserve memory upfront
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    for (size_t i = 0; i < poolSize; ++i) {
        auto projectile = std::make_shared<Projectile>(ProjectileType::Base);
        projectile->SetActive(false); // Ensure projectiles start inactive
        projectiles.push_back(projectile);
        testScene->AddGameObject(projectile);
    }
}

void ProjectileManager::AddProjectile(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float speed, float lifetime) {
    // Use a static index to avoid searching from the beginning every time
    static size_t lastInactiveIndex = 0;
    // Start searching from the last inactive index
    for (size_t i = 0; i < projectiles.size(); ++i) {
        size_t index = (lastInactiveIndex + i) % projectiles.size(); // Wrap around using modulo
        if (!projectiles[index]->IsActive()) {
            // Reuse the inactive projectile
            projectiles[index]->Initialize(position, direction, speed, lifetime);
            //projectiles[index]->SetActive(true);
            lastInactiveIndex = (index + 1) % projectiles.size();
            return;
        }
    }
    // If no inactive projectile is found, dynamically expand the pool by 1.5x
    size_t newSize = static_cast<size_t>(projectiles.size() * 2);
    size_t oldSize = projectiles.size();
    if (newSize <= projectiles.size()) {
        newSize = projectiles.size() + 1; // Ensure at least one new projectile is added
    }

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    projectiles.reserve(newSize);

    for (size_t i = oldSize; i < newSize; ++i) {
        auto newProjectile = std::make_shared<Projectile>(ProjectileType::Base);
        newProjectile->SetActive(false); // Start inactive
        projectiles.push_back(newProjectile);
        testScene->AddGameObject(newProjectile);
    }

    // Reuse the first newly added projectile
    projectiles[oldSize]->Initialize(position, direction, speed, lifetime);
    projectiles[oldSize]->SetActive(true);

    // Update the lastInactiveIndex to the newly added projectile
    lastInactiveIndex = oldSize;
}