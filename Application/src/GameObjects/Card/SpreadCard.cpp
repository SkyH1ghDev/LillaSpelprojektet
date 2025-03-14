#include "Card.hpp"
#include "AbilityManager.hpp"

SpreadCard::SpreadCard()
{
    this->m_type = CardType::Spread;
}

void SpreadCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
	AbilityManager::SurroundShot(position, 15, 7, 100);
}

void SpreadCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
	AbilityManager::SurroundShot(position, 30, 8, 150);
}

void SpreadCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
	AbilityManager::SurroundShot(position, 45, 9, 200);
}

void SpreadCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "ring_of_fire_lvl1.png";
        break;
    case 2:
        this->m_textureName = "ring_of_fire_lvl2.png";
        break;
    case 3:
        this->m_textureName = "ring_of_fire_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}
