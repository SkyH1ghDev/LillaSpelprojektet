#pragma once

#include <SpEngine/Assets/IScene.hpp>
#include <memory>

// Factory class for creating GameScene instances
class GameSceneFactory {
private:
    float defaultLevel; // If defaultLevel is intended to be float

public:
    explicit GameSceneFactory(float level); // Constructor takes a float
    std::unique_ptr<IScene> operator()() const;
};
