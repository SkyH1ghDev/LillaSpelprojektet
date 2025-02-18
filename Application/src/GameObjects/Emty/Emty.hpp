#pragma once
#include <memory>

#include <SpEngine/Assets/IGameObject.hpp>


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

private:

};
