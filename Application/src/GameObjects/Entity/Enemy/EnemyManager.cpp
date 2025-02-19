#include "EnemyManager.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

// Define static members
std::vector<std::shared_ptr<IGameObject>> EnemyManager::m_enemies;
std::shared_ptr<IGameObject> EnemyManager::m_player;

float GetRandomFloat(float min, float max) {
    static std::random_device rd;  // Seed
    static std::mt19937 gen(rd()); // Random number generator
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

void EnemyManager::SpawnEnemies(std::shared_ptr<IGameObject> player, int numberOfEnemies) {
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");

    for (int i = 0; i < numberOfEnemies; i++) {

        float randomX = GetRandomFloat(150.0f, 300.0f);
        float randomY = GetRandomFloat(150.0f, 300.0f);

        std::shared_ptr<IGameObject> enemy = std::make_shared<Entity>(EntityType::Enemy, "Enemy");
        enemy->SetPosition(DX::XMFLOAT2(randomX, randomY)); // Set position

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

