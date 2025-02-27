#pragma once

#include <SpEngine/Assets/Game/IGameObject.hpp>

class Empty : public IGameObject
{
public:

    Empty() = default;
    ~Empty() override = default;
    Empty(const Empty& other) = default;
    Empty& operator=(const Empty& other) = default;
    Empty(Empty&& other) noexcept = default;
    Empty& operator=(Empty&& other) noexcept = default;

    void Update() override;
    void OnStart() override;
    void Reset() override;
};
