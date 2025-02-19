#include "ManaBarManager.hpp"

std::vector<std::shared_ptr<IGameObject>> manaBar;
std::vector<std::shared_ptr<IGameObject>> manaCrystal;
int maxMana = 0;
int manaBarIndex = 0;
int manaCrystalIndex = 0;

void ManaBarManager::Initialize(size_t manaNumber)
{
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    for (size_t i = 0; i < manaNumber; ++i) {
        auto manaReady = std::make_shared<Mana>(ManaType::Ready);
        float manaPositionY = 330 - 30 * i;
        manaReady->SetPosition({ 610,  manaPositionY});

        manaBar.push_back(manaReady);
        testScene->AddGameObject(manaReady);
    }
}

void ManaBarManager::RefillMana(size_t manaNumber)
{
    for (size_t i = 0; i < manaNumber; ++i) {
        if (manaBarIndex >= maxMana - 1)
            return;


    }
    return;
}

void ManaBarManager::RemoveMana(size_t manaNumber)
{

    return;
}


