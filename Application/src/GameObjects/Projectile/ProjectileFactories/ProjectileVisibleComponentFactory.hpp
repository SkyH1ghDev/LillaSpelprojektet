#pragma once
#include <memory>
#include "Projectile.hpp"
#include "BaseVisible.hpp"

std::shared_ptr<IProjectileVisible> CreateVisibleComponent(ProjectileType type);