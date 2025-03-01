#pragma once
#include <memory>
#include "Entity.hpp"
#include "PlayerVisible.hpp"
#include "BishopVisible.hpp"
#include "RookVisible.hpp"

std::shared_ptr<IEntityVisible> CreateVisibleComponent(EntityType type);