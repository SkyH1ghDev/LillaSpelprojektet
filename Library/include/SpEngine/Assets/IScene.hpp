#pragma once
#include <SpEngine/Manager/GameObjectManager.hpp>
#include "IGameObject.hpp"

class IScene
{
public:
    virtual ~IScene() = default;
    virtual void Display() const = 0; // Add const

    void AddGameObject(const std::shared_ptr<IGameObject>& gameObject);

private:
    std::vector<std::shared_ptr<IGameObject>> m_gameObjects;
};

inline void IScene::AddGameObject(const std::shared_ptr<IGameObject>& gameObject)
{
    GameObjectManager::AttachGameObject(gameObject);
    m_gameObjects.push_back(gameObject);
}

