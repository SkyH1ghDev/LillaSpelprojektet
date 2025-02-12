#include "Game.hpp"

#include <SpEngine/Manager/SceneManager.hpp>

#include "Entity.hpp"
#include "Mesh.hpp"
#include "Button/Button.hpp"
#include "GameScene.hpp"
#include "Scene/Factories/GameSceneFactories/GameSceneFactory.hpp"
#include "Player/PlayerController.hpp"
#include "Enemy/EnemyController.hpp"

Game::Game()
{
    // Setup Main Scene

    if (!SceneManager::RegisterScene("main", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }

    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");

    std::shared_ptr<IGameObject> player = std::make_shared<Entity>(EntityType::Player);
    std::shared_ptr<IScript> playerController = std::static_pointer_cast<IScript, PlayerController>(std::make_shared<PlayerController>());

    std::shared_ptr<IGameObject> enemy = std::make_shared<Entity>(EntityType::Enemy);
    std::shared_ptr<IScript> enemyController = std::make_shared<EnemyController>(player);


    std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background);
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse);
    //std::shared_ptr<IGameObject> exitButton = std::make_shared<Button>(ButtonType::Exit);
    
    player->AttachScript(playerController);
    enemy->AttachScript(enemyController);

    testScene->AddGameObject(player);
    player->CenterOrigin(true);
    testScene->AddGameObject(background);
    testScene->AddGameObject(mouse);

    testScene->AddGameObject(std::static_pointer_cast<PlayerController>(playerController)->GetWeaponObject());
    mouse->CenterOrigin(true);
    std::static_pointer_cast<PlayerController>(playerController)->GetWeaponObject()->CenterOrigin(true);
    testScene->AddGameObject(enemy);


    //testScene->AddGameObject(exitButton);

}
