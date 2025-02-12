﻿#include "Game.hpp"

#include <SpEngine/Manager/SceneManager.hpp>

#include "Entity.hpp"
#include "Mesh.hpp"
#include "Button/Button.hpp"
#include "GameScene.hpp"
#include "Scene/Factories/GameSceneFactories/GameSceneFactory.hpp"
#include "Player/PlayerController.hpp"
#include "Enemy/EnemyController.hpp"
#include "Enemy/EnemyManager.hpp"
#include "GameObjects/Mesh/Scripts/wand.hpp"

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

    
    enemy->AttachScript(enemyController);

    std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, "wood_arena_v1.png");
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "crosshair.png");
    //std::shared_ptr<IGameObject> exitButton = std::make_shared<Button>(ButtonType::Exit);
    std::shared_ptr<IGameObject> wand = std::make_shared<Mesh>(MeshType::Object, "liosstav.png");
    std::shared_ptr<IScript> wandScript = std::static_pointer_cast<IScript, WandScript>(std::make_shared<WandScript>(player));

    player->AttachScript(playerController);
    wand->AttachScript(wandScript);
    wand->CenterOrigin(true);
    testScene->AddGameObject(player);
    player->CenterOrigin(true);
    testScene->AddGameObject(background);
    testScene->AddGameObject(mouse);
    testScene->AddGameObject(wand);

    mouse->CenterOrigin(true);
    testScene->AddGameObject(enemy);

    EnemyManager::SpawnEnemies(player, 5);


    //testScene->AddGameObject(exitButton);

}
