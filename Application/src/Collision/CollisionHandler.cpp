#include "CollisionHandler.hpp"
#include "Entity.hpp"
#include "Projectile.hpp"
#include "PickUps.hpp"
#include "SpEngine/Physics/PhysicsEngine.hpp"
#include "StatSheet.hpp"
#include "HealthBarManager.hpp"

CollisionHandler::CollisionHandler(int tileSize) : tileSize(tileSize) {}

void CollisionHandler::OnStart() {
   
    grid.clear();
}

GridCell CollisionHandler::GetTileForPosition(float x, float y) {
    return { static_cast<int>(std::floor(x / tileSize)),
             static_cast<int>(std::floor(y / tileSize)) };
}

void CollisionHandler::Update() {
    grid.clear(); // Reset grid each frame

    auto scene = SceneManager::GetScene("game");
    if (!scene) return;

    auto objects = scene->GetGameObjectVec();
    for (const auto& obj : objects) {
        if (!obj->IsActive() || !obj->GetCollider()) continue;

        auto collider = obj->GetCollider();
        float radiusX = collider->GetRadiusX();
        float radiusY = collider->GetRadiusY();

        GridCell topLeft = GetTileForPosition(obj->GetPosition().x - radiusX, obj->GetPosition().y - radiusY);
        GridCell bottomRight = GetTileForPosition(obj->GetPosition().x + radiusX, obj->GetPosition().y + radiusY);

        for (int x = topLeft.x; x <= bottomRight.x; ++x) {
            for (int y = topLeft.y; y <= bottomRight.y; ++y) {
                grid[{x, y}].push_back(obj);
            }

        }
    }

    for (const auto& [cell, cellObjects] : grid) {
        for (size_t i = 0; i < cellObjects.size(); ++i) {
            for (size_t j = i + 1; j < cellObjects.size(); ++j) {
                auto objA = cellObjects[i];
                auto objB = cellObjects[j];

                auto colA = objA->GetCollider();
                auto colB = objB->GetCollider();

                if (colA && colB &&
                    colA->CanCollideWith(colB->GetLayer()) &&
                    colB->CanCollideWith(colA->GetLayer()) &&
                    PhysicsEngine::ColliderColliderCollision(colA, colB))
                {
                    HandleCollision(objA, objB);
                }
            }
        }
    }
}

