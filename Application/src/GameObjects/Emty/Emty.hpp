#pragma once

#include <SpEngine/Assets/Game/IGameObject.hpp>

class Emty : public IGameObject
{
public:

    Emty() = default;
    ~Emty() override = default;
    Emty(const Emty& other) = default;
    Emty& operator=(const Emty& other) = default;
    Emty(Emty&& other) noexcept = default;
    Emty& operator=(Emty&& other) noexcept = default;

    void Update() override;
    void OnStart() override;
    void Reset() override;
};
