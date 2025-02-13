#pragma once

#include <memory>
#include <SpEngine/Assets/IScript.hpp>
#include <string>
#include <vector>
class ICard : public std::enable_shared_from_this<ICard>
{
public:

	ICard() = default;
    virtual ~ICard() {}
    ICard(const ICard& other) = default;
    ICard& operator=(const ICard& other) = default;
    ICard(ICard&& other) noexcept = default;
    ICard& operator=(ICard&& other) noexcept = default;

    

protected:
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


