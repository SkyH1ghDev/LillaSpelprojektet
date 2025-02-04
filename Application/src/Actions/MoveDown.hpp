#pragma once
#include "IMoveBase.hpp"
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

class MoveDown : public IMoveBase, public IObserver
{
public:
    MoveDown() = default;
    ~MoveDown() override = default;
    MoveDown(const MoveDown& other) = default;
    MoveDown& operator=(const MoveDown& other) = default;
    MoveDown(MoveDown&& other) noexcept = default;
    MoveDown& operator=(MoveDown&& other) noexcept = default;

    void Update(std::optional<std::any> data) override;
};

inline void MoveDown::Update(std::optional<std::any> data)
{
    m_moveDirection = DX::XMVectorScale({0, 1}, (std::any_cast<std::bitset<4>>(data.value()) & std::bitset<4>(KeyState_Pressed)).any());

}
