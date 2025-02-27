#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include <SpEngine/Assets/IScene.hpp>

class SceneManager
{
private:
    static std::unordered_map<std::string, std::shared_ptr<IScene>> m_scenesMap;
    static std::shared_ptr<IScene> m_currentScene;
    static std::string m_currentSceneID;
    static std::string m_previousSceneID;

public:
    [[nodiscard]] static bool RegisterScene(const std::string& id, const std::shared_ptr<IScene>& scene);
    [[nodiscard]] static bool SetCurrentScene(const std::string& id);
    [[nodiscard]] static std::shared_ptr<IScene> GetCurrentScene();
    [[nodiscard]] static std::shared_ptr<IScene> GetScene(const std::string& id);
    [[nodiscard]] static std::vector<std::shared_ptr<IScene>> GetAllScenes();
    static bool LoadScene(const std::string& id);
    static void UnloadScene();
    static void ClearScene(const std::string& id);
    static void ResetScene(const std::string& id);
    static std::string GetCurrentSceneID();
    static std::string GetPreviousSceneID();

};

inline bool SceneManager::SetCurrentScene(const std::string& id)
{
    if (m_scenesMap.contains(id))
    {
        m_currentScene = m_scenesMap[id];
        m_previousSceneID = m_currentSceneID;
        m_currentSceneID = id;
        return true;
    }
    return false;
}

inline std::shared_ptr<IScene> SceneManager::GetCurrentScene()
{
    return m_currentScene;
}

inline std::shared_ptr<IScene> SceneManager::GetScene(const std::string& id)
{
    return m_scenesMap.at(id);
}

inline std::vector<std::shared_ptr<IScene>> SceneManager::GetAllScenes()
{
    std::vector<std::shared_ptr<IScene>> scenes;
    scenes.reserve(m_scenesMap.size());
    for (auto& kv : m_scenesMap)
    {
        scenes.push_back(kv.second);
    }
    return scenes;
}

inline std::string SceneManager::GetCurrentSceneID()
{
    return m_currentSceneID;
}

inline std::string SceneManager::GetPreviousSceneID()
{
    return m_previousSceneID;
}