#pragma once
#include "IMoveBase.hpp"
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

class MoveRight : public IMoveBase, public IObserver
{
public:
    MoveRight() = default;
    ~MoveRight() override = default;
    MoveRight(const MoveRight& other) = default;
    MoveRight& operator=(const MoveRight& other) = default;
    MoveRight(MoveRight&& other) noexcept = default;
    MoveRight& operator=(MoveRight&& other) noexcept = default;

    void Update(std::optional<std::any> data) override;
};

inline void MoveRight::Update(std::optional<std::any> data)
{
    const float scale = (std::any_cast<std::bitset<4>>(data.value()) & std::bitset<4>(KeyState_Pressed)).any();
    m_moveDirection = {1 * scale, 0};
}
