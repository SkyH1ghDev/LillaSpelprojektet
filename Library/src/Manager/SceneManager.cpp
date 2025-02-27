#include "SceneManager.hpp"
#include <iostream>

std::unordered_map<std::string, std::shared_ptr<IScene>> SceneManager::m_scenesMap = {};
std::shared_ptr<IScene> SceneManager::m_currentScene = {};

bool SceneManager::RegisterScene(const std::string& id, const std::shared_ptr<IScene>& scene)
{
    if (id.empty() || scene == nullptr || m_scenesMap.contains(id))
    {
        return false;
    }
    
    scene->SetName(id);
    m_scenesMap[id] = scene;
    return true;
}

bool SceneManager::LoadScene(const std::string& id)
{
    if (!m_scenesMap.contains(id))
    {
        return false;
    }
    
    if (m_currentScene)
    {
        UnloadScene();
    }
    
    m_currentScene = m_scenesMap[id];
    m_currentScene->SetActive(true); // Activate all objects in the scene
    return true;
}

void SceneManager::UnloadScene()
{
    if (m_currentScene)
    {
        m_currentScene->SetActive(false); // Deactivate all objects in the current scene
    }
}

void SceneManager::ClearScene(const std::string& id)
{
    if (!m_scenesMap.contains(id))
    {
        std::cerr << "Scene with ID '" << id << "' does not exist.\n";
    }

    // Get the scene and clear its game objects
    std::shared_ptr<IScene> scene = m_scenesMap[id];
    if (scene)
    {
        scene->ClearGameObjects();
    }
}

void SceneManager::ResetScene(const std::string& id)
{
    if (!m_scenesMap.contains(id))
    {
        std::cerr << "Scene with ID '" << id << "' does not exist.\n";
    }

    // Get the scene and clear its game objects
    std::shared_ptr<IScene> scene = m_scenesMap[id];
    if (scene)
    {
        scene->ResetGameObjects();
    }
}
