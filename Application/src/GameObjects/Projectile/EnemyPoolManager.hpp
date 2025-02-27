#pragma once

#include "PoolingManager.hpp"
#include "Entity.hpp"

class EnemyPoolManager {
public:
    static void AddEnemy(EntityType type, DX::XMFLOAT2 position, const std::string& name = "Enemy") {
        auto enemy = PoolManager<Entity, EntityType>::GetObject(type, name);
        
        enemy->Initialize();
        enemy->SetPosition(position);
    }

    static void Cleanup(EntityType type) {
        PoolManager<Entity, EntityType>::Cleanup(type);
    }
};