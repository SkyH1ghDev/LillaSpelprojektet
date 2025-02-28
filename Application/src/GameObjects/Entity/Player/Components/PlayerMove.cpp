#include "PlayerMove.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Physics/PhysicsEngine.hpp>
#include <SpEngine/Clock/Clock.hpp>

DX::XMFLOAT2 PlayerMove::Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, const std::shared_ptr<Collider>& collider, EntityMoveData& moveData) {
    float deltaTime = Clock::GetDeltaTime();
    DX::XMVECTOR positionXMVector = XMLoadFloat2(&position);
    DX::XMVECTOR directionXMVector = DX::XMVector2Normalize(XMLoadFloat2(&direction));

    moveData.maxSpeed = StatSheet::GetMoveSpeed();

    //In the middle of the Dash
    /*if (isDashing) {

		dashSpeed += dashAcceleration * deltaTime;
        if (dashSpeed > maxDashSpeed)
            dashSpeed = maxDashSpeed;

        DX::XMVECTOR dashMovement = DX::XMVectorScale(dashDirection, dashSpeed * deltaTime);
        positionXMVector = DX::XMVectorAdd(positionXMVector, dashMovement);

        dashTimer -= deltaTime;

        if (dashTimer <= 0.0f) {
            isDashing = false;
            dashCooldownTimer = dashCooldown;
            dashSpeed = 0.0f;
        }

    }
    //Start the Dash
    else if (dashInput && dashCooldownTimer <= 0) {
        isDashing = true;
        dashTimer = dashDuration;
        dashSpeed = maxSpeed;

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
            dashCooldownTimer -= deltaTime;*/

    if (DX::XMVector2Length(directionXMVector).m128_f32[0] > 0.0f)
    {
        moveData.facingDirection = directionXMVector;
        moveData.currentSpeed += moveData.acceleration * deltaTime;

        if (moveData.currentSpeed > moveData.maxSpeed)
        {
            moveData.currentSpeed = moveData.maxSpeed;
        } 
    }
    else
    {
        moveData.currentSpeed -= moveData.deceleration * deltaTime;

        if (moveData.currentSpeed < 0)
        {
            moveData.currentSpeed = 0;
        }
    }

    moveData.velocity = DX::XMVectorScale(directionXMVector, moveData.currentSpeed);

    DX::XMVECTOR movement = DX::XMVectorScale(moveData.velocity, deltaTime);
    positionXMVector = DX::XMVectorAdd(positionXMVector, movement);
    //}


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

