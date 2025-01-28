
#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "Scene.hpp"
#include <iostream>

class GameScene : public Scene {
private:
    int level; // Store the level for this scene
public:
    explicit GameScene(int level); // Constructor declaration
    void display() const override;      // Overriding display method
};

#endif // GAMESCENE_HPP

