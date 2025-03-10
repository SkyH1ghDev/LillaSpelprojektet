
#pragma once

#include "PickUps.hpp"
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include <SpEngine/Manager/SceneManager.hpp>
#include "PoolManager.hpp"

class PickUpsManager {
public:
    static void AddPickUp(PickUpType type, std::string textureName, DX::XMFLOAT2 position, float radius, float aspectRatio, const std::string& name = "PickUp") {
        auto pickUp = PoolManager<PickUps, PickUpType>::GetObject(type);
        pickUp->Initialize(textureName, position, radius, aspectRatio);
    }

    static void Reset() {
        PoolManager<PickUps, PickUpType>::Reset();
    }
};