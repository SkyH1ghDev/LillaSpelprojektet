#pragma  once
#include <memory>
#include "Card.hpp"
#include "ShotgunActivated.hpp"
#include "ShieldActivated.hpp"


std::shared_ptr<ICardActivated> CreateActivatedComponent(CardType type);