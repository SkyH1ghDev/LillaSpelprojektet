#pragma once
#include <SpEngine/Manager/GameObjectManager.hpp>

class IScene
{
public:
    virtual ~IScene() = default;
    virtual void Display() const = 0; // Add const

    void AddGameObject(const std::shared_ptr<IGameObject>& gameObject);
    std::vector<std::shared_ptr<IGameObject>> GetGameObjectVec();
    std::string GetName() const;
    void SetName(const std::string& name);
    void SetActive(bool active); // New function to set active state for all game objects
    void ClearGameObjects();
    void ResetGameObjects();

protected:
    std::vector<std::shared_ptr<IGameObject>> m_gameObjects;
    std::string m_name;
};

inline void IScene::AddGameObject(const std::shared_ptr<IGameObject>& gameObject)
{
    GameObjectManager::AttachGameObject(gameObject);
    m_gameObjects.push_back(gameObject);
}

inline std::vector<std::shared_ptr<IGameObject>> IScene::GetGameObjectVec()
{
    return m_gameObjects;
}

inline std::string IScene::GetName() const
{
    return m_name;
}

inline void IScene::SetName(const std::string& name)
{
    m_name = name;
}

inline void IScene::SetActive(bool active)
{
    for (auto& gameObject : m_gameObjects)
    {
        if (gameObject->IsAlive() || !active)
        {
            gameObject->SetActive(active); // Ensure IGameObject has a SetActive method
        }
    }
}

inline void IScene::ClearGameObjects()
{
    this->m_gameObjects.clear();
}

inline void IScene::ResetGameObjects()
{
    for (auto& gameObject : m_gameObjects)
    {
        gameObject->Reset(); // Ensure IGameObject has a Reset method
    }
}