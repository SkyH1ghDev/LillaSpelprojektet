#pragma once

#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <SpEngine/Assets/IScene.hpp>

class SceneManager {

public:
    bool RegisterScene(const std::string& id, std::function<std::unique_ptr<IScene>()> factory);
    bool LoadScene(const std::string& id);
    bool Update();

    std::shared_ptr<IScene> GetCurrentScene() { return m_currentScene; }

private:
    std::unordered_map<std::string, std::function<std::unique_ptr<IScene>()>> sceneFactories;
    std::shared_ptr<IScene> m_currentScene;

};
