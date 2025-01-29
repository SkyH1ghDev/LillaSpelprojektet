#pragma once

#include <SpEngine/Assets/IScene.hpp>
#include <memory>

// Factory class for creating GameScene instances
class GameSceneFactory {
public:
    static std::unique_ptr<IScene> CreateScene(int level);
};
