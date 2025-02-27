#pragma once
#include <SpEngine/Assets/Game/IGameObject.hpp>

enum class ManaType {
    Ready
};

class Mana : public IGameObject
{
public:
    Mana() = default;
    ~Mana() = default;
    Mana(const Mana& other) = default;
    Mana& operator=(const Mana& other) = default;
    Mana(Mana&& other) noexcept = default;
    Mana& operator=(Mana&& other) noexcept = default;

    Mana(ManaType type);

    void Update() override;
    void OnStart() override;
    void Reset() override;
    void UpdateMana(bool positive, size_t manaCrystalIndex); //remove mana if negative, add mana if positive

private:
    std::string textureNameUpdate;
    ManaType m_type;
};