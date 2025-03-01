#pragma  once
#include <memory>
#include "Entity.hpp"
#include "PlayerAttack.hpp"
#include "BishopAttack.hpp"
#include "RookAttack.hpp"

std::shared_ptr<IEntityAttack> CreateAttackComponent(EntityType type);