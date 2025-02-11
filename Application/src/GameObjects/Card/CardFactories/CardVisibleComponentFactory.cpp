#include "CardVisibleComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<ICardVisible> CreateVisibleComponent(CardType type) {
    switch (type) {
    case CardType::Active:
        break;
    case CardType::Passive:
        break;
    default:
        throw std::invalid_argument("Unknown CardType in CreateVisibleComponent");
        break;
    }
}