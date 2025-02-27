#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <SpEngine/Manager/SceneManager.hpp>
#include "EnemyController.hpp"

template <typename T, typename Type>
class PoolManager {
public:
    static void Initialize(Type type, size_t poolSize, const std::string& name);
    static std::shared_ptr<T> GetObject(Type type, const std::string& name);
    static void ReturnObject(Type type, std::shared_ptr<T> object);
    static void Cleanup(Type type);

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
void PoolManager<T, Type>::Initialize(Type type, size_t poolSize, const std::string& name) {
    auto& objectPool = objectPools[type];
    objectPool.clear();
    objectPool.reserve(poolSize);

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    for (size_t i = 0; i < poolSize; ++i) {
        // Use the provided name and append an index for uniqueness
        auto obj = std::make_shared<T>(type, name + "_" + std::to_string(i));
        obj->SetActive(false);
        if (name == "Bishop")
        {
            std::shared_ptr<IScript> enemyController = std::make_shared<EnemyController>();
            obj->AttachScript(enemyController);
        }
        objectPool.push_back(obj);
        testScene->AddGameObject(obj);
    }
}

template <typename T, typename Type>
std::shared_ptr<T> PoolManager<T, Type>::GetObject(Type type, const std::string& name) {
    auto& objectPool = objectPools[type];

    if (objectPool.empty()) {
        Initialize(type, 10, name); // Initialize the pool with the provided name
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

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    objectPool.reserve(newSize);

    for (size_t i = oldSize; i < newSize; ++i) {
        // Use the provided name and append an index for uniqueness
        auto newObj = std::make_shared<T>(type, name + "_" + std::to_string(i));
        newObj->SetActive(false);
        objectPool.push_back(newObj);
        testScene->AddGameObject(newObj);
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