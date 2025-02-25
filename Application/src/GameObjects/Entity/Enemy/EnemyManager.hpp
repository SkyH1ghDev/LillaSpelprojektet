#pragma once

#include <vector>
#include <memory>
#include "Entity.hpp"
#include "EnemyController.hpp"

class EnemyManager {
public:
    static bool IsTooCloseToOtherEntities(DX::XMFLOAT2 newPos, float minDistance);
    static void SpawnEnemies(std::shared_ptr<IGameObject> player, int numberOfEnemies);
    static void UpdateEnemies();
    static void Cleanup();

private:
    static std::vector<std::shared_ptr<IGameObject>> m_enemies;
    static std::shared_ptr<IGameObject> m_player;
    static int m_numberOfEnemies;
};
