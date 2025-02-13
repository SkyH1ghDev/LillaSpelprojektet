#include "CardActivatedComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<ICardActivated> CreateActivatedComponent(CardType type) {
    switch (type) {

    default:
        throw std::invalid_argument("Unknown Cardtype in CreateActivatedComponent");
        break;
    }
}