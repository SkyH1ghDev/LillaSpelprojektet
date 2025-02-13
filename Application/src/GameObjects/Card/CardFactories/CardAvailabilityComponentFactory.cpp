#include "CardAvailabilityComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<ICardAvailability> CreateAvailabilityComponent(CardType type) {
    switch (type) {

    default:
        throw std::invalid_argument("Unknown CardType in Create AvailabilityComponent");
        break;
    }
}