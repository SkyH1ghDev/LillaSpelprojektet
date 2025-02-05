#pragma once
#include <memory>
#include "Entity.hpp"
#include "PlayerUseCard.hpp"
#include "EnemyUseCard.hpp"

std::shared_ptr<IUseCard> CreateUseCardComponent(EntityType type);