#include "EnemyManager.hpp"
#include "PoolManager.hpp"

#include <SpEngine/Manager/SceneManager.hpp>
#include <cmath>
#include <map>
#include <random>
#include <SpEngine/Math/SpMath.hpp>
#include "DeckManager.hpp"
#include <SpEngine/Audio/Sound.hpp>
#include "ProjectileManager.hpp"

// Define static members
std::vector<std::shared_ptr<IGameObject>> EnemyManager::m_enemies;
std::shared_ptr<IGameObject> EnemyManager::m_player;
RoundState EnemyManager::m_state = RoundState_Waiting;
int EnemyManager::m_numberOfEnemies = 0;
int EnemyManager::m_pointBudget = 0;
int EnemyManager::m_waveNumber = 0;
int EnemyManager::m_roundCount = 0;

std::vector<std::unordered_map<EntityType, std::uint16_t>> EnemyManager::m_spawnWeights =
{
    // Round 1
    {
        {EntityType::Pawn, 500},
        {EntityType::PawnAlt, 500},
        {EntityType::Bishop, 0},
        {EntityType::BishopAlt, 0},
        {EntityType::Rook, 0},
        {EntityType::RookAlt, 0}
    },
    
    // Round 2
    {
        {EntityType::Pawn, 350},
        {EntityType::PawnAlt, 350},
        {EntityType::Bishop, 150},
        {EntityType::BishopAlt, 150},
        {EntityType::Rook, 0},
        {EntityType::RookAlt, 0}
    },
    
    // Round 3
    {
        {EntityType::Pawn, 250},
        {EntityType::PawnAlt, 250},
        {EntityType::Bishop, 200},
        {EntityType::BishopAlt, 200},
        {EntityType::Rook, 50},
        {EntityType::RookAlt, 50}
    },
    
    // Round 4
    {
        {EntityType::Pawn, 200},
        {EntityType::PawnAlt, 200},
        {EntityType::Bishop, 200},
        {EntityType::BishopAlt, 200},
        {EntityType::Rook, 100},
        {EntityType::RookAlt, 100}
    },
    
    // Round 5
    {
        {EntityType::Pawn, 150},
        {EntityType::PawnAlt, 150},
        {EntityType::Bishop, 250},
        {EntityType::BishopAlt, 250},
        {EntityType::Rook, 100},
        {EntityType::RookAlt, 100}
    },
    
    // Round 6
    {
        {EntityType::Pawn, 100},
        {EntityType::PawnAlt, 100},
        {EntityType::Bishop, 250},
        {EntityType::BishopAlt, 250},
        {EntityType::Rook, 150},
        {EntityType::RookAlt, 150}
    },
    
    // Round 7
    {
        {EntityType::Pawn, 50},
        {EntityType::PawnAlt, 50},
        {EntityType::Bishop, 300},
        {EntityType::BishopAlt, 300},
        {EntityType::Rook, 150},
        {EntityType::RookAlt, 150}
    },
    
    // Round 8
    {
        {EntityType::Pawn, 50},
        {EntityType::PawnAlt, 50},
        {EntityType::Bishop, 250},
        {EntityType::BishopAlt, 250},
        {EntityType::Rook, 200},
        {EntityType::RookAlt, 200}
    },
    
    // Round 9
    {
        {EntityType::Pawn, 0},
        {EntityType::PawnAlt, 0},
        {EntityType::Bishop, 250},
        {EntityType::BishopAlt, 250},
        {EntityType::Rook, 250},
        {EntityType::RookAlt, 250}
    },
    
    // Round 10
    {
        {EntityType::Pawn, 0},
        {EntityType::PawnAlt, 0},
        {EntityType::Bishop, 150},
        {EntityType::BishopAlt, 150},
        {EntityType::Rook, 350},
        {EntityType::RookAlt, 350}
    }
};

std::vector<std::uint8_t> EnemyManager::m_numOfEnemiesPerWave =
{
    // Round 1
    1, 2, 3,
    
    // Round 2
    2, 3, 4,
    
    // Round 3
    3, 3, 4,
    
    // Round 3
    4, 4, 5,
    
    // Round 4
    6, 6, 6,
    
    // Round 5
    6, 6, 7,
    
    // Round 6
    7, 7, 7,
    
    // Round 7
    7, 7, 8,
    
    // Round 8
    8, 9, 9,
    
    // Round 9
    10, 10, 11,
    
    // Round 10
    11, 12, 14
};

