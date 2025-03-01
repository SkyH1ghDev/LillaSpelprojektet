#pragma once

#include <memory>
#include "Entity.hpp"
#include "PlayerMove.hpp"
#include "BishopMove.hpp"

std::shared_ptr<IEntityMove> CreateMoveComponent(EntityType type);