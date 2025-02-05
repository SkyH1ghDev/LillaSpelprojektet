#pragma once
#include "IEntityAttack.hpp"
#include <iostream>

class PlayerAttack : public IEntityAttack
{
public:
    void Attack() override;
};