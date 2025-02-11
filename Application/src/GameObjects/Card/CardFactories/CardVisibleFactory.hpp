#pragma  once
#include <memory>
#include "Entity.hpp"
#include "PlayerAttack.hpp"
#include "EnemyAttack.hpp"

std::shared_ptr<IEntityAttack> CreateAttackComponent(EntityType type);