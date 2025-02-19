#pragma once
#include <gtest/gtest.h>
#include <PhysicsEngine.hpp>
#include <Collider.hpp>

TEST(PhysicsEngine, ColliderColliderCollision1)
{
    //A clear collision
    Collider circle = Collider({ 0, 0 }, 1, CollisionLayer::All, CollisionLayer::All);
    Collider oval = Collider({ 1, 0 }, 1, 1.65f, CollisionLayer::All, CollisionLayer::All);
    std::shared_ptr<Collider> col1 = std::make_unique<Collider>(circle);
    std::shared_ptr<Collider> col2 = std::make_unique<Collider>(oval);
    bool returned = PhysicsEngine::ColliderColliderCollision(col1, col2);
    ASSERT_EQ(returned, true);
}

TEST(PhysicsEngine, ColliderColliderCollision2)
{
    //A clear miss
    Collider circle = Collider({ 0, 0 }, 1, CollisionLayer::All, CollisionLayer::All);
    Collider oval = Collider({ 3, 0 }, 1, 1.65f, CollisionLayer::All, CollisionLayer::All);
    std::shared_ptr<Collider> col1 = std::make_unique<Collider>(circle);
    std::shared_ptr<Collider> col2 = std::make_unique<Collider>(oval);
    bool returned = PhysicsEngine::ColliderColliderCollision(col1, col2);
    ASSERT_EQ(returned, false);
}

TEST(PhysicsEngine, ColliderColliderCollision3)
{
    //A super close miss
    Collider circle = Collider({ 0, 0 }, 1, CollisionLayer::All, CollisionLayer::All);
    Collider oval = Collider({ 2.01f, 0 }, 1, 1.65f, CollisionLayer::All, CollisionLayer::All);
    std::shared_ptr<Collider> col1 = std::make_unique<Collider>(circle);
    std::shared_ptr<Collider> col2 = std::make_unique<Collider>(oval);
    bool returned = PhysicsEngine::ColliderColliderCollision(col1, col2);
    ASSERT_EQ(returned, false);
}

TEST(PhysicsEngine, ColliderColliderCollision4)
{
    //A diagonal hit
    Collider circle = Collider({ 0, 0 }, 1, CollisionLayer::All, CollisionLayer::All);
    Collider oval = Collider({ 1.59f, 1.59f }, 1, 1.65f, CollisionLayer::All, CollisionLayer::All);
    std::shared_ptr<Collider> col1 = std::make_unique<Collider>(circle);
    std::shared_ptr<Collider> col2 = std::make_unique<Collider>(oval);
    bool returned = PhysicsEngine::ColliderColliderCollision(col1, col2);
    ASSERT_EQ(returned, true);
}

TEST(PhysicsEngine, ColliderColliderCollision5)
{
    //A diagonal miss
    Collider circle = Collider({ 0, 0 }, 1, CollisionLayer::All, CollisionLayer::All);
    Collider oval = Collider({ 1.6f, 1.6f }, 1, 1.65f, CollisionLayer::All, CollisionLayer::All);
    std::shared_ptr<Collider> col1 = std::make_unique<Collider>(circle);
    std::shared_ptr<Collider> col2 = std::make_unique<Collider>(oval);
    bool returned = PhysicsEngine::ColliderColliderCollision(col1, col2);
    ASSERT_EQ(returned, false);
}
