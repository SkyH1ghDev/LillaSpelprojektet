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
#include "EnemyManager.hpp"
#include "Projectile/ProjectileManager.hpp"
#include "GameObjects/Scripts/Wand.hpp"
#include "Collision/CollisionHandler.hpp"
#include "GameObjects/UI/Bar/HealthBarManager.hpp"
#include "GameObjects/UI/Bar/ManaBarManager.hpp"
#include "Abilities/StatSheet.hpp"
#include "Scripts/AnimateMesh.hpp"
#include "Button.hpp"
#include "PlayerFactory.hpp"
#include "GameObjects/Scripts/PauseControl.hpp"
#include "DeckManager.hpp"
#include "Numbers.hpp"
#include "StaticMesh.hpp"

void Game::SetupGame()
{
    PlayerFactory playerFactory;
    std::shared_ptr<Entity> player = playerFactory.CreateEntity();

    std::shared_ptr<PlayerCardScript> pcs = std::make_shared<PlayerCardScript>();

    // Setup Start Scene
    if (!SceneManager::RegisterScene("main", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> mainScene = SceneManager::GetScene("main");
    SetupMainScene(mainScene, player);

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

    if (!SceneManager::RegisterScene("victory", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> victoryScene = SceneManager::GetScene("victory");
    SetupVictoryScene(victoryScene, player);

    // Setup Main Scene
    if (!SceneManager::RegisterScene("game", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> gameScene = SceneManager::GetScene("game");
    SetupGameScene(gameScene, player, std::static_pointer_cast<IScript>(pcs), pcs->GetCardDeck());

    // Setup Upgrade Scene
    if (!SceneManager::RegisterScene("upgrade", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }
    std::shared_ptr<IScene> upgradeScene = SceneManager::GetScene("upgrade");
    SetupUpgradeScene(upgradeScene, pcs->GetCardDeck());

    std::shared_ptr<Empty> escape = std::make_shared<Empty>();
    std::shared_ptr<IScript> pauseScript = std::static_pointer_cast<IScript, PauseControl>(std::make_shared<PauseControl>());
    escape->AttachScript(pauseScript);
    gameScene->AddGameObject(escape);
    pauseScene->AddGameObject(escape);
    upgradeScene->AddGameObject(escape);
    
}

void Game::ResetGame()
{
    SceneManager::ClearScene("game");
    SceneManager::ClearScene("main");
    SceneManager::ClearScene("pause");
    SceneManager::ClearScene("secondScene");
    EnemyManager::Cleanup();
    HealthBarManager::Cleanup();
    ManaBarManager::Cleanup();
    StatSheet::Reset();

    SetupGame();

    // OnStart for all GameObjects

    for (const auto& gameObject : GameObjectManager::GetGameObjects())
    {
        gameObject->OnStart();
    }
    SceneManager::LoadScene("main");
}

void Game::SetupMainScene(std::shared_ptr<IScene> startScene, std::shared_ptr<IGameObject> player)
{
    std::shared_ptr<IGameObject> title = std::make_shared<Mesh>(MeshType::Title, "Title", "title_logo_v1.png");
    title->SetPosition({161, 10});
    std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, "Background", "start_background.png");
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "MenuMouse", "mouse.png");

    std::shared_ptr<IGameObject> playButton = std::make_shared<Button>(ButtonType::Play);
    playButton->SetPosition({245, 150 });
    std::shared_ptr<IGameObject> exitButton = std::make_shared<Button>(ButtonType::Exit);
    exitButton->SetPosition({ 245, 210 });

    startScene->AddGameObject(player);
    startScene->AddGameObject(title);
    startScene->AddGameObject(background);
    startScene->AddGameObject(mouse);
    startScene->AddGameObject(playButton);
    startScene->AddGameObject(exitButton);
}

void Game::SetupGameScene(std::shared_ptr<IScene> mainScene, std::shared_ptr<IGameObject> player, std::shared_ptr<IScript> playerCardScript, std::shared_ptr<IGameObject> cardDeck)
{
    // Player, Controller and CardDeck

    std::shared_ptr<IScript> playerAttackScript = std::static_pointer_cast<IScript, PlayerAttackScript>(std::make_shared<PlayerAttackScript>());

    player->SetPosition({ 150, 150 });
    player->AttachScript(playerAttackScript);
    player->AttachScript(playerCardScript);
    player->CenterOrigin(true);

    mainScene->AddGameObject(player);
    mainScene->AddGameObject(cardDeck);

    //Enemies
    std::shared_ptr<EnemyManager> enemyManager = std::make_shared<EnemyManager>(player);
    mainScene->AddGameObject(enemyManager);

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

    //round text and numbers
    std::shared_ptr<IGameObject> roundText = std::make_shared<Mesh>(MeshType::Object, "RoundText", "text_round");
    roundText->SetPosition({ 408, 1 });
    std::shared_ptr<IScript> textScript = std::static_pointer_cast<IScript, AnimateScript>(std::make_shared<AnimateScript>());
    roundText->AttachScript(textScript);

    mainScene->AddGameObject(roundText);
    std::shared_ptr<IGameObject> num1 = std::make_shared<Numbers>(NumberPos::First);
    std::shared_ptr<IGameObject> num2 = std::make_shared<Numbers>(NumberPos::Second);
    num1->SetPosition({ 560, 1 });
    num2->SetPosition({ 584, 1 });
    mainScene->AddGameObject(num1);
    mainScene->AddGameObject(num2);

    // Collision
    std::shared_ptr<IGameObject> collisionObject = std::make_shared<Empty>();
    std::shared_ptr<IScript> collisionHandler = std::static_pointer_cast<IScript, CollisionHandler>(std::make_shared<CollisionHandler>(32));
    collisionObject->AttachScript(collisionHandler);
    mainScene->AddGameObject(collisionObject);


    // Managers
    PoolManager<Projectile, ProjectileType>::Initialize(ProjectileType::PawnPellet, 20);
    PoolManager<Projectile, ProjectileType>::Initialize(ProjectileType::BishopBall, 20);
    HealthBarManager::Initialize(5);
    ManaBarManager::Initialize(3);
    ManaBarManager::RefillManaShard(5);

    //StaicMeshes
    DX::XMFLOAT2 pos = { 150, 150 };
    std::shared_ptr<IGameObject> testMesh = std::make_shared<StaticMesh>("testMesh", "heart.png", pos, 6, 1);
    mainScene->AddGameObject(testMesh);
}

void Game::SetupPauseScene(std::shared_ptr<IScene> pauseScene)
{
    //Buttons and mouse
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "MenuMouse", "mouse.png");

    std::shared_ptr<IGameObject> continueButton = std::make_shared<Button>(ButtonType::Continue);
    continueButton->SetPosition({ 244, 150 });
    std::shared_ptr<IGameObject> quitButton = std::make_shared<Button>(ButtonType::Quit);
    quitButton->SetPosition({ 244, 210 });
    pauseScene->AddGameObject(continueButton);
    pauseScene->AddGameObject(quitButton);
    pauseScene->AddGameObject(mouse);

    //Animated text
    std::shared_ptr<IScript> updateScript = std::static_pointer_cast<IScript, AnimateScript>(std::make_shared<AnimateScript>());
    std::shared_ptr<Mesh> pausedText = std::make_shared<Mesh>(MeshType::Object, "PauseText", "text_paused");
    pausedText->AttachScript(updateScript);
    pausedText->SetPosition({241, 75});
    pauseScene->AddGameObject(pausedText);

    //Create animated background
    for (size_t i = 0; i < 8; i++)
    {
        std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, std::string("PauseBackground" + std::to_string(i)), "background_paused");
        std::shared_ptr<IScript> script = std::static_pointer_cast<IScript, AnimateScript>(std::make_shared<AnimateScript>());
        background->AttachScript(script);
        background->SetPosition({ float(80 * i), 0 });
        pauseScene->AddGameObject(background);
    }

}

void Game::SetupDeathScene(std::shared_ptr<IScene> deathScene, std::shared_ptr<IGameObject> player)
{
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "PauseMouse", "mouse.png");

    std::shared_ptr<IGameObject> restartButton = std::make_shared<Button>(ButtonType::Play);
    restartButton->SetPosition({ 245, 150 });
    std::shared_ptr<IGameObject> quitButton = std::make_shared<Button>(ButtonType::Quit);
    quitButton->SetPosition({ 245, 210 });

    std::shared_ptr<IGameObject> gameOverText = std::make_shared<Mesh>(MeshType::Object, "CapturedText", "text_captured");
    std::shared_ptr<IScript> script = std::static_pointer_cast<IScript, AnimateScript>(std::make_shared<AnimateScript>());
    gameOverText->AttachScript(script);
    gameOverText->SetPosition( { 190, 75 });
    deathScene->AddGameObject(gameOverText);

    deathScene->AddGameObject(mouse);
       
    deathScene->AddGameObject(player);
    deathScene->AddGameObject(restartButton);
    deathScene->AddGameObject(quitButton);
}

void Game::SetupVictoryScene(std::shared_ptr<IScene> victoryScene, std::shared_ptr<IGameObject> player)
{
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "PauseMouse", "mouse.png");

    std::shared_ptr<IGameObject> restartButton = std::make_shared<Button>(ButtonType::Play);
    restartButton->SetPosition({ 245, 150 });
    std::shared_ptr<IGameObject> quitButton = std::make_shared<Button>(ButtonType::Quit);
    quitButton->SetPosition({ 245, 210 });

    std::shared_ptr<IGameObject> gameOverText = std::make_shared<Mesh>(MeshType::Object, "PromotedText", "text_promoted");
    std::shared_ptr<IScript> script = std::static_pointer_cast<IScript, AnimateScript>(std::make_shared<AnimateScript>());
    gameOverText->AttachScript(script);
    gameOverText->SetPosition({ 190 + 27, 75 - 106 }); 
    victoryScene->AddGameObject(gameOverText);

    victoryScene->AddGameObject(mouse);

    victoryScene->AddGameObject(player);
    victoryScene->AddGameObject(restartButton);
    victoryScene->AddGameObject(quitButton);
}

void Game::SetupUpgradeScene(std::shared_ptr<IScene> upgradeScene, std::shared_ptr<IGameObject> cardDeck)
{
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "PauseMouse", "mouse.png");
    upgradeScene->AddGameObject(mouse);

    
    std::shared_ptr<IGameObject> chesster = std::make_shared<Mesh>(MeshType::Object, "chesster_closeup", "chesster_closeup");
    std::shared_ptr<IScript> updateChesster = std::static_pointer_cast<IScript, AnimateScript>(std::make_shared<AnimateScript>());
    chesster->AttachScript(updateChesster);
    upgradeScene->AddGameObject(chesster);
    chesster->SetPosition({ 420, 120 });

    std::shared_ptr<IGameObject> cardButton1 = std::make_shared<Button>(ButtonType::Card, 1);
    cardButton1->SetPosition({ 200, 145 });
    std::shared_ptr<IGameObject> cardButton2 = std::make_shared<Button>(ButtonType::Card, 2);
    cardButton2->SetPosition({ 295, 145 });
    std::shared_ptr<IGameObject> cardButton3 = std::make_shared<Button>(ButtonType::Card, 3);
    cardButton3->SetPosition({ 390, 145 });

    upgradeScene->AddGameObject(cardButton1);
    upgradeScene->AddGameObject(cardButton2);
    upgradeScene->AddGameObject(cardButton3);

    std::shared_ptr<IGameObject> card1 = std::make_shared<Mesh>(MeshType::Object, "card1", "card_basic.png");
    card1->SetPosition({ 200, 145 });
    std::shared_ptr<IGameObject> card2 = std::make_shared<Mesh>(MeshType::Object, "card2", "card_basic.png");
    card2->SetPosition({ 295, 145 });
    std::shared_ptr<IGameObject> card3 = std::make_shared<Mesh>(MeshType::Object, "card3", "card_basic.png");
    card3->SetPosition({ 390, 145 });

    upgradeScene->AddGameObject(card1);
    upgradeScene->AddGameObject(card2);
    upgradeScene->AddGameObject(card3);

    std::vector<std::shared_ptr<Mesh>> backgroundSegments;

    for (size_t i = 0; i < 8; i++)
    {
        std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, std::string("upgradeBackground" + std::to_string(i)), "background_card");
        std::shared_ptr<IScript> script = std::static_pointer_cast<IScript, AnimateScript>(std::make_shared<AnimateScript>());
        background->AttachScript(script);
        background->SetPosition({ float(80 * i), 0 });
        upgradeScene->AddGameObject(background);
        backgroundSegments.push_back(std::static_pointer_cast<Mesh>(background));
    }

    std::shared_ptr<IGameObject> text = std::make_shared<Mesh>(MeshType::Object, "UpgradeText", "text_pick");
    text->SetPosition({ 180, 75 });
    std::shared_ptr<IScript> textScript = std::static_pointer_cast<IScript, AnimateScript>(std::make_shared<AnimateScript>());
    text->AttachScript(textScript);
    upgradeScene->AddGameObject(text);

    std::shared_ptr<DeckManager> deckManager = std::make_shared<DeckManager>();
    upgradeScene->AddGameObject(std::static_pointer_cast<IGameObject>(deckManager));
    DeckManager::Initialize(cardButton1, cardButton2, cardButton3, card1, card2, card3, cardDeck, chesster, text, backgroundSegments);
}