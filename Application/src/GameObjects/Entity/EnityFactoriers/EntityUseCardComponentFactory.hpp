#pragma once
#include <memory>
#include "Entity.hpp"
#include "PlayerUseCard.hpp"
#include "EnemyUseCard.hpp"

std::shared_ptr<IEntityUseCard> CreateUseCardComponent(EntityType type);