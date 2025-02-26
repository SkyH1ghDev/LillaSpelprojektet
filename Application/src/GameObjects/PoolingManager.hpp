#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <SpEngine/Manager/SceneManager.hpp>

template <typename T, typename Type>
class PoolManager {
public:
    static void Initialize(Type type, size_t poolSize);
    static std::shared_ptr<T> GetObject(Type type);
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
void PoolManager<T, Type>::Initialize(Type type, size_t poolSize) {
    auto& objectPool = objectPools[type];
    objectPool.clear();
    objectPool.reserve(poolSize);

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    for (size_t i = 0; i < poolSize; ++i) {
        auto obj = std::make_shared<T>(type); // Pass the type to the constructor
        obj->SetActive(false);
        objectPool.push_back(obj);
        testScene->AddGameObject(obj);
    }
}

template <typename T, typename Type>
std::shared_ptr<T> PoolManager<T, Type>::GetObject(Type type) {
    auto& objectPool = objectPools[type];

    if (objectPool.empty()) {
        Initialize(type, 10); // Create an initial pool if none exists
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
        auto newObj = std::make_shared<T>(type); // Pass the type to the constructor
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