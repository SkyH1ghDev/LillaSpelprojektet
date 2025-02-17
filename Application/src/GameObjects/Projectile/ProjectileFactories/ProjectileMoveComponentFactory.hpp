#pragma once
#include <memory>
#include "Projectile.hpp"
#include "BaseMove.hpp"
#include "PawnPelletMove.hpp"
#include "BishopBallMove.hpp"

std::shared_ptr<IProjectileMove> CreateMoveComponent(ProjectileType type);