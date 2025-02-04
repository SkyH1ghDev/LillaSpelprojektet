#pragma once
#include "IMoveBase.hpp"
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

class MoveLeft : public IMoveBase, public IObserver
{
public:
    MoveLeft() = default;
    ~MoveLeft() override = default;
    MoveLeft(const MoveLeft& other) = default;
    MoveLeft& operator=(const MoveLeft& other) = default;
    MoveLeft(MoveLeft&& other) noexcept = default;
    MoveLeft& operator=(MoveLeft&& other) noexcept = default;

    void Update(std::optional<std::any> data) override;
};

inline void MoveLeft::Update(std::optional<std::any> data)
{
    const float scale = (std::any_cast<std::bitset<4>>(data.value()) & std::bitset<4>(KeyState_Pressed)).any();
    m_moveDirection = {-1 * scale, 0};
}
