#include "ProjectileManager.hpp"
#include <algorithm>


// Initialize static variable
std::vector<std::shared_ptr<Projectile>> ProjectileManager::projectiles;

void ProjectileManager::AddProjectile(std::shared_ptr<Projectile> projectile) {
    projectiles.push_back(projectile);
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    testScene->AddGameObject(projectile);
    projectile->OnStart();
    
}