void CollisionHandler::HandleCollision(const std::shared_ptr<IGameObject>& objA,
    const std::shared_ptr<IGameObject>& objB) { 
    if (objA->GetCollider()->GetLayer() == CollisionLayer::Player &&
        objB->GetCollider()->GetLayer() == CollisionLayer::EnemyProjectile) {
        // Handle EnemyProjectile hitting an ally

        auto projectile = std::dynamic_pointer_cast<Projectile>(objB);
        auto entity = std::dynamic_pointer_cast<Entity>(objA);

        if (projectile && entity) {
            // Call the Perform functions
            projectile->PerformHit();
            entity->PerformTakeDamage(projectile->GetDamage());
        }
    }
    else if (objA->GetCollider()->GetLayer() == CollisionLayer::EnemyProjectile &&
        objB->GetCollider()->GetLayer() == CollisionLayer::Player) {
        // Handle EnemyProjectile hitting an ally

        auto projectile = std::dynamic_pointer_cast<Projectile>(objA);
        auto entity = std::dynamic_pointer_cast<Entity>(objB);

        if (projectile && entity) {
            // Call the Perform functions
            projectile->PerformHit(); 
            entity->PerformTakeDamage(projectile->GetDamage());
        }
    }
    else if (objA->GetCollider()->GetLayer() == CollisionLayer::Enemy &&
        objB->GetCollider()->GetLayer() == CollisionLayer::AllyProjectile) {
        // Handle AllyProjectile hitting an enemy

        auto projectile = std::dynamic_pointer_cast<Projectile>(objB);
        auto entity = std::dynamic_pointer_cast<Entity>(objA);

        if (projectile && entity) {
            // Call the Perform functions
            if (!projectile->GetHasHit())
            {
                projectile->PerformHit();
                entity->PerformTakeDamage(projectile->GetDamage());
            }
        }
    }
    else if (objA->GetCollider()->GetLayer() == CollisionLayer::AllyProjectile &&
        objB->GetCollider()->GetLayer() == CollisionLayer::Enemy) {
        // Handle AllyProjectile hitting an enemy

        auto projectile = std::dynamic_pointer_cast<Projectile>(objA);
        auto entity = std::dynamic_pointer_cast<Entity>(objB);

        if (projectile && entity) {
            // Call the Perform functions
            if (!projectile->GetHasHit())
            {
                projectile->PerformHit();
                entity->PerformTakeDamage(projectile->GetDamage());
            }
        }
    }
    else if (objA->GetCollider()->GetLayer() == CollisionLayer::Player &&
        objB->GetCollider()->GetLayer() == CollisionLayer::Enemy)
    {
        //Enemy - Player collision
        auto player = std::dynamic_pointer_cast<Entity>(objA);
        auto enemy = std::dynamic_pointer_cast<Entity>(objB);

        if (player && enemy && enemy->GetState() != EntityState::Dying && enemy->GetState() != EntityState::Spawning && !player->HasIFrame())
        {
            player->PerformTakeDamage(1);

            // Compute knockback direction (Player moves away from Enemy)
            DX::XMFLOAT2 playerPos = player->GetPosition();
            DX::XMFLOAT2 enemyPos = enemy->GetPosition();

            DX::XMVECTOR playerVec = DX::XMLoadFloat2(&playerPos);
            DX::XMVECTOR enemyVec = DX::XMLoadFloat2(&enemyPos);

            DX::XMVECTOR knockbackDir = DX::XMVectorSubtract(playerVec, enemyVec);
            knockbackDir = DX::XMVector3Normalize(knockbackDir);  // Normalize the direction

            // Define knockback strength
            float knockbackForce = 50.0f;

            // Scale the vector
            DX::XMVECTOR knockbackVector = DX::XMVectorScale(knockbackDir, knockbackForce);

            DX::XMFLOAT2 knockback;
            DX::XMStoreFloat2(&knockback, knockbackVector);

            // Move the player

            player->SetIsStunned(true);
            player->PerformMove(knockback, true);
            player->SetIsStunned(false);
        }
    }
    else if (objB->GetCollider()->GetLayer() == CollisionLayer::Player &&
        objA->GetCollider()->GetLayer() == CollisionLayer::Enemy)
    {
        //Enemy - Player collision
        auto player = std::dynamic_pointer_cast<Entity>(objB);
        auto enemy = std::dynamic_pointer_cast<Entity>(objA);

        if (player && enemy && enemy->GetState() != EntityState::Dying && enemy->GetState() != EntityState::Spawning && !player->HasIFrame())
        {
            player->PerformTakeDamage(1);

            // Compute knockback direction (Player moves away from Enemy)
            DX::XMFLOAT2 playerPos = player->GetPosition();
            DX::XMFLOAT2 enemyPos = enemy->GetPosition();

            DX::XMVECTOR playerVec = DX::XMLoadFloat2(&playerPos);
            DX::XMVECTOR enemyVec = DX::XMLoadFloat2(&enemyPos);

            DX::XMVECTOR knockbackDir = DX::XMVectorSubtract(playerVec, enemyVec);
            knockbackDir = DX::XMVector3Normalize(knockbackDir);  // Normalize the direction

            // Define knockback strength
            float knockbackForce = 50.0f;

            // Scale the vector
            DX::XMVECTOR knockbackVector = DX::XMVectorScale(knockbackDir, knockbackForce);

            DX::XMFLOAT2 knockback;
            DX::XMStoreFloat2(&knockback, knockbackVector);

            // Move the player
            player->SetIsStunned(true);
            player->PerformMove(knockback, true);
            player->SetIsStunned(false);
        }
    }
    else if (objB->GetCollider()->GetLayer() == CollisionLayer::DisruptorWave &&
        objA->GetCollider()->GetLayer() == CollisionLayer::EnemyProjectile) 
    {
            // Handle destructive AllyProjectile hitting an enemyProjectile

            auto allyProjectile = std::dynamic_pointer_cast<Projectile>(objA);
            auto enemyProjectile = std::dynamic_pointer_cast<Projectile>(objB);

            if (allyProjectile && enemyProjectile) 
            {
                // Call the Perform functions
                allyProjectile->PerformHit();
                enemyProjectile->PerformHit();
            }
    }
    else if (objA->GetCollider()->GetLayer() == CollisionLayer::DisruptorWave &&
        objB->GetCollider()->GetLayer() == CollisionLayer::EnemyProjectile)
    {
            // Handle destructive AllyProjectile hitting an enemyProjectile

            auto allyProjectile = std::dynamic_pointer_cast<Projectile>(objA);
            auto enemyProjectile = std::dynamic_pointer_cast<Projectile>(objB);

            if (allyProjectile && enemyProjectile)
            {
                // Call the Perform functions
                allyProjectile->PerformHit();
                enemyProjectile->PerformHit();
            }
    }
    else if (objA->GetCollider()->GetLayer() == CollisionLayer::PickUps &&
        objB->GetCollider()->GetLayer() == CollisionLayer::Player)
        {
            auto player = std::dynamic_pointer_cast<Entity>(objA);
            auto pickUp = std::dynamic_pointer_cast<PickUps>(objB);
            
            if (player && pickUp)
            {
                StatSheet::IncreaseHealth(1);
                HealthBarManager::DrawHearts();
                pickUp->Reset();
            }
        }
    else if (objB->GetCollider()->GetLayer() == CollisionLayer::PickUps &&
        objA->GetCollider()->GetLayer() == CollisionLayer::Player)
        {
            auto player = std::dynamic_pointer_cast<Entity>(objA);
            auto pickUp = std::dynamic_pointer_cast<PickUps>(objB);

            if (player && pickUp)
            {
                StatSheet::IncreaseHealth(1);
                HealthBarManager::DrawHearts();
                pickUp->Reset();
            }
         }
}
