#include "SceneManager.hpp"

// Register a scene factory with an ID
void SceneManager::registerScene(const std::string& id, std::function<std::unique_ptr<Scene>()> factory) {
    sceneFactories[id] = std::move(factory);
}

// Create a scene using its ID
std::unique_ptr<Scene> SceneManager::createScene(const std::string& id) const {
    auto it = sceneFactories.find(id);
    if (it != sceneFactories.end()) {
        return it->second();  // Call the factory function to create the scene
    }
    else {
        throw std::runtime_error("Scene ID '" + id + "' not registered.");
    }
}