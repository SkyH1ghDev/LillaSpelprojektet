#pragma once
#include "Mana.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

class ManaBarManager {
public:
    static void Initialize(size_t manaNumber);
    static void RefillManaShard(size_t manaNumber);
    static bool RemoveManaCrystal(size_t manaNumber);
    static void Cleanup();
    static void Reset();
    
private:
    static std::vector<std::shared_ptr<IGameObject>> manaBar;
    static int maxMana;
    static int manaBarIndex;
    static int manaCrystalIndex;
};