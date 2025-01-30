#include "SceneManager.hpp"

// Register a scene factory function
bool SceneManager::RegisterScene(const std::string& id, std::function<std::unique_ptr<IScene>()> factory) {
    if (id.empty()) {
        std::cerr << "Error: Cannot register scene with an empty ID!" << std::endl;
        return false;
    }

    if (!factory) { // Check if the factory function is valid
        std::cerr << "Error: Factory function for scene '" << id << "' is invalid!" << std::endl;
        return false;
    }

    if (sceneFactories.find(id) != sceneFactories.end()) {
        std::cerr << "Error: Scene with ID '" << id << "' is already registered!" << std::endl;
        return false;
    }

    sceneFactories[id] = factory;
    return true; // Indicate success
}


// Load a scene by ID
bool SceneManager::LoadScene(const std::string& id) {
    auto it = sceneFactories.find(id);
    if (it != sceneFactories.end()) {
        m_currentScene = it->second(); // Call the factory function to create the scene
        return true;
    }
    else {
        return false;
    }
}

// Call update (or display) on the current scene
bool SceneManager::Update() {
    if (m_currentScene) {
        m_currentScene->Display();
        return true;
    }
    else {
        return false;
    }
}