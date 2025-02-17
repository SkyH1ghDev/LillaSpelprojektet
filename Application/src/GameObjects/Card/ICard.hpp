#pragma once

#include <memory>
#include <SpEngine/Assets/IScript.hpp>
#include <string>
#include <iostream>
#include <vector>


enum class CardType {
    Shotgun,
    Spread
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
    virtual void ActivateLvl1() = 0;
    virtual void ActivateLvl2() = 0;
    virtual void ActivateLvl3() = 0;
    CardType GetType();
    void ActivateLevel(size_t cardLevel);

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

    std::vector<std::shared_ptr<IScript>> m_scripts;
};


inline CardType ICard::GetType()
{
    return this->m_type;
}



inline void ICard::ActivateLevel(size_t cardLevel) {
    switch (cardLevel) {
    case 1:
        ActivateLvl1();
        break;
    case 2:
        ActivateLvl2();
        break;
    case 3:
        ActivateLvl3();
        break;

    default:
        std::cerr << "unknown cardlevel" << std::endl;
        break;
    }
}