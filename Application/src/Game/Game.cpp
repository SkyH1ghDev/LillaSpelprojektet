#include "Game.hpp"

#include <SpEngine/Manager/SceneManager.hpp>

#include "Entity.hpp"
#include "Mesh.hpp"
#include "GameScene.hpp"
#include "Scene/Factories/GameSceneFactories/GameSceneFactory.hpp"
#include "Player/PlayerController.hpp"

Game::Game()
{
    if (!SceneManager::RegisterScene("main", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");

    std::shared_ptr<IGameObject> player = std::make_shared<Entity>(EntityType::Player);
    std::shared_ptr<IGameObject> playerController = std::make_shared<PlayerController>(std::static_pointer_cast<Entity, IGameObject>(player));
    std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background);

    testScene->AddGameObject(player);
    testScene->AddGameObject(playerController);
    testScene->AddGameObject(background);
}
