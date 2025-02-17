#include "HealthBarManager.hpp"

std::stack<std::shared_ptr<IGameObject>> HealthBarManager::m_health;

void HealthBarManager::Initialize(size_t heartNumber)
{
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    for (size_t i = 0; i < heartNumber; ++i) {
        std::shared_ptr<IGameObject> heartEmpty = std::make_shared<Heart>(HeartType::Empty);
        std::shared_ptr<IGameObject> heartFull = std::make_shared<Heart>(HeartType::Full);
        float heartPositionX = 30.0f + 25.0f * i;
        heartEmpty->SetPosition({ heartPositionX, 10.0f });
        heartFull->SetPosition({ heartPositionX, 10.0f });

        m_health.push(heartFull);
        testScene->AddGameObject(heartFull);
        testScene->AddGameObject(heartEmpty);
    }
}

void HealthBarManager::AddHeart()
{

}

void HealthBarManager::RemoveHeart(size_t healthDamage)
{
    for (size_t i = 0; i < healthDamage; ++i) {
        std::shared_ptr<Heart> heart = std::dynamic_pointer_cast<Heart>(m_health.top());
        heart->UpdateHeart(false);
        m_health.pop();
    }
    return;
}
