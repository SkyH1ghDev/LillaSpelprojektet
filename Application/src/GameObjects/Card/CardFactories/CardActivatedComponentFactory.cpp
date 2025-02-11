#include "CardActivatedComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<ICardActivated> CreateActivatedComponent(CardType type) {
    switch (type) {
    case CardType::Shotgun:
        return std::make_shared<ShotgunActivated>();
        break;
    case CardType::Shield:
        return std::make_shared<ShieldActivated>();
        break;
    default:
        throw std::invalid_argument("Unknown Cardtype in CreateActivatedComponent");
        break;
    }
}