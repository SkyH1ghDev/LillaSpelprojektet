#pragma once
#include "IMoveBase.hpp"
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>

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
    m_moveDirection = DX::XMVectorScale({0, -1}, std::any_cast<bool>(data.value()));
}
