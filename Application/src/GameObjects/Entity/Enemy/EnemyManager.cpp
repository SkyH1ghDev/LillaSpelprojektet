#include "EnemyManager.hpp"
#include "PoolManager.hpp"

#include <SpEngine/Manager/SceneManager.hpp>
#include <cmath>
#include <random>
#include <SpEngine/Math/SpMath.hpp>

// Define static members
std::vector<std::shared_ptr<IGameObject>> EnemyManager::m_enemies;
std::shared_ptr<IGameObject> EnemyManager::m_player;
RoundState EnemyManager::m_state = RoundState_Waiting;
int EnemyManager::m_numberOfEnemies = 0;
int EnemyManager::m_pointBudget = 6;
int EnemyManager::m_waveNumber = 0;

EnemyManager::EnemyManager(const std::shared_ptr<IGameObject>& player)
{
    m_player = player;

    // Initialize the pool with a certain number of enemies
    //PoolManager<Entity, EntityType>::Initialize(EntityType::Pawn, 10, "Pawn");
    PoolManager<Entity, EntityType>::Initialize(EntityType::Bishop, 20);
    //PoolManager<Entity, EntityType>::Initialize(EntityType::Knight, 5, "Knight");
    PoolManager<Entity, EntityType>::Initialize(EntityType::Rook, 3);
    //PoolManager<Entity, EntityType>::Initialize(EntityType::Queen, 2, "Queen");
}

void EnemyManager::OnStart()
{
    this->m_isAlive = true;
    SpawnEnemies();
}

void EnemyManager::Update()
{
    UpdateEnemies();
}

void EnemyManager::Reset()
 {
    m_enemies.clear();
    EnemyManager::m_state = RoundState_Waiting;
    EnemyManager::m_numberOfEnemies = 0;
    EnemyManager::m_pointBudget = 6;
    EnemyManager::m_waveNumber = 0;
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

void EnemyManager::SpawnEnemies()
{
    std::shared_ptr<IScene> testScene = SceneManager::GetCurrentScene();
    std::vector<std::string> enemiesToSpawn = CalculateEnemiesToSpawn();

    DX::XMFLOAT2 playerPos = m_player->GetPosition();
    
    constexpr float minDistanceFromPlayer = 50.0f; // Avoid spawning too close to player
    constexpr float minDistanceBetweenEnemies = 40.0f; // Avoid enemy clustering

    for (int i = 0; i < enemiesToSpawn.size(); ++i) {

        constexpr int maxAttempts = 100;
        for (int j = 0; j < maxAttempts; ++j)
        {
            DX::XMFLOAT2 randomPos =
            {
                SpMath::RandomReal<float>(90.0f, 580.0f),
                SpMath::RandomReal<float>(57.0f, 300.0f)
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
                CreateEnemy(enemiesToSpawn.at(i), randomPos);
                break;
            }
        }
    }
}

/*
// TODO: FIX, MISCALCULATES HOW MANY ENEMIES TO SPAWN FOR SOME REASON
*/

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
    
    EnemyPointData pointData = {};

    std::vector<std::string> entitiesToSpawn;

    int pointBudget = m_pointBudget;
    
    while (pointBudget > 0)
    {

        EnemySpawnChance chance = {};
        
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

void EnemyManager::CreateEnemy(const std::string& type, const DX::XMFLOAT2& position)
{
    // Convert the string type to EntityType (assuming you have a mapping)
    EntityType enemyType = ConvertStringToEntityType(type);

    // Retrieve an enemy from the pool
    std::shared_ptr<Entity> enemy = PoolManager<Entity, EntityType>::GetObject(enemyType, type);

    // Set the enemy's position and activate it
    enemy->SetPosition(position);
    enemy->Initialize();

    // Add the enemy to the list of active enemies
    m_enemies.push_back(enemy);
}

void EnemyManager::UpdateEnemies()
{
    switch (m_state)
    {
    case RoundState_Waiting:
        m_state = RoundState_WaveStarted;
        m_pointBudget += SpMath::RandomInteger<int>(1, 4);
        break;

    case RoundState_WaveStarted:
        m_enemies.erase
        (
            std::remove_if
            (
                m_enemies.begin(),
                m_enemies.end(),
                [](const std::shared_ptr<IGameObject>& enemy) {
                    if (!enemy || !enemy->IsActive()) {
                        // Return the enemy to the pool
                        std::shared_ptr<Entity> enemyEntity = std::dynamic_pointer_cast<Entity>(enemy);
                        PoolManager<Entity, EntityType>::ReturnObject(enemyEntity->GetType(), enemyEntity);
                        return true;
                    }
                    return false;
                }
            ),
            m_enemies.end()
        );

        if (m_enemies.empty())
        {
            ++m_waveNumber;
            SpawnEnemies();

            if (m_waveNumber % 3 == 0)
            {
                m_state = RoundState_Waiting;
                break;
            }
        }
        break;
    }
}

void EnemyManager::Cleanup()
{
    m_enemies.clear();
}

EntityType EnemyManager::ConvertStringToEntityType(const std::string& type)
{
    //if (type == "Pawn") return EntityType::Pawn;
    if (type == "Bishop") return EntityType::Bishop;
    //if (type == "Knight") return EntityType::Knight;
    if (type == "Rook") return EntityType::Rook;
    //if (type == "Queen") return EntityType::Queen;
    // Default to Pawn if no match is found
    return EntityType::Rook;
}