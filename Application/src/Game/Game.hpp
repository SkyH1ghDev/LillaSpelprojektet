#pragma once

class Game
{
public:
    Game();
    ~Game() = default;
    Game(const Game& other) = default;
    Game& operator=(const Game& other) = default;
    Game(Game&& other) noexcept = default;
    Game& operator=(Game&& other) noexcept = default;
};
