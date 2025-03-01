#pragma once

#include <memory>
#include "Entity.hpp"
#include "PlayerMove.hpp"
#include "BishopMove.hpp"
#include "RookMove.hpp"

std::shared_ptr<IEntityMove> CreateMoveComponent(EntityType type);