#pragma  once
#include <memory>
#include "Card.hpp"


std::shared_ptr<ICardActivated> CreateActivatedComponent(CardType type);