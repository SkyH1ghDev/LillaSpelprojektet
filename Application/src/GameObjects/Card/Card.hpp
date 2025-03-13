#pragma once

#include <SpEngine/Assets/Game/IGameObject.hpp>
#include "ICard.hpp"


class ShotgunCard : public ICard 
{
public:
    ShotgunCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;
    
private:
};

class SpreadCard : public ICard
{
public:
    SpreadCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
};

class HealCard : public ICard
{
public:
    HealCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
};

class SniperCard : public ICard
{
public:
    SniperCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
};

class DisruptorCard : public ICard
{
public:
    DisruptorCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
};

class RangeBuffCard : public ICard
{
public:
    RangeBuffCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
};

class AttackSpeedBuffCard : public ICard
{
public:
    AttackSpeedBuffCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
};

class IceCubesCard : public ICard
{
public:
    IceCubesCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
};

class MagicMissileCard : public ICard
{
public:
    MagicMissileCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
};

class BladeCard : public ICard
{
public:
    BladeCard();
    void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) override;
    void SetCardTexture(size_t cardLevel) override;

private:
};