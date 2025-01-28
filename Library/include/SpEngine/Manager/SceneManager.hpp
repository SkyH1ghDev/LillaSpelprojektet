#pragma once

#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include <stdexcept>
#include <SpEngine/Assets/IScene.hpp>

// SceneManager class
class SceneManager {
private:
    // Maps scene IDs to factory functions that create scenes
    std::unordered_map<std::string, std::function<std::unique_ptr<IScene>()>> sceneFactories;

public:
    // Registers a scene creation function with a given ID
    void registerScene(const std::string& id, std::function<std::unique_ptr<IScene>()> factory);

    // Creates a scene based on its ID
    std::unique_ptr<IScene> createScene(const std::string& id) const;
};
