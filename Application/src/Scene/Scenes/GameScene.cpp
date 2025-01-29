#include <iostream>
#include "GameScene.hpp"

// Constructor implementation
GameScene::GameScene(int level) : m_level(level) {}

// display() method implementation
void GameScene::Display() const {
    std::cout << "Game Scene - Level: " << m_level << std::endl;
}
