#pragma once
#include <SpEngine/Assets/IGameObject.hpp>
#include <iostream>

#include "IUIVisible.hpp"

// Define an enum for the entity type
enum class HeartType {
    Full,
    Empty
};

class Heart : public IGameObject
{
public:
    Heart() = default;
    ~Heart() = default;
    Heart(const Heart& other) = default;
    Heart& operator=(const Heart& other) = default;
    Heart(Heart&& other) noexcept = default;
    Heart& operator=(Heart&& other) noexcept = default;

    Heart(HeartType type);
    void PerformVisible() { if (m_visible) m_visible->Visible(m_textureName, m_layerFloat, m_scaleFloat, m_position); }

    void Update() override;
    void OnStart() override;
    void UpdateHeart(bool positive);
    

private:
    std::shared_ptr<IUIVisible> m_visible;
    HeartType m_type;
    bool heart_empty = true;

};