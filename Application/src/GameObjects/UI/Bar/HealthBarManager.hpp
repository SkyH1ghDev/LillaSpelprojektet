#pragma once
#include "Heart.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <stack>

class HealthBarManager {
public:
    static void Initialize(size_t heartNumber);
    static void AddHeart();
    static void RemoveHeart(size_t healthDamage);

private:
    static std::stack<std::shared_ptr<IGameObject>> m_health;
};