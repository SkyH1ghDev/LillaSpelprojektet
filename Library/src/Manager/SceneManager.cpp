#include "SceneManager.hpp"

// Register a scene factory function
void SceneManager::RegisterScene(const std::string& id, std::function<std::unique_ptr<IScene>()> factory) {
    sceneFactories[id] = std::move(factory);
}

// Load a scene by ID
void SceneManager::LoadScene(const std::string& id) {
    auto it = sceneFactories.find(id);
    if (it != sceneFactories.end()) {
        m_currentScene = it->second(); // Call the factory function to create the scene
        std::cout << "Loaded scene: " << id << std::endl;
    }
    else {
        throw std::runtime_error("Scene ID '" + id + "' not registered.");
    }
}

// Call update (or display) on the current scene
void SceneManager::Update() {
    if (m_currentScene) {
        m_currentScene->Display();
    }
    else {
        std::cout << "No scene loaded!" << std::endl;
    }
}