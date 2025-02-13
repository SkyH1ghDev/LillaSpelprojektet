#include "CardVisibleComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<ICardVisible> CreateVisibleComponent(CardType type) {
    switch (type) {
    default:
        throw std::invalid_argument("Unknown CardType in CreateVisibleComponent");
        break;
    }
}