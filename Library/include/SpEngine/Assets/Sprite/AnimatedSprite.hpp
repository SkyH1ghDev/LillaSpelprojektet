#pragma once
#include "StaticSprite.hpp"

#include <wrl/client.h>

namespace MW = Microsoft::WRL;

class AnimatedSprite : public ISprite
{
public:
    AnimatedSprite() = default;
    AnimatedSprite(const std::vector<std::shared_ptr<StaticSprite>>& sprites, const float& frameTime);
    ~AnimatedSprite() override = default;
    AnimatedSprite(const AnimatedSprite& other) = default;
    AnimatedSprite& operator=(const AnimatedSprite& other) = default;
    AnimatedSprite(AnimatedSprite&& other) noexcept = default;
    AnimatedSprite& operator=(AnimatedSprite&& other) noexcept = default;

    std::shared_ptr<StaticSprite> GetSprite(float time) const;
    void UpdateCurrentTime(const float& deltaTime);
    
private:
    std::vector<std::shared_ptr<StaticSprite>> m_sprites;
    float m_frameTime = 0.0f;
    float m_currTime = 0.0f;
};

inline AnimatedSprite::AnimatedSprite(const std::vector<std::shared_ptr<StaticSprite>>& sprites, const float& frameTime)
{
    m_sprites = sprites;
    m_frameTime = frameTime;
}

inline std::shared_ptr<StaticSprite> AnimatedSprite::GetSprite(float time) const 
{
    //+ 0.0001f to avoid division by zero
    int index = static_cast<int>(time / (m_frameTime + 0.0001f)) % static_cast<int>(m_sprites.size());
    
    return m_sprites.at(index);
}

inline void AnimatedSprite::UpdateCurrentTime(const float& deltaTime)
{
    this->m_currTime += deltaTime;
}