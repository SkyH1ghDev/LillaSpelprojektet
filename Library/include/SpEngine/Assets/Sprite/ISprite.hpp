#pragma once

class ISprite {
public:
    ISprite() = default;
    virtual ~ISprite() = default;
    ISprite(const ISprite& other) = default;
    ISprite& operator=(const ISprite& other) = default;
    ISprite(ISprite&& other) noexcept = default;
    ISprite& operator=(ISprite&& other) noexcept = default;

};