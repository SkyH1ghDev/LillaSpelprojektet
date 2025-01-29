#pragma once

#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <SpEngine/Assets/IScene.hpp>

class SceneManager {
private:
    std::unordered_map<std::string, std::function<std::unique_ptr<IScene>()>> sceneFactories;
    std::unique_ptr<IScene> m_currentScene;

public:
    void RegisterScene(const std::string& id, std::function<std::unique_ptr<IScene>()> factory);
    void LoadScene(const std::string& id);
    void Update();
};
