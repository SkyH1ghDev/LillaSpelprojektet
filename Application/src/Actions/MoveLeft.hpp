#pragma once
#include "IMoveBase.hpp"
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>

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
    m_moveDirection = DX::XMVectorScale({-1, 0}, std::any_cast<bool>(data.value()));
}
