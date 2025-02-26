#include "Game.hpp"


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
#include "Scripts/PauseBackGround.hpp"

void Game::SetupGame()
{
    // Setup Start Scene
    if (!SceneManager::RegisterScene("start", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> startScene = SceneManager::GetScene("start");
    SetupStartScene(startScene);

    if (!SceneManager::RegisterScene("pause", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> pauseScene = SceneManager::GetScene("pause");
    SetupPauseScene(pauseScene);

    // Setup Main Scene
    if (!SceneManager::RegisterScene("main", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> mainScene = SceneManager::GetScene("main");
    SetupMainScene(mainScene);
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

void Game::SetupStartScene(std::shared_ptr<IScene> startScene)
{
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "MenuMouse", "mouse.png");

    std::shared_ptr<IGameObject> playButton = std::make_shared<Button>(ButtonType::Play);
    playButton->SetPosition({ 250, 150 });
    std::shared_ptr<IGameObject> exitButton = std::make_shared<Button>(ButtonType::Exit);
    exitButton->SetPosition({ 250, 200 });

    startScene->AddGameObject(mouse);
    startScene->AddGameObject(playButton);
    startScene->AddGameObject(exitButton);
}

void Game::SetupMainScene(std::shared_ptr<IScene> mainScene)
{

    // Player, Controller and CardDeck
    std::shared_ptr<IGameObject> player = std::make_shared<Entity>(EntityType::Player, "Player");
    std::shared_ptr<IScript> playerController = std::static_pointer_cast<IScript, PlayerController>(std::make_shared<PlayerController>());
    std::shared_ptr<IScript> playerAttackScript = std::static_pointer_cast<IScript, PlayerAttackScript>(std::make_shared<PlayerAttackScript>());
    std::shared_ptr<PlayerCardScript> pcs = std::make_shared<PlayerCardScript>();
    std::shared_ptr<IScript> playerCardScript = std::static_pointer_cast<IScript>(pcs);

    player->SetPosition({ 150, 150 });
    player->AttachScript(playerController);
    player->AttachScript(playerAttackScript);
    player->AttachScript(playerCardScript);
    player->CenterOrigin(true);
    std::shared_ptr<IGameObject> cardDeck = pcs->GetCardDeck();

    mainScene->AddGameObject(player);
    mainScene->AddGameObject(cardDeck);


    // Background and Mouse
    std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, "Background", "wood_arena_v1.png");
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "Crosshair", "crosshair.png");
    std::shared_ptr<IGameObject> wand = std::make_shared<Mesh>(MeshType::Object, "Wand", "wandMockupOne.apng");
    std::shared_ptr<IScript> wandScript = std::static_pointer_cast<IScript, WandScript>(std::make_shared<WandScript>(player));
    wand->AttachScript(wandScript);
    wand->CenterOrigin(true);
    mouse->CenterOrigin(true);

    mainScene->AddGameObject(background);
    mainScene->AddGameObject(mouse);
    mainScene->AddGameObject(wand);


    // Collision
    std::shared_ptr<IGameObject> collisionObject = std::make_shared<Emty>();
    std::shared_ptr<IScript> collisionHandler = std::static_pointer_cast<IScript, CollisionHandler>(std::make_shared<CollisionHandler>(32));
    collisionObject->AttachScript(collisionHandler);
    mainScene->AddGameObject(collisionObject);


    // Managers
    EnemyManager::SpawnEnemies(player, 2);
    ProjectileManager::Initialize(ProjectileType::BishopBall, 10);
    ProjectileManager::Initialize(ProjectileType::PawnPellet, 10);
    HealthBarManager::Initialize(5);
    ManaBarManager::Initialize(3);
    ManaBarManager::RefillManaShard(5);


    // Temporary Exit Button
    std::shared_ptr<IGameObject> exitButton = std::make_shared<Button>(ButtonType::Exit);
    exitButton->SetPosition({ 0, 280 });
    mainScene->AddGameObject(exitButton);

}

void Game::SetupPauseScene(std::shared_ptr<IScene> pauseScene)
{
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "PauseMouse", "mouse.png");

    std::shared_ptr<IGameObject> playButton = std::make_shared<Button>(ButtonType::Play);
    playButton->SetPosition({ 250, 150 });
    std::shared_ptr<IGameObject> exitButton = std::make_shared<Button>(ButtonType::Exit);
    exitButton->SetPosition({ 250, 200 });

    pauseScene->AddGameObject(mouse);
    pauseScene->AddGameObject(playButton);
    pauseScene->AddGameObject(exitButton);

    for (size_t i = 0; i < 8; i++)
    {
        std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, std::string("PauseBackground" + std::to_string(i)), "pawnground.apng");
        std::shared_ptr<IScript> script = std::static_pointer_cast<IScript, PauseBackgroundScript>(std::make_shared<PauseBackgroundScript>());
        background->AttachScript(script);
        background->SetPosition({ float(80 * i), 0 });
        pauseScene->AddGameObject(background);
    }

}
