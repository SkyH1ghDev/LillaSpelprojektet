#include <iostream>
#include "MenuScene.hpp"

// Constructor implementation
MenuScene::MenuScene(int level) : m_level(level) {}

// display() method implementation
void MenuScene::Display() const {
    std::cout << "Game Scene - Level: " << m_level << std::endl;
}
