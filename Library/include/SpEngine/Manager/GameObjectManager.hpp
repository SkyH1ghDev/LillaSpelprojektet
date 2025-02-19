#pragma once
#include <SpEngine/Assets/Game/IGameObject.hpp>

#include <memory>
#include <vector>

class GameObjectManager
{
public:
    GameObjectManager() = default;
    ~GameObjectManager() = default;
    GameObjectManager(const GameObjectManager& other) = default;
    GameObjectManager& operator=(const GameObjectManager& other) = default;
    GameObjectManager(GameObjectManager&& other) noexcept = default;
    GameObjectManager& operator=(GameObjectManager&& other) noexcept = default;

    static void AttachGameObject(const std::shared_ptr<IGameObject>& gameObject);
    static std::vector<std::shared_ptr<IGameObject>> GetGameObjects();

private:
    static std::vector<std::shared_ptr<IGameObject>> m_gameObjects;

};
