#include "EnemyManager.hpp"
#include "EnemyController.hpp"

#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Math/SpMath.hpp>

// Define static members
std::vector<std::shared_ptr<IGameObject>> EnemyManager::m_enemies;
std::shared_ptr<IGameObject> EnemyManager::m_player;
int EnemyManager::m_numberOfEnemies = 0;
int EnemyManager::m_pointBudget = 3;

EnemyManager::EnemyManager(const std::shared_ptr<IGameObject>& player)
{
    m_player = player;
}

void EnemyManager::OnStart()
{
    SpawnEnemies(m_player);
}

void EnemyManager::Update()
{
    UpdateEnemies();
}

bool EnemyManager::IsTooCloseToOtherEnemies(DX::XMFLOAT2 newPos, float minDistance)
{
    for (const auto& enemy : m_enemies)
    {
        if (enemy)
        {
            DX::XMFLOAT2 enemyPos = enemy->GetPosition();
            
            float dx = enemyPos.x - newPos.x;
            float dy = enemyPos.y - newPos.y;
            float distance = std::sqrt(dx * dx + dy * dy);
            
            if (distance < minDistance)
            {
                return true; // Too close to another enemy
            }
        }
    }
    return false;
}

void EnemyManager::SpawnEnemies(const std::shared_ptr<IGameObject>& player)
{
    std::shared_ptr<IScene> testScene = SceneManager::GetCurrentScene();
    m_player = player;
    DX::XMFLOAT2 playerPos = player->GetPosition();
    std::vector<std::string> enemiesToSpawn = CalculateEnemiesToSpawn();

    constexpr float minDistanceFromPlayer = 50.0f; // Avoid spawning too close to player
    constexpr float minDistanceBetweenEnemies = 30.0f; // Avoid enemy clustering

    for (int i = 0; i < enemiesToSpawn.size(); ++i) {

        constexpr int maxAttempts = 100;
        for (int j = 0; j < maxAttempts; ++j)
        {
            DX::XMFLOAT2 randomPos =
            {
                SpMath::RandomReal<float>(50.0f, 590.0f),
                SpMath::RandomReal<float>(27.0f, 310.0f)
            };
            
            float dx = playerPos.x - randomPos.x;
            float dy = playerPos.y - randomPos.y;
            float distanceFromPlayer = std::sqrt(dx * dx + dy * dy);

            if
            (
                distanceFromPlayer >= minDistanceFromPlayer
                &&
                !IsTooCloseToOtherEnemies(randomPos, minDistanceBetweenEnemies)
            )
            {
                CreateEnemy(enemiesToSpawn.at(i), randomPos, player);
                break;
            }
        }
    }
}

std::vector<std::string> EnemyManager::CalculateEnemiesToSpawn()
{
    float successPercentage = 1.0f;

    struct EnemySpawnChance
    {
        float Pawn;
        float Bishop;
        float Knight;
        float Rook;
        float Queen;
    };
    
    EnemySpawnChance chance = {};
    EnemyPointData pointData = {};

    std::vector<std::string> entitiesToSpawn;

    int pointBudget = m_pointBudget;
    
    while (pointBudget > 0)
    {

        // Set percent odds of spawning a certain type
        if (pointBudget < 3)
        {
            // PAWN IS GUARANTEED   
        }
        else if (pointBudget < 5)
        {
            chance.Bishop = SpMath::RandomReal<float>(0.2f, 0.4f);
            chance.Knight = SpMath::RandomReal<float>(0.2f, 0.4f) + chance.Bishop;
        }
        else if (pointBudget < 9)
        {
            chance.Rook = SpMath::RandomReal<float>(0.1f, 0.2f);
            chance.Bishop = SpMath::RandomReal<float>(0.2f, 0.3f) + chance.Rook;
            chance.Knight = SpMath::RandomReal<float>(0.2f, 0.3f) + chance.Bishop;
        }
        else
        {
            chance.Queen = SpMath::RandomReal<float>(0.0f, 0.05f);
            chance.Rook = SpMath::RandomReal<float>(0.2f, 0.3f) + chance.Queen;
            chance.Bishop = SpMath::RandomReal<float>(0.1f, 0.25f) + chance.Rook;
            chance.Knight = SpMath::RandomReal<float>(0.1f, 0.25f) + chance.Bishop;
        }

        float rand = SpMath::RandomReal<float>(0.0f, 1.0f);

        // TODO: ADD SPAWNNING FOR ALL TYPES OF ENEMIES
        if (rand < chance.Queen)
        {
            entitiesToSpawn.push_back("Queen");
            pointBudget -= pointData.Queen;
            successPercentage -= SpMath::RandomReal<float>(0.4f, 0.55f);
        }
        else if (rand < chance.Rook)
        {
            entitiesToSpawn.push_back("Rook");
            pointBudget -= pointData.Rook;
            successPercentage -= SpMath::RandomReal<float>(0.10f, 0.25f);
        }
        else if (rand < chance.Bishop)
        {
            entitiesToSpawn.push_back("Bishop");
            pointBudget -= pointData.Bishop;
            successPercentage -= SpMath::RandomReal<float>(0.0f, 0.15f);
        }
        else if (rand < chance.Knight)
        {
            entitiesToSpawn.push_back("Knight");
            pointBudget -= pointData.Knight;
            successPercentage -= SpMath::RandomReal<float>(0.0f, 0.15f);
        }
        else
        {
            entitiesToSpawn.push_back("Pawn");
            pointBudget -= pointData.Pawn;
            successPercentage -= SpMath::RandomReal<float>(0.0f, 0.10f);
        }
            
        if (SpMath::RandomReal<float>(0.0f, 1.0f) > successPercentage)
        {
            break;
        }
    }

    return entitiesToSpawn;
}

void EnemyManager::CreateEnemy(const std::string& type, const DX::XMFLOAT2& position, const std::shared_ptr<IGameObject>& player)
{
    std::shared_ptr<IScene> currScene = SceneManager::GetCurrentScene();
    
    std::shared_ptr<Entity> enemy = std::make_shared<Entity>(EntityType::Enemy, type);
    enemy->SetPosition(position);
    enemy->InitializeValues();
    
    std::shared_ptr<EnemyController> enemyController = std::make_shared<EnemyController>(player);
    enemy->AttachScript(enemyController);

    currScene->AddGameObject(enemy);
    m_enemies.push_back(enemy);
}


void EnemyManager::UpdateEnemies()
{
    // Remove dead enemies
    m_enemies.erase
    (
        std::remove_if
        (
            m_enemies.begin(),
            m_enemies.end(),
        [](const std::shared_ptr<IGameObject>& enemy) { return !enemy || !enemy->IsActive(); }
        ),
        m_enemies.end()
    );

    // Respawn enemies if all are dead
    if (m_enemies.empty())
    {
        SpawnEnemies(m_player); // Respawn a new wave
        m_pointBudget += SpMath::RandomInteger<int>(1, 4);
    }
}

void EnemyManager::Cleanup()
{
    m_enemies.clear();
}
