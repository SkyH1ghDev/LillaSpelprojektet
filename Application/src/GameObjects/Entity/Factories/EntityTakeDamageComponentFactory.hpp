#pragma once
#include <memory>
#include "Entity.hpp"
#include "PlayerTakeDamage.hpp"
#include "BishopTakeDamage.hpp"

std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent(EntityType type);