#pragma  once
#include <memory>
#include "Card.hpp"

std::shared_ptr<ICardAvailability> CreateAvailabilityComponent(CardType type);