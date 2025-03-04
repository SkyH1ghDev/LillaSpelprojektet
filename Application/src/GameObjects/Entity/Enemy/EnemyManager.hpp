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
    void CreateEnemy(const std::string& type, const DX::XMFLOAT2& position);
    void UpdateEnemies();
    EntityType ConvertStringToEntityType(const std::string& type);
    static void Cleanup();
    static int GetRoundCount();
    
    std::vector<std::string> CalculateEnemiesToSpawn();
    bool IsTooCloseToOtherEnemies(DX::XMFLOAT2 newPos, float minDistance);

private:
    static std::vector<std::shared_ptr<IGameObject>> m_enemies;
    static std::shared_ptr<IGameObject> m_player;
    static RoundState m_state;
    static int m_numberOfEnemies;
    static int m_pointBudget;
    static int m_waveNumber;
    static int m_roundCount;

    struct EnemyPointData
    {
        const int Pawn = 1;
        const int Bishop = 3;
        const int BishopAlt = 3;
        const int Knight = 3;
        const int Rook = 5;
        const int RookAlt = 5;
        const int Queen = 9;
    };
    
};
