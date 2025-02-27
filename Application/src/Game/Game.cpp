#include "Game.hpp"

#include <SpEngine/Manager/SceneManager.hpp>

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

void Game::SetupGame()
{
    // Setup Main Scene

    if (!SceneManager::RegisterScene("main", GameSceneFactory::CreateScene(0)))
    {
        std::cerr << "Scene registration failed!\n";
    }

    SceneManager::LoadScene("main");

    std::shared_ptr<IScene> mainScene = SceneManager::GetScene("main");

    std::shared_ptr<IGameObject> player = std::make_shared<Entity>(EntityType::Player, "Player");
    std::shared_ptr<IScript> playerController = std::make_shared<PlayerController>();
    player->AttachScript(playerController);
    std::shared_ptr<IScript> playerAttackScript = std::make_shared<PlayerAttackScript>();
    player->AttachScript(playerAttackScript);
    std::shared_ptr<PlayerCardScript> playerCardScript = std::make_shared<PlayerCardScript>();
    player->AttachScript(playerCardScript);
    player->CenterOrigin(true);
    player->SetPosition({ 150, 150 });
    mainScene->AddGameObject(player);

    std::shared_ptr<Entity> playerEntity = std::dynamic_pointer_cast<Entity>(player);
    playerEntity->Initialize();

    std::shared_ptr<IGameObject> wand = std::make_shared<Mesh>(MeshType::Object, "Wand", "wandMockupOne.apng");
    std::shared_ptr<IScript> wandScript = std::static_pointer_cast<IScript, WandScript>(std::make_shared<WandScript>(player));
    wand->AttachScript(wandScript);
    wand->CenterOrigin(true);
    mainScene->AddGameObject(wand);
    
    std::shared_ptr<IGameObject> background = std::make_shared<Mesh>(MeshType::Background, "Background", "wood_arena_v1.png");
    mainScene->AddGameObject(background);
    
    std::shared_ptr<IGameObject> mouse = std::make_shared<Mesh>(MeshType::Mouse, "Mouse", "crosshair.png");
    mouse->CenterOrigin(true);
    mainScene->AddGameObject(mouse);

    std::shared_ptr<EnemyManager> enemyManager = std::make_shared<EnemyManager>(player);
    mainScene->AddGameObject(enemyManager);
   
    PoolManager<Projectile, ProjectileType>::Initialize(ProjectileType::PawnPellet, 20, "PawnPellet");
    PoolManager<Projectile, ProjectileType>::Initialize(ProjectileType::BishopBall, 20, "PawnPellet");

    std::shared_ptr<IGameObject> collisionObject = std::make_shared<Empty>();
    std::shared_ptr<IScript> collisionHandler = std::static_pointer_cast<IScript, CollisionHandler>(std::make_shared<CollisionHandler>(32));
    collisionObject->AttachScript(collisionHandler);
    mainScene->AddGameObject(collisionObject);
      
    HealthBarManager::Initialize(5);
    ManaBarManager::Initialize(3);

    ManaBarManager::RefillManaShard(5); 
    std::shared_ptr<IGameObject> cardDeck = playerCardScript->GetCardDeck();
    mainScene->AddGameObject(cardDeck);

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
    ProjectileManager::Cleanup(ProjectileType::BishopBall);
    ProjectileManager::Cleanup(ProjectileType::PawnPellet);
    HealthBarManager::Cleanup();
    ManaBarManager::Cleanup();
    StatSheet::Reset();
}
