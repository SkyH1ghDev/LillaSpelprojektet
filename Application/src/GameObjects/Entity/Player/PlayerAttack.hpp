#pragma once
#include "IAttack.hpp"
#include <iostream>

class PlayerAttack : public IAttack
{
public:
    void Attack() override;
};