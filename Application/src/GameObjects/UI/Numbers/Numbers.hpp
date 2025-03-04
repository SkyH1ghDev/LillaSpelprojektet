#pragma once
#include <SpEngine/Assets/Game/IGameObject.hpp>

enum class NumberPos {
    First,
    Second
};

class Numbers : public IGameObject
{

public:
    Numbers() = default;
    ~Numbers() = default;
    Numbers(const Numbers& other) = default;
    Numbers& operator=(const Numbers& other) = default;
    Numbers(Numbers&& other) noexcept = default;
    Numbers& operator=(Numbers&& other) noexcept = default;

    Numbers(NumberPos numberPos);


    void Update() override;
    void OnStart() override;
    void Reset() override;

private:
    NumberPos m_pos;
};