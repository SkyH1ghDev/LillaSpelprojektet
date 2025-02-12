#include "EnemyManager.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

// Define static members
std::vector<std::shared_ptr<IGameObject>> EnemyManager::m_enemies;
std::shared_ptr<IGameObject> EnemyManager::m_player;


void EnemyManager::SpawnEnemies(std::shared_ptr<IGameObject> player, int numberOfEnemies) {
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");

    const float minX = 100.0f, maxX = 500.0f; // X-Axis range
    const float minY = 100.0f, maxY = 500.0f; // Y-Axis range

    for (int i = 0; i < numberOfEnemies; i++) {

        std::shared_ptr<IGameObject> enemy = std::make_shared<Entity>(EntityType::Enemy);
        enemy->SetPosition(DX::XMFLOAT2(100*(i+1), 100*(i+1))); // Set position

        std::shared_ptr<IScript> enemyController = std::make_shared<EnemyController>(player);
        enemy->AttachScript(enemyController);

        testScene->AddGameObject(enemy);
        m_enemies.push_back(enemy); // Store for future updates
    }
}

void EnemyManager::UpdateEnemies() {
    for (auto& enemy : m_enemies) {
        if (enemy) {
            enemy->Update(); // Assuming `IGameObject` has an `Update()` method
        }
    }
}

void EnemyManager::Cleanup() {
    m_enemies.erase(std::remove_if(m_enemies.begin(), m_enemies.end(),
        [](const std::shared_ptr<IGameObject>& enemy) { return !enemy; }),
        m_enemies.end());
}
