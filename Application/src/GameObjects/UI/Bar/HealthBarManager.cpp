#include "HealthBarManager.hpp"

std::vector<std::shared_ptr<IGameObject>> HealthBarManager::health;
int HealthBarManager::maxHealth = 0;
int HealthBarManager::heartIndex = 0;

void HealthBarManager::Initialize(size_t heartNumber)
{
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    for (size_t i = 0; i < heartNumber; ++i) {
        auto heartEmpty = std::make_shared<Heart>(HeartType::Empty);
        auto heartFull = std::make_shared<Heart>(HeartType::Full);
        float heartPositionX = 30.0f + 25.0f * i;
        heartEmpty->SetPosition({ heartPositionX, 10.0f });
        heartFull->SetPosition({ heartPositionX, 10.0f });

        health.push_back(heartFull);
        heartIndex++;
        testScene->AddGameObject(heartFull);
        testScene->AddGameObject(heartEmpty);
    }
    heartIndex--;
    maxHealth = health.size();
}

void HealthBarManager::RefillHeart(size_t healthIncrease)
{
    for (size_t i = 0; i < healthIncrease; ++i) {
        if (heartIndex >= maxHealth-1) 
            return;
        
        heartIndex++;
        std::shared_ptr<Heart> heart = std::dynamic_pointer_cast<Heart>(health[heartIndex]);
        if (heart)
            heart->UpdateHeart(true);
    }
    return;
}

void HealthBarManager::RemoveHeart(size_t healthDamage)
{
    for (size_t i = 0; i < healthDamage; ++i) {
        if (heartIndex < 0)
            return;

        std::shared_ptr<Heart> heart = std::dynamic_pointer_cast<Heart>(health[heartIndex]);
        if (heart)
            heart->UpdateHeart(false);

        heartIndex--;

    }
    return;
}

void HealthBarManager::AddNewHeart(size_t heartNumber)
{
    RefillHeart(30);

    heartIndex = maxHealth - 1;
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    int currentHearts = heartIndex + 1;
    for (size_t i = 0; i < heartNumber; ++i) {
        if (maxHealth > 30)
            return;

        auto heartEmpty = std::make_shared<Heart>(HeartType::Empty);
        auto heartFull = std::make_shared<Heart>(HeartType::Full);
        float heartPositionX = 30 + 25.0f * i + 25.0f * currentHearts;
        heartEmpty->SetPosition({ heartPositionX, 10.0f });
        heartFull->SetPosition({ heartPositionX, 10.0f });

        health.push_back(heartFull);
        heartIndex++;
        testScene->AddGameObject(heartFull);
        testScene->AddGameObject(heartEmpty);
        maxHealth = health.size();
    }


}
