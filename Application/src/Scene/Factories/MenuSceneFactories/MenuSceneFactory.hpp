#pragma once

#include <SpEngine/Assets/IScene.hpp>
#include <memory>

// Factory class for creating GameScene instances
class MenuSceneFactory {
public:
    static std::unique_ptr<IScene> CreateScene();
};
