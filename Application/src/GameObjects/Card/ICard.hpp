#pragma once

#include <memory>
#include <SpEngine/Assets/IScript.hpp>
#include <string>
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
    virtual void Activate() =0;
    CardType GetType();
    

protected:
    CardType m_type;
    std::string m_textureName;
    float m_layerFloat;
    float m_scaleFloat;

    float m_rotationFloat = 0.0;
    DX::XMFLOAT2 m_origonOffset = { 0, 0 };

    bool m_centerOrigin = false;
    bool m_isActive = true;
    bool m_shouldRender = false;

    std::vector<std::shared_ptr<IScript>> m_scripts;
};

//inline void ICard::AttachScript(const std::shared_ptr<IScript>& script) {
//    if (const auto it = std::ranges::find(m_scripts, script); it == m_scripts.end())
//    {
//        m_scripts.push_back(script);
//    }
//}

inline CardType ICard::GetType()
{
    return this->m_type;
}



