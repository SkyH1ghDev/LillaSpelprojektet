#pragma once
#include "IMove.hpp"
#include <iostream>

class PlayerMove : public IMove
{
public:

    void Move() override;

};
