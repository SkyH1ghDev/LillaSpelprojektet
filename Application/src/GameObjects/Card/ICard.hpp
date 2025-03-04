#pragma once

#include <memory>
#include <SpEngine/Assets/Game/IScript.hpp>
#include <string>
#include <iostream>
#include <vector>


enum class CardType {
    Shotgun,
    Spread,
    Heal,
    Sniper,
    Disruptor,
    RangeBuff
};

class ICard : public std::enable_shared_from_this<ICard>
{
public:

	ICard() = default;
    virtual ~ICard() {}
    ICard(const ICard& other) = default;
    ICard& operator=(const ICard& other) = default;
    ICard(ICard&& other) noexcept = default;
    ICard& operator=(ICard&& other) noexcept = default;
    

    //void AttachScript(const std::shared_ptr<IScript>& script);
    virtual void ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) = 0;
    virtual void ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) = 0;
    virtual void ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) = 0;
    virtual void SetCardTexture(size_t cardLevel) = 0;
    std::string GetCardTexture();
    CardType GetType();
    void ActivateLevel(size_t cardLevel, DX::XMFLOAT2 position, DX::XMFLOAT2 target);

protected:
    CardType m_type;
    std::string m_textureName;
    float m_layerFloat = 0.5;
    float m_scaleFloat = 1.0;

    float m_rotationFloat = 0.0;
    DX::XMFLOAT2 m_origonOffset = { 0, 0 };

    bool m_centerOrigin = false;
    bool m_isActive = true;
    bool m_shouldRender = false;
    bool m_isAlive = true;

    std::vector<std::shared_ptr<IScript>> m_scripts;
};

inline CardType ICard::GetType()
{
    return this->m_type;
}


inline std::string ICard::GetCardTexture()
{
    return this->m_textureName;
}



inline void ICard::ActivateLevel(size_t cardLevel, DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
    switch (cardLevel) {
    case 1:
        ActivateLvl1(position, target);
        break;
    case 2:
        ActivateLvl2(position, target);
        break;
    case 3:
        ActivateLvl3(position, target);
        break;
    default:
        std::cerr << "unknown cardlevel" << std::endl;
        break;
    }
}