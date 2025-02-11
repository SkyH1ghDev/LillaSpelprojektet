#include "CardAvailabilityComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<ICardAvailability> CreateAvailabilityComponent(CardType type) {
    switch (type) {
        case CardType::Active:
        break;
        case CardType::Passive:
        break;
    default:
        throw std::invalid_argument("Unknown CardType in Create AvailabilityComponent");
        break;
    }
}