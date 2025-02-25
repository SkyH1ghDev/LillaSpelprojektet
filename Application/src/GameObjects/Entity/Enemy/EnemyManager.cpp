#include "EnemyManager.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <cmath>
#include <SpEngine/Clock/Clock.hpp>

// Define static members
std::vector<std::shared_ptr<IGameObject>> EnemyManager::m_enemies;
std::shared_ptr<IGameObject> EnemyManager::m_player;

float GetRandomFloat(float min, float max) {
    static std::random_device rd;  // Seed
    static std::mt19937 gen(rd()); // Random number generator
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

bool EnemyManager::IsTooCloseToOtherEntities(DX::XMFLOAT2 newPos, float minDistance) {
    for (const auto& enemy : EnemyManager::m_enemies) {
        if (enemy) {
            DX::XMFLOAT2 enemyPos = enemy->GetPosition();
            float dx = enemyPos.x - newPos.x;
            float dy = enemyPos.y - newPos.y;
            float distance = std::sqrt(dx * dx + dy * dy);
            if (distance < minDistance) {
                return true; // Too close to another enemy
            }
        }
    }
    return false;
}

void EnemyManager::SpawnEnemies(std::shared_ptr<IGameObject> player, int numberOfEnemies) {
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    m_player = player;
    DX::XMFLOAT2 playerPos = player->GetPosition();

    const float minDistanceFromPlayer = 50.0f; // Avoid spawning too close to player
    const float minDistanceBetweenEnemies = 30.0f; // Avoid enemy clustering

    int attempts = 0;
    const int maxAttempts = 100;

    for (int i = 0; i < numberOfEnemies; i++) {
        DX::XMFLOAT2 randomPos;
        bool validPosition = false;

        while (!validPosition && attempts < maxAttempts) {
            randomPos.x = GetRandomFloat(50.0f, 590.0f);
            randomPos.y = GetRandomFloat(27.0f, 310.0f);

            float dx = playerPos.x - randomPos.x;
            float dy = playerPos.y - randomPos.y;
            float distanceFromPlayer = std::sqrt(dx * dx + dy * dy);

            if (distanceFromPlayer >= minDistanceFromPlayer &&
                !IsTooCloseToOtherEntities(randomPos, minDistanceBetweenEnemies)) {
                validPosition = true;
            }
            attempts++;
        }

        if (!validPosition) {
            continue; // Skip this enemy if no valid position is found
        }

        std::shared_ptr<IGameObject> enemy = std::make_shared<Entity>(EntityType::Enemy, "Enemy");
        enemy->SetPosition(randomPos);
        enemy->OnStart();

        std::shared_ptr<IScript> enemyController = std::make_shared<EnemyController>(player);
        enemy->AttachScript(enemyController);

        testScene->AddGameObject(enemy);
        m_enemies.push_back(enemy);
    }
}

void EnemyManager::UpdateEnemies() {
    // Remove dead enemies
    m_enemies.erase(std::remove_if(m_enemies.begin(), m_enemies.end(),
        [](const std::shared_ptr<IGameObject>& enemy) { return !enemy || !enemy->IsActive(); }),
        m_enemies.end());

    // Respawn enemies if all are dead
    if (m_enemies.empty()) {
        m_enemies.clear();
        SpawnEnemies(m_player, 2); // Respawn a new wave
    }
}

void EnemyManager::Cleanup() {
    m_enemies.clear();
}
