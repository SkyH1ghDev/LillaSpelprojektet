#pragma once

#include <SpEngine/Assets/IScene.hpp>

class MenuScene : public IScene {
public:
    void Display() const override;      // Overriding display method

    void Update(float deltaTime) override;

    void OnEnter() override;

    void OnExit() override;
};