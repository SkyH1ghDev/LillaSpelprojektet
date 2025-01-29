#include "MenuSceneFactory.hpp"
#include "MenuScene.hpp"

std::unique_ptr<IScene> MenuSceneFactory::CreateScene(float level) {
    return std::make_unique<MenuScene>(static_cast<int>(level));
}