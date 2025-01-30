#include "MenuSceneFactory.hpp"
#include "MenuScene.hpp"

std::unique_ptr<IScene> MenuSceneFactory::CreateScene() {
    return std::make_unique<MenuScene>();
}