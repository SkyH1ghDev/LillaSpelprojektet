#pragma once

class SpriteWrapper {
public:
    SpriteWrapper() = default;
    ~SpriteWrapper() = default;
    SpriteWrapper(const SpriteWrapper& other) = default;
    SpriteWrapper& operator=(const SpriteWrapper& other) = default;
    SpriteWrapper(SpriteWrapper&& other) noexcept = default;
    SpriteWrapper& operator=(SpriteWrapper&& other) noexcept = default;

private:
    std::vector<>
};