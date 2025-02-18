#include "SceneManager.hpp"

#include <iostream>

std::unordered_map<std::string, std::shared_ptr<IScene>> SceneManager::m_scenesMap = {};
std::shared_ptr<IScene> SceneManager::m_currentScene = {};


bool SceneManager::RegisterScene(const std::string& id, const std::shared_ptr<IScene>& scene)
{
    if (id.empty())
    {
        return false;
    }

    if (scene == nullptr)
    {
        return false;
    }

    if (m_scenesMap.contains(id))
    {
        return false;
    }
    
    scene->SetName(id);
    m_scenesMap[id] = scene;
    return true;
}



// Load a scene by ID


// Call update (or display) on the current scene
/*bool SceneManager::Update() {
    if (m_currentScene) {
        m_currentScene->Display();
        return true;
    }
    else {
        return false;
    }
}*/
