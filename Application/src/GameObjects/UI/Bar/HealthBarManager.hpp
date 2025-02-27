#pragma once
#include "Heart.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

class HealthBarManager {
public:
    static void Initialize(size_t heartNumber);
    static void AddNewHeart(size_t heartNumber);
    static void DrawHearts();
    static void Cleanup();
    static void Reset();

private:
    static std::vector<std::shared_ptr<Heart>> health;
    static int maxHealth;
};