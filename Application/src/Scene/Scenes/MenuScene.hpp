#pragma once

#include <SpEngine/Assets/IScene.hpp>

class MenuScene : public IScene {
public:
    explicit MenuScene(); // Constructor declaration
    void Display() const override;      // Overriding display method
};
