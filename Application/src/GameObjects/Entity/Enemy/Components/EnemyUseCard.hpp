#pragma once
#include "IEntityUseCard.hpp"
#include <iostream>

class EnemyUseCard : public IEntityUseCard
{
public:
    void UseCard() override;
};