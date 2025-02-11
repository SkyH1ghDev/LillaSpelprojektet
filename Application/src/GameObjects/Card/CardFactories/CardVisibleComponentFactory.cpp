#include "CardVisibleComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<ICardVisible> CreateVisibleComponent(CardType type) {
    switch (type) {
    case CardType::Shotgun:
        return std::make_shared<ShotgunVisible>();
        break;
    case CardType::Shield:
        return std::make_shared < ShieldVisible>();
        break;
    default:
        throw std::invalid_argument("Unknown CardType in CreateVisibleComponent");
        break;
    }
}