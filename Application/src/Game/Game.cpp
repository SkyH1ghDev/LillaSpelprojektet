#include "Game.hpp"

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
#include "Collision/CollisionHandler.hpp"
#include "Emty.hpp"
#include "GameObjects/UI/Bar/HealthBarManager.hpp"
#include "GameObjects/UI/Bar/ManaBarManager.hpp"
#include "Abilities/StatSheet.hpp"

void Game::SetupGame()
{
    // Setup Main Scene

    if (!SceneManager::RegisterScene("main", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");

    std::shared_ptr<IGameObject> player = std::make_shared<Entity>(EntityType::Player, "Player");
    player->SetPosition({ 150, 150 });
    std::shared_ptr<IScript> playerController = std::static_pointer_cast<IScript, PlayerController>(std::make_shared<PlayerController>());


    std::shared_ptr<PlayerCardScript> pcs = std::make_shared<PlayerCardScript>();
    std::shared_ptr<IScript> playerCardScript = std::static_pointer_cast<IScript>(pcs);

    std::shared_ptr<IScript> playerAttackScript = std::static_pointer_cast<IScript, PlayerAttackScript>(std::make_shared<PlayerAttackScript>());


    //Button Scene???
    std::shared_ptr<IGameObject> playButton = std::make_shared<Button>(ButtonType::Play);
    playButton->SetPosition({300, 100});
    std::shared_ptr<IGameObject> continueButton = std::make_shared<Button>(ButtonType::Continue);
    continueButton->SetPosition({ 300, 150 });
    std::shared_ptr<IGameObject> quitButton = std::make_shared<Button>(ButtonType::Quit);
    quitButton->SetPosition({ 300, 200 });
    std::shared_ptr<IGameObject> exitButton = std::make_shared<Button>(ButtonType::Exit);
    exitButton->SetPosition({ 300, 250 });

    testScene->AddGameObject(playButton);
    testScene->AddGameObject(continueButton);
    testScene->AddGameObject(quitButton);
    testScene->AddGameObject(exitButton);

    std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, "Background", "wood_arena_v1.png");
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "Mouse", "crosshair.png");

    std::shared_ptr<IGameObject> wand = std::make_shared<Mesh>(MeshType::Object, "Wand", "wandMockupOne.apng");
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

    ProjectileManager::Initialize(ProjectileType::BishopBall, 10);
    ProjectileManager::Initialize(ProjectileType::PawnPellet, 10);

    std::shared_ptr<IGameObject> collisionObject = std::make_shared<Emty>();
    std::shared_ptr<IScript> collisionHandler = std::static_pointer_cast<IScript, CollisionHandler>(std::make_shared<CollisionHandler>(32));
    collisionObject->AttachScript(collisionHandler);
    testScene->AddGameObject(collisionObject);

    HealthBarManager::Initialize(5);
    ManaBarManager::Initialize(3);
    ManaBarManager::RefillManaShard(5);
    std::shared_ptr<IGameObject> cardDeck = pcs->GetCardDeck();
    testScene->AddGameObject(cardDeck);


    if (!SceneManager::RegisterScene("secondScene", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }

    std::shared_ptr<IScene> secondScene = SceneManager::GetScene("secondScene");

    secondScene->AddGameObject(player);
    secondScene->AddGameObject(background);
    secondScene->AddGameObject(mouse);
}

void Game::ResetGame()
{
    SceneManager::ClearScene("main");
    SceneManager::ClearScene("secondScene");
    EnemyManager::Cleanup();
    ProjectileManager::Cleanup();
    HealthBarManager::Cleanup();
    ManaBarManager::Cleanup();
    StatSheet::Reset();
}