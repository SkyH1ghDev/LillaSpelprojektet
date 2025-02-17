#pragma once
#include <memory>

#include <SpEngine/Assets/IGameObject.hpp>
#include "ICard.hpp"


class ShotgunCard : public ICard 
{
public:
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;

    
private:
    
    CardType m_type = CardType::Shotgun;
};

class SpreadCard : public ICard
{
public:
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;

private:
    CardType m_type = CardType::Spread;
};
