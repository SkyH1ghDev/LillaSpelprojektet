#pragma once
#include "IUseCard.hpp"
#include <iostream>

class EnemyUseCard : public IUseCard
{
public:
    void UseCard() override;
};