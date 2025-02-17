#pragma once
#include <memory>

#include <SpEngine/Assets/IGameObject.hpp>
#include "ICard.hpp"
// Define an enum for the card 



class ShotgunCard : public ICard
{
public:

    void ActivateLvl1();
    void ActivateLvl2();
    void ActivateLvl3();

    
private:
    
    CardType m_type = CardType::Shotgun;
};

class SpreadCard : public ICard
{
public:
    void ActivateLvl1();
    void ActivateLvl2();
    void ActivateLvl3();

private:

    CardType m_type = CardType::Spread;
};