EnemyManager::EnemyManager(const std::shared_ptr<IGameObject>& player)
{
    m_player = player;

    // Initialize the pool with a certain number of enemies
    // Pawn
    PoolManager<Entity, EntityType>::Initialize(EntityType::Pawn, 10);
    PoolManager<Entity, EntityType>::Initialize(EntityType::PawnAlt, 10);

    // Bishop
    PoolManager<Entity, EntityType>::Initialize(EntityType::Bishop, 10);
    PoolManager<Entity, EntityType>::Initialize(EntityType::BishopAlt, 10);

    // Rook
    PoolManager<Entity, EntityType>::Initialize(EntityType::Rook, 10);
    PoolManager<Entity, EntityType>::Initialize(EntityType::RookAlt, 10);
    
    //PoolManager<Entity, EntityType>::Initialize(EntityType::Knight, 5, "Knight");
    //PoolManager<Entity, EntityType>::Initialize(EntityType::Queen, 2, "Queen");
}

void EnemyManager::OnStart()
{
    this->m_isAlive = true;
}

void EnemyManager::Update()
{
    UpdateEnemies();
}

void EnemyManager::Reset()
{
    m_enemies.clear();

    m_state = RoundState_Waiting;
    m_numberOfEnemies = 0;
    m_pointBudget = 0;
    m_waveNumber = 0;
    m_roundCount = 0;

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
    std::vector<EntityType> enemiesToSpawn = CalculateEnemiesToSpawn(m_waveNumber);

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

std::vector<EntityType> EnemyManager::CalculateEnemiesToSpawn(const int& wave)
{
    //EnemyPointData pointData = {};

    std::vector<EntityType> entitiesToSpawn;
    std::unordered_map<EntityType, std::uint16_t> spawnWeights = m_spawnWeights.at(wave / 3);
    std::map<float, EntityType> spawnChance;
    std::uint8_t numToSpawn = m_numOfEnemiesPerWave.at(wave);

    std::uint32_t totalWeight = 0;
    
    for (const auto& weight : spawnWeights)
    {
        totalWeight += weight.second;
    }

    float currentPosition = 0.0f;
    
    for (auto& weight : spawnWeights)
    {
        float percentage = static_cast<float>(spawnWeights.at(weight.first)) / totalWeight;

        if (percentage == 0.0f)
        {
            continue;
        }
        
        spawnChance[percentage + currentPosition] = weight.first; 
        currentPosition += percentage;
    }
    
    for (std::uint8_t i = 0; i < numToSpawn; ++i)
    {
        float randomized = SpMath::RandomReal<float>(0.0f, 1.0f);

        for (const auto& chance : spawnChance)
        {
            if (randomized < chance.first)
            {
                entitiesToSpawn.push_back(chance.second);
                break;
            }
        }
    }
    
    return entitiesToSpawn;
}

void EnemyManager::CreateEnemy(const EntityType& type, const DX::XMFLOAT2& position)
{
    // Retrieve an enemy from the pool
    std::shared_ptr<Entity> enemy = PoolManager<Entity, EntityType>::GetObject(type);

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

        //Start upgrade 
        SceneManager::UnloadScene();
        ProjectileManager::Reset();
        EnemyManager::m_roundCount += 1;
        if (EnemyManager::m_roundCount > 10)
        {
            SceneManager::LoadScene("victory");
            Sound::SetMusic("menu_theme.wav", 0.4f);
            Sound::PlayOnce("promoted.wav", 0.4f);
        }
        else
            SceneManager::LoadScene("upgrade");
        
        if (SpMath::RandomInteger(0, 2) == 0)
            DeckManager::ResetMenu(UpgradeType::LevelCard, 1);
        else
        {
            if (SpMath::RandomInteger(0, 1) == 0 && m_waveNumber > 10)
            {
                if (SpMath::RandomInteger(0, 1) == 0 && m_waveNumber > 20)
                    DeckManager::ResetMenu(UpgradeType::AddCard, 3);
                else
                    DeckManager::ResetMenu(UpgradeType::AddCard, 2);
            }
            else
            {
                DeckManager::ResetMenu(UpgradeType::AddCard, 1);
            }
        }
        Sound::SetMusic("prepare.wav", 0.4f);
        Sound::PlayMusic(true);
        
        m_state = RoundState_WaveStarted;
        m_pointBudget += SpMath::RandomInteger<int>(1, 4);
        break;

    case RoundState_WaveStarted:
        std::erase_if
        (
            m_enemies,
            [](const std::shared_ptr<IGameObject>& enemy) {
                if (!enemy || !enemy->IsActive()) {
                    // Return the enemy to the pool
                    std::shared_ptr<Entity> enemyEntity = std::dynamic_pointer_cast<Entity>(enemy);
                    PoolManager<Entity, EntityType>::ReturnObject(enemyEntity->GetType(), enemyEntity);
                    return true;
                }
                return false;
            }
        );

        if (m_enemies.empty())
        {
            SpawnEnemies();
            
            if (m_waveNumber % 3 == 0 && m_waveNumber != 0)
            {
                m_state = RoundState_Waiting;
            }

            ++m_waveNumber;
        }
        break;
    }
}

void EnemyManager::Cleanup()
{
    m_enemies.clear();
}

int EnemyManager::GetRoundCount()
{
    return m_roundCount;
}