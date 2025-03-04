#pragma once

#include <vector>
#include <memory>
#include <SpEngine/Assets/Game/IGameObject.hpp>
#include "Entity.hpp"

enum RoundState
{
    RoundState_Waiting,
    RoundState_WaveStarted
};

class EnemyManager : public IGameObject {
public:

    EnemyManager(const std::shared_ptr<IGameObject>& player);
    void Update() override;
    void OnStart() override;
    void Reset() override;
    
    void SpawnEnemies();
    void CreateEnemy(const EntityType& type, const DX::XMFLOAT2& position);
    void UpdateEnemies();
    static void Cleanup();
    
    std::vector<EntityType> CalculateEnemiesToSpawn(const int& wave);
    static int GetRoundCount();
    bool IsTooCloseToOtherEnemies(DX::XMFLOAT2 newPos, float minDistance);

private:
    static std::vector<std::shared_ptr<IGameObject>> m_enemies;
    static std::shared_ptr<IGameObject> m_player;
    static RoundState m_state;
    static int m_numberOfEnemies;
    static int m_pointBudget;
    static int m_waveNumber;
    static int m_roundCount;

    static std::vector<std::unordered_map<EntityType, std::uint16_t>> m_spawnWeights;
    static std::vector<std::uint8_t> m_numOfEnemiesPerWave;

};
