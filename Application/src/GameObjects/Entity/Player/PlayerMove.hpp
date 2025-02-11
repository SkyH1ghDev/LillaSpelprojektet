#pragma once
#include "IEntityMove.hpp"

class PlayerMove : public IEntityMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, bool dashing) override;

private:
    DX::XMVECTOR velocity = { 0.0f, 0.0f };
    float acceleration = 400.0f;
	float deceleration = 600.0f;
	float maxVelocity = 200.0f;
    float friction = 0.3f;

    float dashSpeed = 400.0f; 
    float dashDuration = 0.1f;
    float dashCooldownTimer = 0.0f;
    float dashCooldown = 0.1f;
    float dashTimer = 0.0f;
	bool isDashing = false;

    DX::XMVECTOR dashDirection = { 0.0f, 0.0f };
	DX::XMVECTOR facingDirection = { 0.0f, 1.0f };
};
