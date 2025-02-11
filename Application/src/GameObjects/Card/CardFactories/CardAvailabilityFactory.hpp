#pragma  once
#include <memory>
#include "card.hpp"

std::shared_ptr<IEntityAttack> CreateAttackComponent(EntityType type);