#pragma once
#include <memory>
#include "Projectile.hpp"
#include "BaseHit.hpp"
#include "PawnPelletHit.hpp"
#include "BishopBallHit.hpp"
#include "ScatterPellethit.hpp"

std::shared_ptr<IProjectileHit> CreateHitComponent(ProjectileType type);