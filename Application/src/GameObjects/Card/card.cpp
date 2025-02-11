#include "card.hpp"
#include "CardActivatedFactory.hpp"
#include "CardAvailabilityFactory.hpp"
#include "CardVisibleFactory.hpp"
#include <iostream>



Card::Card(CardType cardType) :
    m_activated (CreateActivatedComponent(cardType)),
    m_visible (CreateVisibleComponent(cardType)),
    m_available (CreateAvailabilityComponent(cardType))
{
    std::cout << "Card created of type: " << (m_type == CardType::Passive ? "Passive" : "Active") << "\n";
}
