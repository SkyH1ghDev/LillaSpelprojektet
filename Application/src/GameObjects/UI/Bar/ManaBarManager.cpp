#include "ManaBarManager.hpp"

std::vector<std::shared_ptr<IGameObject>> ManaBarManager::manaBar;
std::vector<std::shared_ptr<IGameObject>> ManaBarManager::manaCrystal;
int ManaBarManager::maxMana = 0;
int ManaBarManager::manaBarIndex = 0;
int ManaBarManager::manaCrystalIndex = 0;

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
    maxMana = manaBar.size();
}

void ManaBarManager::RefillMana(size_t manaNumber)
{
    for (size_t i = 0; i < manaNumber; ++i) {
        if (manaCrystalIndex >= 5) {
            manaBarIndex++;
            manaCrystalIndex = 0;
        }

        if (manaBarIndex >= maxMana) {
            manaBarIndex = maxMana - 1;
            return;
        }

        std::shared_ptr<Mana> mana = std::dynamic_pointer_cast<Mana>(manaBar[manaBarIndex]);
        if (mana) 
            mana->UpdateMana(true, manaCrystalIndex);
        manaCrystalIndex++;
    }
    return;
}

void ManaBarManager::RemoveMana(size_t manaNumber)
{
    for (size_t i = 0; i < manaNumber; ++i) {
        


    }
    return;
}
