#include "GameSceneFactory.hpp"
#include "GameScene.hpp"

GameSceneFactory::GameSceneFactory(float level) : defaultLevel(level) {}

std::unique_ptr<Scene> GameSceneFactory::operator()() const {
    return std::make_unique<GameScene>(static_cast<int>(defaultLevel)); // Cast if needed
}
