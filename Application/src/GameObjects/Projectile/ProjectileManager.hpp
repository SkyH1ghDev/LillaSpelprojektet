#pragma once
#include <vector>
#include "Projectile.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

class ProjectileManager {
public:

    static void AddProjectile(std::shared_ptr<Projectile> projectile);

private:
    static std::vector<std::shared_ptr<Projectile>> projectiles;

};
