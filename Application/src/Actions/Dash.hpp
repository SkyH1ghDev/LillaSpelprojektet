#pragma once
#include "IMoveBase.hpp"
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

class Dash : public IMoveBase, public IObserver
{
public:
    Dash() = default;
    ~Dash() override = default;
    Dash(const Dash& other) = default;
    Dash& operator=(const Dash& other) = default;
    Dash(Dash&& other) noexcept = default;
    Dash& operator=(Dash&& other) noexcept = default;

    void Update(std::optional<std::any> data) override;
};

inline void Dash::Update(std::optional<std::any> data)
{
    const float scale = (std::any_cast<std::bitset<4>>(data.value()) == std::bitset<4>(KeyState_Pressed)) ? 1.0f : 0.0f;
	m_isDashing = scale;
}