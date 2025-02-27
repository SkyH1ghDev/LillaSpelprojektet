#pragma once
#include "Heart.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

class HealthBarManager {
public:
    static void Initialize(size_t heartNumber);
    static void RefillHeart(size_t healthIncrease);
    static void RemoveHeart(size_t healthDamage);
    static void AddNewHeart(size_t heartNumber);
    static void Cleanup();
    static void Reset();

private:
    static std::vector<std::shared_ptr<IGameObject>> health;
    static int maxHealth;
    static int heartIndex;
};