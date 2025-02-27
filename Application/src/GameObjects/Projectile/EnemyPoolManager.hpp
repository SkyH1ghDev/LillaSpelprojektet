#pragma once

#include "PoolingManager.hpp"
#include "Entity.hpp"

class EnemyManager {
public:
    static void AddEnemy(EntityType type, DX::XMFLOAT2 position) {
        auto enemy = PoolManager<Entity, EntityType>::GetObject(type);
        enemy->Initialize();
        enemy->SetPosition(position);
    }

    static void Cleanup(EntityType type) {
        PoolManager<Entity, EntityType>::Cleanup(type);
    }
};