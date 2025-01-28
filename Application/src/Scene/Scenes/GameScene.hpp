#pragma once

#include <SpEngine/Assets/IScene.hpp>

class GameScene : public IScene {
private:
    int level; // Store the level for this scene
public:
    explicit GameScene(int level); // Constructor declaration
    void display() const override;      // Overriding display method
};
