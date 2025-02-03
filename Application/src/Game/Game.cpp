#include "Game.hpp"

#include <SpEngine/Manager/SceneManager.hpp>

#include "Entity.hpp"
#include "GameScene.hpp"
#include "Scene/Factories/GameSceneFactories/GameSceneFactory.hpp"

Game::Game()
{
    if (SceneManager::RegisterScene("main", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    std::shared_ptr<IGameObject> testGameObject = std::make_shared<Entity>(EntityType::Player);

    testScene->AddGameObject(testGameObject);
}
