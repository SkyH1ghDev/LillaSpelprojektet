﻿#include "Game.hpp"

#include <SpEngine/Manager/SceneManager.hpp>

#include "Entity.hpp"
#include "Mesh.hpp"
#include "Button/Button.hpp"
#include "GameScene.hpp"
#include "Scene/Factories/GameSceneFactories/GameSceneFactory.hpp"
#include "Player/PlayerController.hpp"
#include "CardDeck.hpp"

#include "Player/PlayerAttackScript.hpp"
#include "Player/PlayerCardScript.hpp"
#include "Enemy/EnemyController.hpp"
#include "Enemy/EnemyManager.hpp"
#include "Projectile/ProjectileManager.hpp"
#include "GameObjects/Scripts/wand.hpp"
#include "GameObjects/UI/Bar/HealthBarManager.hpp"
#include "GameObjects/UI/Bar/ManaBarManager.hpp"


Game::Game()
{
    // Setup Main Scene

    if (!SceneManager::RegisterScene("main", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    
    std::shared_ptr<IGameObject> player = std::make_shared<Entity>(EntityType::Player);
    player->SetPosition({ 150, 150 });
    std::shared_ptr<IScript> playerController = std::static_pointer_cast<IScript, PlayerController>(std::make_shared<PlayerController>());


    std::shared_ptr<PlayerCardScript> pcs = std::make_shared<PlayerCardScript>();
    std::shared_ptr<IScript> playerCardScript = std::static_pointer_cast<IScript>(pcs);

    std::shared_ptr<IScript> playerAttackScript = std::static_pointer_cast<IScript, PlayerAttackScript>(std::make_shared<PlayerAttackScript>());


    std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, "wood_arena_v1.png");
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "crosshair.png");

    std::shared_ptr<IGameObject> wand = std::make_shared<Mesh>(MeshType::Object, "liosstav.png");
    std::shared_ptr<IScript> wandScript = std::static_pointer_cast<IScript, WandScript>(std::make_shared<WandScript>(player));

    player->AttachScript(playerController);
    player->AttachScript(playerAttackScript);
    player->AttachScript(playerCardScript);

    wand->AttachScript(wandScript);
    wand->CenterOrigin(true);
    testScene->AddGameObject(player);
    player->CenterOrigin(true);
    testScene->AddGameObject(background);
    testScene->AddGameObject(mouse);
    testScene->AddGameObject(wand);

    mouse->CenterOrigin(true);

    EnemyManager::SpawnEnemies(player, 2);

    ProjectileManager::Initialize(ProjectileType::Base, 200);
    ProjectileManager::Initialize(ProjectileType::BishopBall, 10);
    ProjectileManager::Initialize(ProjectileType::PawnPellet, 10);

    // UI
    HealthBarManager::Initialize(5);
    ManaBarManager::Initialize(3);
    std::shared_ptr<IGameObject> cardDeck = pcs->GetCardDeck();
    testScene->AddGameObject(cardDeck);
}
