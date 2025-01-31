#include "Game.hpp"

#include <SpEngine/Manager/SceneManager.hpp>

#include "Entity.hpp"
#include "GameScene.hpp"
#include "Scene/Factories/GameSceneFactories/GameSceneFactory.hpp"

Game::Game()
{
    std::unique_ptr<IScene> testScene = GameSceneFactory::CreateScene(0);
    std::shared_ptr<IGameObject> testGameObject = std::make_shared<Entity>(EntityType::Player);

    testScene->AddGameObject(testGameObject);
}
