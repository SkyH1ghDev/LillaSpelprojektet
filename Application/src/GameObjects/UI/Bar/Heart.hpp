#pragma once
#include <SpEngine/Assets/Game/IGameObject.hpp>

#include "IUIVisible.hpp"

class Heart : public IGameObject
{
public:
    Heart() = default;
    ~Heart() = default;
    Heart(const Heart& other) = default;
    Heart& operator=(const Heart& other) = default;
    Heart(Heart&& other) noexcept = default;
    Heart& operator=(Heart&& other) noexcept = default;

    void PerformVisible() { if (m_visible) m_visible->Visible(m_textureName, m_layerFloat, m_scaleFloat, m_position); }

    void Update() override;
    void OnStart() override;
    void Reset() override;
    void UpdateHeart(bool heart);
    

private:
    std::shared_ptr<IUIVisible> m_visible;
    bool heart_empty = true;

};