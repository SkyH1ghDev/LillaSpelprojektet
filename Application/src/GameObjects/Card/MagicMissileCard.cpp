#include "card.hpp"
#include "ProjectileManager.hpp"

MagicMissileCard::MagicMissileCard()
{
    this->m_type = CardType::MagicMissile;
}

void MagicMissileCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    ProjectileManager::AddProjectile(ProjectileType::MagicMissile, position, target, 200, 6, 50);
}

void MagicMissileCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    ProjectileManager::AddProjectile(ProjectileType::MagicMissile, position, target, 200, 6, 70);
}

void MagicMissileCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    ProjectileManager::AddProjectile(ProjectileType::MagicMissile, position, target, 200, 6, 90);
}

void MagicMissileCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "magic_missile_lvl1.png";
        break;
    case 2:
        this->m_textureName = "magic_missile_lvl2.png";
        break;
    case 3:
        this->m_textureName = "magic_missile_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}