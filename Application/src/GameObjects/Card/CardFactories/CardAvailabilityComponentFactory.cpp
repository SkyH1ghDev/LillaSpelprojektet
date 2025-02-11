#include "CardAvailabilityComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<ICardAvailability> CreateAvailabilityComponent(CardType type) {
    switch (type) {
    case CardType::Shotgun:
        return std::make_shared<ShotgunAvailable>();
        break;
    case CardType::Shield:
        return std::make_shared<ShieldAvailablility>();
        break;
    default:
        throw std::invalid_argument("Unknown CardType in Create AvailabilityComponent");
        break;
    }
}