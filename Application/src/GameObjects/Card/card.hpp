#pragma once
#include <memory>

#include <SpEngine/Assets/IGameObject.hpp>
#include "ICard.hpp"
// Define an enum for the card 



class ShotgunCard : public ICard
{
public:

    void Activate();
    
private:
    
    CardType m_type = CardType::Shotgun;
};

class SpreadCard : public ICard
{
public:
    void Activate();

private:

    CardType m_type = CardType::Spread;
};
