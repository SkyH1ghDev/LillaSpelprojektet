#pragma once

#include "IGameObject.hpp"
class IScene {
public:
    virtual ~IScene() = default;
    virtual void Display() const = 0; // Render the scene
    virtual void Update(float deltaTime) = 0; // Update the scene logic
    virtual void OnEnter() = 0; // Called when the scene is entered
    virtual void OnExit() = 0; // Called when the scene is exited   
};


