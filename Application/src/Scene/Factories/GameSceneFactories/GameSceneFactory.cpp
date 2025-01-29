#include "GameSceneFactory.hpp"
#include "GameScene.hpp"

std::unique_ptr<IScene> GameSceneFactory::CreateScene(float level) {
    return std::make_unique<GameScene>(static_cast<int>(level));
}
