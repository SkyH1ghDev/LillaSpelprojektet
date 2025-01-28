#pragma once
#include "IMove.hpp"
#include <iostream>

class EnemyMove : public IMove
{
public:
    void Move() override;
};
