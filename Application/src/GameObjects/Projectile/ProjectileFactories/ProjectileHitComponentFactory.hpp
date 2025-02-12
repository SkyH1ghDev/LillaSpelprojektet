#pragma once
#include <memory>
#include "Projectile.hpp"
#include "BaseHit.hpp"

std::shared_ptr<IProjectileHit> CreateHitComponent(ProjectileType type);