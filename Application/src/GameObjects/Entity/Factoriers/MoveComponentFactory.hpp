#pragma once

#include <memory>
#include "Entity.hpp"
#include "PlayerMove.hpp"
#include "EnemyMove.hpp"

std::shared_ptr<IMove> CreateMoveComponent(EntityType type);