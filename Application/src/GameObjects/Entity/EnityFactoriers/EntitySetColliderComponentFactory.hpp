#pragma once

#include <memory>
#include "Entity.hpp"
#include "PlayerSetCollider.hpp"
#include "BishopSetCollider.hpp"
#include "RookSetCollider.hpp"

std::shared_ptr<IEntitySetCollider> CreateColliderComponent(EntityType type);