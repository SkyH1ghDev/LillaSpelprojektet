#include "Game.hpp"


#include "Entity.hpp"
#include "Mesh.hpp"
#include "GameScene.hpp"
#include "Empty.hpp"
#include "Scene/Factories/GameSceneFactories/GameSceneFactory.hpp"
#include "Player/PlayerController.hpp"
#include "CardDeck.hpp"

#include "Player/PlayerAttackScript.hpp"
#include "Player/PlayerCardScript.hpp"
#include "Enemy/EnemyManager.hpp"
#include "Projectile/ProjectileManager.hpp"
#include "GameObjects/Scripts/Wand.hpp"
#include "Collision/CollisionHandler.hpp"
#include "GameObjects/UI/Bar/HealthBarManager.hpp"
#include "GameObjects/UI/Bar/ManaBarManager.hpp"
#include "Abilities/StatSheet.hpp"
#include "Scripts/PauseBackGround.hpp"
#include "Button.hpp"

void Game::SetupGame()
{
    std::shared_ptr<IGameObject> player = std::make_shared<Entity>(EntityType::Player, "Player");
    std::shared_ptr<IScript> playerController = std::static_pointer_cast<IScript, PlayerController>(std::make_shared<PlayerController>());
    player->AttachScript(playerController);

    // Setup Start Scene
    if (!SceneManager::RegisterScene("start", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> startScene = SceneManager::GetScene("start");
    SetupStartScene(startScene, player);

    if (!SceneManager::RegisterScene("pause", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> pauseScene = SceneManager::GetScene("pause");
    SetupPauseScene(pauseScene);

    // Setup Death Scene
    if (!SceneManager::RegisterScene("death", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> deathScene = SceneManager::GetScene("death");
    SetupDeathScene(deathScene, player);


    // Setup Main Scene
    if (!SceneManager::RegisterScene("main", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> mainScene = SceneManager::GetScene("main");
    SetupMainScene(mainScene, player);

}

void Game::ResetGame()
{
    SceneManager::ClearScene("main");
    SceneManager::ClearScene("start");
    SceneManager::ClearScene("pause");
    SceneManager::ClearScene("secondScene");
    EnemyManager::Cleanup();
    ProjectileManager::Cleanup();
    HealthBarManager::Cleanup();
    ManaBarManager::Cleanup();
    StatSheet::Reset();

    SetupGame();

    // OnStart for all GameObjects

    for (const auto& gameObject : GameObjectManager::GetGameObjects())
    {
        gameObject->OnStart();
    }
    SceneManager::LoadScene("start");
}

void Game::SetupStartScene(std::shared_ptr<IScene> startScene, std::shared_ptr<IGameObject> player)
{

    std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, "Background", "wood_arena_v1.png");
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "MenuMouse", "mouse.png");

    std::shared_ptr<IGameObject> playButton = std::make_shared<Button>(ButtonType::Play);
    playButton->SetPosition({245, 150 });
    std::shared_ptr<IGameObject> exitButton = std::make_shared<Button>(ButtonType::Exit);
    exitButton->SetPosition({ 245, 210 });

    startScene->AddGameObject(player);
    startScene->AddGameObject(background);
    startScene->AddGameObject(mouse);
    startScene->AddGameObject(playButton);
    startScene->AddGameObject(exitButton);
}

void Game::SetupMainScene(std::shared_ptr<IScene> mainScene, std::shared_ptr<IGameObject> player)
{
    // Player, Controller and CardDeck


    std::shared_ptr<IScript> playerAttackScript = std::static_pointer_cast<IScript, PlayerAttackScript>(std::make_shared<PlayerAttackScript>());
    std::shared_ptr<PlayerCardScript> pcs = std::make_shared<PlayerCardScript>();
    std::shared_ptr<IScript> playerCardScript = std::static_pointer_cast<IScript>(pcs);

    player->SetPosition({ 150, 150 });
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
    std::shared_ptr<IGameObject> collisionObject = std::make_shared<Empty>();
    std::shared_ptr<IScript> collisionHandler = std::static_pointer_cast<IScript, CollisionHandler>(std::make_shared<CollisionHandler>(32));
    collisionObject->AttachScript(collisionHandler);
    mainScene->AddGameObject(collisionObject);


    // Managers
    ProjectileManager::Initialize(ProjectileType::BishopBall, 10);
    ProjectileManager::Initialize(ProjectileType::PawnPellet, 10);
    HealthBarManager::Initialize(5);
    ManaBarManager::Initialize(3);
    ManaBarManager::RefillManaShard(5);


    // Temporary Exit Button
    std::shared_ptr<IGameObject> exitButton = std::make_shared<Button>(ButtonType::Quit);
    exitButton->SetPosition({ 0, 280 });
    mainScene->AddGameObject(exitButton);
     
}

void Game::SetupPauseScene(std::shared_ptr<IScene> pauseScene)
{
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "PauseMouse", "mouse.png");

    std::shared_ptr<IGameObject> playButton = std::make_shared<Button>(ButtonType::Play);
    playButton->SetPosition({ 245, 150 });
    std::shared_ptr<IGameObject> quitButton = std::make_shared<Button>(ButtonType::Quit);
    quitButton->SetPosition({ 245, 200 });
    std::shared_ptr<IGameObject> continueButton = std::make_shared<Button>(ButtonType::Quit);
    continueButton->SetPosition({ 245, 200 });

    pauseScene->AddGameObject(quitButton);
    pauseScene->AddGameObject(continueButton);

    //Create animated background
    for (size_t i = 0; i < 8; i++)
    {
        std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, std::string("PauseBackground" + std::to_string(i)), "pawnground.apng");
        std::shared_ptr<IScript> script = std::static_pointer_cast<IScript, PauseBackgroundScript>(std::make_shared<PauseBackgroundScript>());
        background->AttachScript(script);
        background->SetPosition({ float(80 * i), 0 });
        pauseScene->AddGameObject(background);
    }

}

void Game::SetupDeathScene(std::shared_ptr<IScene> deathScene, std::shared_ptr<IGameObject> player)
{
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "PausMouse", "mouse.png");

    std::shared_ptr<IGameObject> restartButton = std::make_shared<Button>(ButtonType::Play);
    restartButton->SetPosition({ 245, 150 });
    std::shared_ptr<IGameObject> quitButton = std::make_shared<Button>(ButtonType::Quit);
    quitButton->SetPosition({ 245, 210 });
       

    deathScene->AddGameObject(player);
    deathScene->AddGameObject(mouse);
    deathScene->AddGameObject(restartButton);
    deathScene->AddGameObject(quitButton);
}
