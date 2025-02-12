#pragma once
#include "IMoveBase.hpp"
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <SpEngine/Input/KeyState.hpp>
#include <bitset>

class MoveUp : public IMoveBase, public IObserver
{
public:
    MoveUp() = default;
    ~MoveUp() override = default;
    MoveUp(const MoveUp& other) = default;
    MoveUp& operator=(const MoveUp& other) = default;
    MoveUp(MoveUp&& other) noexcept = default;
    MoveUp& operator=(MoveUp&& other) noexcept = default;

    void Update(std::optional<std::any> data) override;
};

inline void MoveUp::Update(std::optional<std::any> data)
{
    const float scale = (std::any_cast<std::bitset<4>>(data.value()) & std::bitset<4>(KeyState_Pressed)).any();
    m_moveDirection = {0, -1 * scale};
}
