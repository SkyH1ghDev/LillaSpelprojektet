#pragma once
#include <SpEngine/Assets/IGameObject.hpp>
#include <iostream>

#include "IUIVisible.hpp"

// Define an enum for the entity type
enum class BarType {
	Health,
	Mana
};

class Bar : public IGameObject
{
public:
    Bar() = default;
    ~Bar() = default;
    Bar(const Bar& other) = default;
    Bar& operator=(const Bar& other) = default;
    Bar(Bar&& other) noexcept = default;
    Bar& operator=(Bar&& other) noexcept = default;

    Bar(BarType type);
    void PerformVisible() { if (m_visible) m_visible->Visible(m_textureName, m_layerFloat, m_scaleFloat, m_position); }

    void Update() override;
    void OnStart() override;

private:
    std::shared_ptr<IUIVisible> m_visible;
	BarType m_type;

};