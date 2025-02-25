#pragma once
#include <memory>
#include "Projectile.hpp"
#include "BaseVisible.hpp"
#include "BishopBallVisible.hpp"
#include "PawnPelletVisible.hpp"
#include "ScatterPelletVisible.hpp"

std::shared_ptr<IProjectileVisible> CreateVisibleComponent(ProjectileType type);