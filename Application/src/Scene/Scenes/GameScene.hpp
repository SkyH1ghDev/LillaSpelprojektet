#pragma once
#include "Entity.hpp"
#include <SpEngine/Assets/IScene.hpp>
#include <vector>
#include <memory>

class GameScene : public IScene {
public:
    GameScene(int level);

    void Display() const override;
    void Update(float deltaTime) override;
    void OnEnter() override;
    void OnExit() override;

    DX::XMFLOAT2 GetEntityPosition(int i) const; 
private:
    int m_level;
    std::vector<std::unique_ptr<Entity>> m_entities;

    void InitializeEntities();
};
