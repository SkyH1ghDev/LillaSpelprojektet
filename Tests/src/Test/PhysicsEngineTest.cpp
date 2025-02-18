#pragma once
#include <gtest/gtest.h>
#include <PhysicsEngine.hpp>
#include <Collider.hpp>

TEST(PhysicsEngine, ColliderColliderCollision1)
{
    //A clear collision
    Collider circle = Collider({ 0, 0 }, 1);
    Collider oval = Collider({ 1, 0 }, 1, 1.65f);
    bool returned = PhysicsEngine::ColliderColliderCollision(circle, oval);
    ASSERT_EQ(returned, true);
}

TEST(PhysicsEngine, ColliderColliderCollision2)
{
    //A clear miss
    Collider circle = Collider({ 0, 0 }, 1);
    Collider oval = Collider({ 3, 0 }, 1, 1.65f);
    bool returned = PhysicsEngine::ColliderColliderCollision(circle, oval);
    ASSERT_EQ(returned, false);
}

TEST(PhysicsEngine, ColliderColliderCollision3)
{
    //A super close miss
    Collider circle = Collider({ 0, 0 }, 1);
    Collider oval = Collider({ 2.01f, 0 }, 1, 1.65f);
    bool returned = PhysicsEngine::ColliderColliderCollision(circle, oval);
    ASSERT_EQ(returned, false);
}

TEST(PhysicsEngine, ColliderColliderCollision4)
{
    //A diagonal test
    Collider circle = Collider({ 0, 0 }, 1);
    Collider oval = Collider({ 1.6f, 1.6f }, 1, 1.65f);
    bool returned = PhysicsEngine::ColliderColliderCollision(circle, oval);
    ASSERT_EQ(returned, false);
}
