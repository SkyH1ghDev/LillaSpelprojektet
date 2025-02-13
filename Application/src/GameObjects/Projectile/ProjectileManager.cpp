#include "ProjectileManager.hpp"
#include <algorithm>

// Initialize static variable
std::vector<std::shared_ptr<Projectile>> ProjectileManager::projectiles;

void ProjectileManager::Initialize(size_t poolSize) {
    projectiles.clear(); // Clear any existing projectiles
    projectiles.reserve(poolSize); // Reserve memory upfront
    for (size_t i = 0; i < poolSize; ++i) {
        auto projectile = std::make_shared<Projectile>(ProjectileType::Base);
        projectile->SetActive(false); // Ensure projectiles start inactive
        projectiles.push_back(projectile);
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
            projectiles[index]->SetActive(true);

            // Add to the scene
            auto testScene = SceneManager::GetScene("main");
            if (testScene) {
                testScene->AddGameObject(projectiles[index]);
            }

            // Update the last inactive index for the next call
            lastInactiveIndex = (index + 1) % projectiles.size();
            return;
        }
    }

    // If no inactive projectile is found, log a warning or expand the pool
    // (Optional: Dynamically resize the pool if needed)
    // projectiles.push_back(std::make_shared<Projectile>(ProjectileType::Base));
    // AddProjectile(position, direction, speed, lifetime);
}