#include "PlayerDash.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Clock/Clock.hpp>
#include <SpEngine/Physics/PhysicsEngine.hpp>
#include <algorithm>

DX::XMFLOAT2 PlayerDash::Dash(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, const std::shared_ptr<Collider>& collider, const bool& dashInput, EntityMoveData& moveData)
{
    float deltaTime = Clock::GetDeltaTime();
    DX::XMVECTOR positionXMVector = XMLoadFloat2(&position);
    DX::XMVECTOR directionXMVector = DX::XMVector2Normalize(XMLoadFloat2(&direction));

    float maxSpeed = StatSheet::GetMoveSpeed();
    
    if (moveData.isDashing) {

		moveData.dashSpeed += moveData.dashAcceleration * deltaTime;
        moveData.dashSpeed = std::min(moveData.dashSpeed, moveData.maxDashSpeed);

        DX::XMVECTOR dashMovement = DX::XMVectorScale(moveData.dashDirection, moveData.dashSpeed * deltaTime);
        positionXMVector = DX::XMVectorAdd(positionXMVector, dashMovement);

        moveData.dashTimer -= deltaTime;

        if (moveData.dashTimer <= 0.0f) {
            moveData.isDashing = false;
            moveData.dashCooldownTimer = moveData.dashCooldown;
            moveData.dashSpeed = 0.0f;
        }
    }
    
    //Start the Dash
    else if (dashInput && moveData.dashCooldownTimer <= 0) {
        moveData.isDashing = true;
        moveData.dashTimer = moveData.dashDuration;
        moveData.dashSpeed = maxSpeed;

        if (DX::XMVector2Length(directionXMVector).m128_f32[0] > 0.0f) {
            moveData.dashDirection = directionXMVector;
            moveData.facingDirection = directionXMVector;
        }
        else {
            moveData.dashDirection = moveData.facingDirection;
        }
    
    }
    else
    {
        if (moveData.dashCooldownTimer > 0)
        {
            moveData.dashCooldownTimer -= deltaTime;
        }
    }

    moveData.velocity = DX::XMVectorScale(directionXMVector, moveData.currentSpeed);

    DX::XMVECTOR movement = DX::XMVectorScale(moveData.velocity, deltaTime);
    positionXMVector = DX::XMVectorAdd(positionXMVector, movement);
    
    DX::XMFLOAT2 newPosition;
    DX::XMStoreFloat2(&newPosition, positionXMVector);
    
    collider->UpdatePosition(newPosition);
    
    if (PhysicsEngine::WallEntityXCollision(collider))      
    {
        newPosition.x = position.x;
    }
    if (PhysicsEngine::WallEntityYCollision(collider))
    {
        newPosition.y = position.y;
    }
    
    return newPosition;
}
