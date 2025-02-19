#pragma once
#include <gtest/gtest.h>
#include <Collider.hpp>

TEST(Collider, Layer)
{
    Collider test = Collider({ 0, 0 }, 1, CollisionLayer::Player, CollisionLayer::None);
    ASSERT_EQ(test.GetLayer(), CollisionLayer::Player);
}

TEST(Collider, Mask)
{
    Collider test = Collider({ 0, 0 }, 1, CollisionLayer::None, CollisionLayer::Enemy);
    ASSERT_EQ(test.GetMask(), CollisionLayer::Enemy);
}

TEST(Collider, PositionX)
{
    Collider test = Collider({ 12, 1 }, 1, CollisionLayer::All, CollisionLayer::All);
    ASSERT_EQ(test.GetPosition().x, 12);
}

TEST(Collider, PositionY)
{
    Collider test = Collider({ 1, 13 }, 1, CollisionLayer::All, CollisionLayer::All);
    ASSERT_EQ(test.GetPosition().y, 13);
}

TEST(Collider, Radius)
{
    Collider test = Collider({ 0, 0 }, 5, CollisionLayer::All, CollisionLayer::All);
    ASSERT_EQ(test.GetRadius(), 5);
}

TEST(Collider, RadiusX)
{
    Collider test = Collider({ 0, 0 }, 5, 2, CollisionLayer::All, CollisionLayer::All);
    ASSERT_EQ(test.GetRadiusX(), 5);
}

TEST(Collider, RadiusY)
{
    Collider test = Collider({ 0, 0 }, 5, 2, CollisionLayer::All, CollisionLayer::All);
    ASSERT_EQ(test.GetRadiusY(), 10);
}
