#pragma once

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
};
