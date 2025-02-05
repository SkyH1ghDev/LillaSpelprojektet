#pragma once
#include <memory>
#include "Entity.hpp"
#include "PlayerVisible.hpp"
#include "EnemyVisible.hpp"

std::shared_ptr<IVisible> CreateVisibleComponent(EntityType type);