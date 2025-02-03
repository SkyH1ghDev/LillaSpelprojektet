#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <stdexcept>
#include <SpEngine/Assets/IScene.hpp>

class SceneManager
{
private:
    static std::unordered_map<std::string, std::shared_ptr<IScene>> m_scenes;
    static std::shared_ptr<IScene> m_currentScene;

public:

    [[nodiscard]]
    static bool RegisterScene(const std::string& id, const std::shared_ptr<IScene>& scene);

    [[nodiscard]]
    static bool SetCurrentScene(const std::string& id);

    [[nodiscard]]
    static std::shared_ptr<IScene> GetCurrentScene();

    [[nodiscard]]
    static std::shared_ptr<IScene> GetScene(const std::string& id);
    //bool Update();
};

inline bool SceneManager::SetCurrentScene(const std::string& id)
{
    if (m_scenes.contains(id))
    {
        m_currentScene = m_scenes[id]; // Call the factory function to create the scene
        return true;
    }

    return false;
}

inline std::shared_ptr<IScene> SceneManager::GetCurrentScene()
{

}

inline std::shared_ptr<IScene> SceneManager::GetScene(const std::string& id)
{
    return m_scenes.at(id);
}
