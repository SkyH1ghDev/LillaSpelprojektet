#pragma  once
#include <memory>
#include "Card.hpp"
#include "ShotgunVisible.hpp"
#include "ShieldVisible.hpp"

std::shared_ptr<ICardVisible> CreateVisibleComponent(CardType type);