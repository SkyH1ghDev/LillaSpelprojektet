#include "HealthBarManager.hpp"
#include "StatSheet.hpp"

std::vector<std::shared_ptr<Heart>> HealthBarManager::health;
int HealthBarManager::maxHealth = 0;

void HealthBarManager::Initialize(size_t heartNumber)
{
    std::shared_ptr<IScene> scene = SceneManager::GetScene("main");
    for (size_t i = 0; i < heartNumber; ++i) {
        auto heart = std::make_shared<Heart>();
        float heartPositionX = 30.0f + 25.0f * i;

        heart->SetPosition({ heartPositionX, 10.0f });

        health.push_back(heart);
        scene->AddGameObject(heart);
    }
    maxHealth = health.size();
    DrawHearts();
}

void HealthBarManager::AddNewHeart(size_t heartNumber)
{
    std::shared_ptr<IScene> scene = SceneManager::GetScene("main");

    for (size_t i = 0; i < heartNumber; ++i) {
        if (maxHealth > 30)
            return;

        auto heart = std::make_shared<Heart>();
        float heartPositionX = 30 + 25.0f * i + 25.0f * maxHealth;
        heart->SetPosition({ heartPositionX, 10.0f });

        health.push_back(heart);
        scene->AddGameObject(heart);
    }
    maxHealth = health.size();
    DrawHearts();
}

void HealthBarManager::DrawHearts()
{
    float currentHealth = StatSheet::GetCurrentHealth();

    for (size_t i = 1; i < maxHealth; i++) {
        if (currentHealth > i)
            health[i]->UpdateHeart(true);
        else
            health[i]->UpdateHeart(false);
    }
}

void HealthBarManager::Cleanup()
{
    health.clear();
    maxHealth = 0;
}

void HealthBarManager::Reset()
{
    maxHealth = 5;
    DrawHearts();
}
