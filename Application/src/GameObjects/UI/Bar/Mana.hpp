#pragma once
#include <SpEngine/Assets/IGameObject.hpp>
#include <iostream>

#include "IUIVisible.hpp"
enum class ManaType {
    Ready
};


class Mana : public IGameObject
{
public:
    Mana() = default;
    ~Mana() = default;
    Mana(const Mana& other) = default;
    Mana& operator=(const Mana& other) = default;
    Mana(Mana&& other) noexcept = default;
    Mana& operator=(Mana&& other) noexcept = default;

    Mana(ManaType type);
    void PerformVisible() { if (m_visible) m_visible->Visible(m_textureName, m_layerFloat, m_scaleFloat, m_position); }

    void Update() override;
    void OnStart() override;
    void UpdateMana(bool positive, size_t manaCrystalIndex); //remove mana if negative, add mana if positive

private:
    std::shared_ptr<IUIVisible> m_visible;
    std::string textureNameUpdate;
    ManaType m_type;
};