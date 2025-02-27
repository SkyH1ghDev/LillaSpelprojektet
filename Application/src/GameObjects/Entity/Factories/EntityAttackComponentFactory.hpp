#pragma  once
#include <memory>

std::shared_ptr<IEntityAttack> CreateAttackComponent(EntityType type);