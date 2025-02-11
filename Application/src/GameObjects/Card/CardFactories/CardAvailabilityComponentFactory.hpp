#pragma  once
#include <memory>
#include "Card.hpp"
#include "ShotgunAvailable.hpp"
#include "ShieldAvailable.hpp"

std::shared_ptr<ICardAvailability> CreateAvailabilityComponent(CardType type);