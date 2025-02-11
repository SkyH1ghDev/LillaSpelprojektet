#pragma  once
#include <memory>
#include "Card.hpp"

std::shared_ptr<ICardVisible> CreateVisibleComponent(CardType type);