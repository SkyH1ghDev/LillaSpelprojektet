#pragma once

// DON'T TOUCH, IT IS HERE SO THAT THE COMPILER DOESN'T MISTAKE (GetObject) FOR THE wingdi.h MACRO
#undef GetObject

#include <vector>
#include <memory>
#include <unordered_map>
#include <SpEngine/Manager/SceneManager.hpp>

#include "BaseProjectileFactory.hpp"
#include "BishopBallFactory.hpp"
#include "RookFactory.hpp"
#include "RookAltFactory.hpp"
#include "BishopFactory.hpp"
#include "BishopAltFactory.hpp"
#include "DisruptorWaveFactory.hpp"
#include "PawnFactory.hpp"
#include "PawnPelletFactory.hpp"
#include "PlayerFactory.hpp"
#include "Projectile.hpp"
#include "ScatterPelletFactory.hpp"
#include "SniperBulletFactory.hpp"
#include "FireBallFactory.hpp"

template <typename T, typename Type>
class PoolManager {
public:
    static void Initialize(Type type, size_t poolSize);
    static std::shared_ptr<T> GetObject(Type type, const std::string& name);
    static void ReturnObject(Type type, std::shared_ptr<T> object);
    static void Cleanup(Type type);
    static std::shared_ptr<T> CreateObject(Type type);

private:
    static std::unordered_map<Type, std::vector<std::shared_ptr<T>>> objectPools;
    static std::unordered_map<Type, size_t> lastInactiveIndexMap;
};

// Initialize static variables
template <typename T, typename Type>
std::unordered_map<Type, std::vector<std::shared_ptr<T>>> PoolManager<T, Type>::objectPools;

template <typename T, typename Type>
std::unordered_map<Type, size_t> PoolManager<T, Type>::lastInactiveIndexMap;




template <typename T, typename Type>
void PoolManager<T, Type>::Initialize(Type type, size_t poolSize) {
    auto& objectPool = objectPools[type];
    objectPool.clear();
    objectPool.reserve(poolSize);

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("game");
    for (size_t i = 0; i < poolSize; ++i) {
        // Use the provided name and append an index for uniqueness
        //auto obj = std::make_shared<T>(type, name + "_" + std::to_string(i));

        std::shared_ptr<T> obj = CreateObject(type);
        
        if (obj)
        {
            obj->SetActive(false);
            objectPool.push_back(obj);
            testScene->AddGameObject(obj);
        }
    }
}

template <typename T, typename Type>
std::shared_ptr<T> PoolManager<T, Type>::GetObject(Type type, const std::string& name) {
    auto& objectPool = objectPools[type];

    if (objectPool.empty()) {
        Initialize(type, 10); // Initialize the pool with the provided name
    }

    size_t& lastInactiveIndex = lastInactiveIndexMap[type];

    for (size_t i = 0; i < objectPool.size(); ++i) {
        size_t index = (lastInactiveIndex + i) % objectPool.size();
        if (!objectPool[index]->IsActive()) {
            lastInactiveIndex = (index + 1) % objectPool.size();
            return objectPool[index];
        }
    }

    // Expand the pool if no inactive object is found
    size_t oldSize = objectPool.size();
    size_t newSize = oldSize * 2;

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("game");
    objectPool.reserve(newSize);

    for (size_t i = oldSize; i < newSize; ++i) {
        std::shared_ptr<T> obj = CreateObject(type);
        
        if (obj)
        {
            obj->SetActive(false);
            objectPool.push_back(obj);
            testScene->AddGameObject(obj);
        }

    }

    objectPool[oldSize]->SetActive(true);
    lastInactiveIndex = oldSize;
    return objectPool[oldSize];
}

template <typename T, typename Type>
void PoolManager<T, Type>::ReturnObject(Type type, std::shared_ptr<T> object) {
    object->SetActive(false);
}

template <typename T, typename Type>
void PoolManager<T, Type>::Cleanup(Type type) {
    objectPools[type].clear();
    lastInactiveIndexMap[type] = 0;
}

template <typename T, typename Type>
std::shared_ptr<T> PoolManager<T, Type>::CreateObject(Type type)
{
    std::shared_ptr<T> obj;

    if constexpr (std::is_same_v<Type, EntityType>)
    {
        switch (type)
        {
            case EntityType::Player:
            {
                PlayerFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateEntity());
                break;
            }
            
            case EntityType::Bishop:
            {
                BishopFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateEntity());
                break;
            }
            
            case EntityType::BishopAlt:
            {
                BishopAltFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateEntity());
                break;
            }
            
            case EntityType::Pawn:
            {
                PawnFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateEntity());
                break;
            }
            
            case EntityType::Rook:
            {
                RookFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateEntity());
                break;
            }

            case EntityType::RookAlt:
            {
                RookAltFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateEntity());
                break;
            }

            case EntityType::Queen:
            case EntityType::Knight:
            default:
                break;
        }
    }
    
    else if constexpr (std::is_same_v<Type, ProjectileType>)
    {
        switch (type)
        {
            case ProjectileType::Base:
            {
                BaseProjectileFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateObject());
                break;
            }
            
            case ProjectileType::BishopBall:
            {
                BishopBallFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateObject());
                break;
            }

            case ProjectileType::PawnPellet:
            {
                PawnPelletFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateObject());
                break;
            }               

            case ProjectileType::ScatterPellet:
            {
                ScatterPelletFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateObject());
                break;
            }

            case ProjectileType::SniperBullet:
            {
                SniperBulletFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateObject());
                break;
            }

            case ProjectileType::DisruptorWave:
            {
                DisruptorWaveFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateObject());
                break;
            }

            case ProjectileType::FireBall:
            {
                FireBallFactory factory;
                obj = std::dynamic_pointer_cast<T>(factory.CreateObject());
                break;
            }

            default:
                break;
        }
    }

    return obj;
}