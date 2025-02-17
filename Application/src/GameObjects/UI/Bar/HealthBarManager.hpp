#pragma once
#include "Heart.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

class HealthBarManager {
public:
    static void Initialize(size_t heartNumber);
    static void AddHeart(size_t healthIncrease);
    static void RemoveHeart(size_t healthDamage);

private:
    static std::vector<std::shared_ptr<IGameObject>> health;
    static int maxHealth;
    static int heartIndex;
};