#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include <stdexcept>

// Base Scene class
class Scene {
public:
    virtual void display() const = 0;  // Example method to display scene info
    virtual ~Scene() = default;
};

// SceneManager class
class SceneManager {
private:
    // Maps scene IDs to factory functions that create scenes
    std::unordered_map<std::string, std::function<std::unique_ptr<Scene>()>> sceneFactories;

public:
    // Registers a scene creation function with a given ID
    void registerScene(const std::string& id, std::function<std::unique_ptr<Scene>()> factory);

    // Creates a scene based on its ID
    std::unique_ptr<Scene> createScene(const std::string& id) const;
};

#endif // SCENEMANAGER_HPP