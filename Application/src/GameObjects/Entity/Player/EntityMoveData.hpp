#pragma once

#include <DirectXMath.h>

namespace DX = DirectX;

struct EntityMoveData
{
    DX::XMVECTOR velocity = { 0.0f, 0.0f };
    DX::XMVECTOR facingDirection = { 0.0f, 1.0f };
    DX::XMVECTOR dashDirection = { 0.0f, 0.0f };

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
