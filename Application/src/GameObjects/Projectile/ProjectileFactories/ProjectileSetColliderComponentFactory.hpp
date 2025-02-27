#pragma once
#include <memory>
#include "Projectile.hpp"
#include "BaseSetCollider.hpp"
#include "PawnPelletSetCollider.hpp"
#include "BishopBallSetCollider.hpp"
#include "ScatterPelletSetCollider.hpp"
#include "SniperBulletSetCollider.hpp"	
#include "DisruptorWaveSetCollider.hpp"

std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent(ProjectileType type);