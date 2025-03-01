#pragma once
#include "IEntityUseCard.hpp"

class EnemyUseCard : public IEntityUseCard
{
public:
    void UseCard() override;
};