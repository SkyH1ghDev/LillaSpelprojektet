#pragma once
#include <SpEngine/Assets/IScene.hpp>
#include <memory>

class Game
{
public:
    Game() = default;
    ~Game() = default;
    Game(const Game& other) = default;
    Game& operator=(const Game& other) = default;
    Game(Game&& other) noexcept = default;
    Game& operator=(Game&& other) noexcept = default;
    void SetupGame();
    void ResetGame();

private:
    void SetupStartScene(std::shared_ptr<IScene> startScene);
};
