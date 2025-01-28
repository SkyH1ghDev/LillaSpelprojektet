#include <iostream>
#include "GameScene.hpp"

// Constructor implementation
GameScene::GameScene(int level) : level(level) {}

// display() method implementation
void GameScene::display() const {
    std::cout << "Game Scene - Level: " << level << std::endl;
}
