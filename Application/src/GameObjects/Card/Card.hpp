#pragma once

#include <SpEngine/Assets/Game/IGameObject.hpp>
#include "ICard.hpp"


class ShotgunCard : public ICard 
{
public:
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;
    
private:
    CardType m_type = CardType::Shotgun;
};

class SpreadCard : public ICard
{
public:
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
    CardType m_type = CardType::Spread;
};

class HealCard : public ICard
{
public:
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
    CardType m_type = CardType::Heal;
};

class SniperCard : public ICard
{
public:
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
    CardType m_type = CardType::Sniper;
};

class DisruptorCard : public ICard
{
public:
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
    CardType m_type = CardType::Disruptor;
};