#include "Card.hpp"
#include "CardActivatedComponentFactory.hpp"
#include "CardAvailabilityComponentFactory.hpp"
#include "CardVisibleComponentFactory.hpp"
#include <iostream>



Card::Card(CardType cardType) :
    m_activated (CreateActivatedComponent(cardType)),
    m_visible (CreateVisibleComponent(cardType)),
    m_available (CreateAvailabilityComponent(cardType))
{
    std::cout << "Card created of type: " << (m_type == CardType::Shotgun ? "Shotgun" : "Shield") << "\n";
}
