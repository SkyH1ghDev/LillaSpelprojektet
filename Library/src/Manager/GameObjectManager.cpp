#include "GameObjectManager.hpp"

// Init static member
std::vector<std::shared_ptr<IGameObject>> GameObjectManager::m_gameObjects = {};

std::vector<std::shared_ptr<IGameObject>> GameObjectManager::GetGameObjects()
{
    return m_gameObjects;
}

void GameObjectManager::AttachGameObject(const std::shared_ptr<IGameObject>& gameObject)
{
    if (const auto& it = std::ranges::find(m_gameObjects, gameObject); it == m_gameObjects.end())
    {
        m_gameObjects.push_back(gameObject);
    }
}
