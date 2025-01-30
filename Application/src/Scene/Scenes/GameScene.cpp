#include <iostream>
#include "GameScene.hpp"


GameScene::GameScene(int level) : m_level(level) {
    OnEnter(); // Automatically initialize entities
}

void GameScene::OnEnter() {
    std::cout << "Entering Game Scene - Level: " << m_level << std::endl;
    InitializeEntities();
}

void GameScene::InitializeEntities() {
    // Add player
    m_entities.push_back(std::make_unique<Entity>(EntityType::Player));

}

void GameScene::Display() const {
    std::cout << "Displaying Game Scene - Level: " << m_level << std::endl;
    for (const auto& entity : m_entities) {
        entity->PerformVisible(); // Render all entities
    }
}

void GameScene::Update(float deltaTime) {
    for (auto& entity : m_entities) {
        entity->PerformMove();  // Update entity positions
    }
}

void GameScene::OnExit() {
    std::cout << "Exiting Game Scene - Level: " << m_level << std::endl;
    m_entities.clear(); // Cleanup
}

DX::XMFLOAT2 GameScene::GetEntityPosition(int i) const {
    return this->m_entities.at(i)->GetPosition();
}
