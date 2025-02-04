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
    m_moveDirection = DX::XMVectorScale({1, 0}, (std::any_cast<std::bitset<4>>(data.value()) & std::bitset<4>(KeyState_Pressed)).any());
}
