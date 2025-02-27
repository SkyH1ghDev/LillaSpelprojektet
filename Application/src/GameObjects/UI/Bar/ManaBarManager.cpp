#include "ManaBarManager.hpp"

std::vector<std::shared_ptr<IGameObject>> ManaBarManager::manaBar;
int ManaBarManager::maxMana = 0;
int ManaBarManager::manaBarIndex = 0;
int ManaBarManager::manaCrystalIndex = 0;

void ManaBarManager::Initialize(size_t manaNumber)
{
    std::shared_ptr<IScene> testScene = SceneManager::GetScene("main");
    for (size_t i = 0; i < manaNumber; ++i) {
        auto manaReady = std::make_shared<Mana>(ManaType::Ready);
        float manaPositionY = 330 - 20 * i;
        manaReady->SetPosition({ 615,  manaPositionY});

        manaBar.push_back(manaReady);
        testScene->AddGameObject(manaReady);
    }
    maxMana = manaBar.size();
}

void ManaBarManager::RefillManaShard(size_t manaNumber)
{

    for (size_t i = 0; i < manaNumber; ++i) {
        if (manaCrystalIndex >= 5 && manaBarIndex < maxMana) {
            manaBarIndex++;
            manaCrystalIndex = 0;
        }

        if (manaBarIndex >= maxMana) {
            manaBarIndex = maxMana - 1;
            manaCrystalIndex = 5;
            return;
        }

        std::shared_ptr<Mana> mana = std::dynamic_pointer_cast<Mana>(manaBar[manaBarIndex]);
        if (mana) 
            mana->UpdateMana(true, manaCrystalIndex);
        manaCrystalIndex++;
    }
    return;
}

bool ManaBarManager::RemoveManaCrystal(size_t manaNumber)
{
    if (manaNumber > manaBarIndex + 1)
        return false;
    else if(manaNumber == manaBarIndex + 1) {
        if (manaCrystalIndex < 5)
            return false;
    }

    manaNumber *= 5;

    for (size_t i = 0; i < manaNumber; ++i) {
        if (manaCrystalIndex <= 0) {
            manaBarIndex--;
            manaCrystalIndex = 5;
        }

        std::shared_ptr<Mana> mana = std::dynamic_pointer_cast<Mana>(manaBar[manaBarIndex]);
        if (mana)
            mana->UpdateMana(false, manaCrystalIndex);
        manaCrystalIndex--;

    }
    return true;
}

void ManaBarManager::Reset()
{
    manaBarIndex = 0;
    manaCrystalIndex = 0;
}

void ManaBarManager::Cleanup()
{
    manaBar.clear();
    manaBarIndex = 0;
    manaCrystalIndex = 0;
}
