#pragma once
#include <memory>
#include "Entity.hpp"
#include "PlayerTakeDamage.hpp"
#include "BishopTakeDamage.hpp"
#include "RookTakeDamage.hpp"

std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent(EntityType type);