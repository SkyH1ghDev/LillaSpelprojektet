#pragma once
#include <memory>
#include "Projectile.hpp"
#include "BaseMove.hpp"
#include "PawnPelletMove.hpp"
#include "BishopBallMove.hpp"
#include "ScatterPelletMove.hpp"
#include "SniperBulletMove.hpp"
#include "DisruptorWaveMove.hpp"

std::shared_ptr<IProjectileMove> CreateMoveComponent(ProjectileType type);