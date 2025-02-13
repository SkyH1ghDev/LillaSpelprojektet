#pragma once
#include <memory>
#include "Projectile.hpp"
#include "BaseMove.hpp"

std::shared_ptr<IProjectileMove> CreateMoveComponent(ProjectileType type);