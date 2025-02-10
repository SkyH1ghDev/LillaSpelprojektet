#pragma once

class AnimatedSprite
{
public:
    AnimatedSprite();
    ~AnimatedSprite();
    AnimatedSprite(const AnimatedSprite& other);
    AnimatedSprite& operator=(const AnimatedSprite& other);
    AnimatedSprite(AnimatedSprite&& other) noexcept;
    AnimatedSprite& operator=(AnimatedSprite&& other) noexcept;

private:

};
