#pragma once
#include <SpEngine/Assets/Game/IGameObject.hpp>

class Heart : public IGameObject
{
public:
    Heart() = default;
    ~Heart() = default;
    Heart(const Heart& other) = default;
    Heart& operator=(const Heart& other) = default;
    Heart(Heart&& other) noexcept = default;
    Heart& operator=(Heart&& other) noexcept = default;


    void Update() override;
    void OnStart() override;
    void Reset() override;
    void UpdateHeart(bool heart);
};