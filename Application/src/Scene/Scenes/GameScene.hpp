#pragma once

#include <SpEngine/Assets/IScene.hpp>

class GameScene : public IScene {
private:
    int m_level; // Store the level for this scene
public:
    explicit GameScene(int level); // Constructor declaration
    void Display() const override;      // Overriding display method
};
