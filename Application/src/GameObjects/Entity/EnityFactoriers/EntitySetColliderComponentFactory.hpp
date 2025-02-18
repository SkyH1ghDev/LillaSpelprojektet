#pragma once

#include <memory>
#include "Entity.hpp"
#include "PlayerSetCollider.hpp"
#include "EnemySetCollider.hpp"

std::shared_ptr<IEntitySetCollider> CreateColliderComponent(EntityType type);