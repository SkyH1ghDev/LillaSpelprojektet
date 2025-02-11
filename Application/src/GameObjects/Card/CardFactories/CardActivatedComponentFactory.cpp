#include "CardActivatedComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<ICardActivated> CreateActivatedComponent(CardType type) {
    switch (type) {
    case CardType::Active:
        break;
    case CardType::Passive:
        break;
    default:
        throw std::invalid_argument("Unknown Cardtype in CreateActivatedComponent");
        break;
    }
}