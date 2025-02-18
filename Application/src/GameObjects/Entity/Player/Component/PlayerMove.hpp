#pragma once
#include "IEntityMove.hpp"
#include <iostream> 

class PlayerMove : public IEntityMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, bool dashing, std::shared_ptr<Collider> m_collider) override;

private:
    DX::XMVECTOR velocity = { 0.0f, 0.0f };
    DX::XMVECTOR dashDirection = { 0.0f, 0.0f };
    DX::XMVECTOR facingDirection = { 0.0f, 1.0f };

    float currentSpeed = 0.0f;
    float maxSpeed = 200.0f;
    float acceleration = 400.0f;
	float deceleration = 600.0f;


    float dashSpeed = 0.0f; 
	float maxDashSpeed = 2000.0f;
	float dashAcceleration = 4000.0f;

    float dashDuration = 0.12f;
    float dashCooldown = 0.1f;
    float dashCooldownTimer = 0.0f;
    float dashTimer = 0.0f;
	bool isDashing = false;
};
