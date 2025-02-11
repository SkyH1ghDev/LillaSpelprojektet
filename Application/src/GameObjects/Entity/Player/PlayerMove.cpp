#include "PlayerMove.hpp"

#include <SpEngine/Clock/Clock.hpp>

DX::XMFLOAT2 PlayerMove::Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, bool dashInput) {
    float deltaTime = Clock::GetDeltaTime();
    DX::XMVECTOR positionXMVector = XMLoadFloat2(&position);
    DX::XMVECTOR directionXMVector = DX::XMVector2Normalize(XMLoadFloat2(&direction));

    //In the middle of the Dash
    if (isDashing) {
        
        DX::XMVECTOR dashMovement = DX::XMVectorScale(dashDirection, dashSpeed * deltaTime);
        positionXMVector = DX::XMVectorAdd(positionXMVector, dashMovement);

        dashTimer -= deltaTime;

        if (dashTimer <= 0.0f) {
            isDashing = false;
			dashCooldownTimer = dashCooldown;
        }

	}
	//Start the Dash
	else if (dashInput && dashCooldownTimer <= 0) {
        isDashing = true;
        dashTimer = dashDuration;

        if (DX::XMVector2Length(directionXMVector).m128_f32[0] > 0.0f) {
            dashDirection = directionXMVector;
			facingDirection = directionXMVector;
		}
        else {
            dashDirection = facingDirection;
        }

    }
	//Regular movement
    else {
		if (dashCooldownTimer > 0)
			dashCooldownTimer -= deltaTime;

        DX::XMVECTOR movement = DX::XMVectorScale(directionXMVector, 250.0f * Clock::GetDeltaTime());
        positionXMVector = DX::XMVectorAdd(positionXMVector, movement);
		
        if(DirectX::XMVector2Length(directionXMVector).m128_f32[0] > 0.0f)
            facingDirection = directionXMVector;
    }


    DX::XMFLOAT2 newPosition;
    DX::XMStoreFloat2(&newPosition, positionXMVector);

    return newPosition;
}

