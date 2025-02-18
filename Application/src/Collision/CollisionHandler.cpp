#include "CollisionHandler.hpp"
#include "Entity.hpp"
#include "Projectile.hpp"
#include "SpEngine/Physics/PhysicsEngine.hpp"

CollisionHandler::CollisionHandler(int tileSize) : tileSize(tileSize) {}

void CollisionHandler::OnStart() {
    // This function runs once when the script is attached to a game object
    grid.clear();
}

GridCell CollisionHandler::GetTileForPosition(float x, float y) {
    return { static_cast<int>(std::floor(x / tileSize)),
             static_cast<int>(std::floor(y / tileSize)) };
}

void CollisionHandler::Update() {
    grid.clear(); // Reset grid each frame

    auto scene = SceneManager::GetScene("main");
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
    else if (objA->GetCollider()->GetLayer() == CollisionLayer::Enemy &&
        objB->GetCollider()->GetLayer() == CollisionLayer::AllyProjectile) {
        // Handle AllyProjectile hitting an enemy

        auto projectile = std::dynamic_pointer_cast<Projectile>(objB);
        auto entity = std::dynamic_pointer_cast<Entity>(objA);

        if (projectile && entity) {
            // Call the Perform functions
            projectile->PerformHit(); 
            entity->PerformTakeDamage(projectile->GetDamage());
        }
    }
}
