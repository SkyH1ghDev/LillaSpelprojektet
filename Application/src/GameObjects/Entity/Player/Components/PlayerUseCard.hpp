#pragma once
#include "IEntityUseCard.hpp"

class PlayerUseCard : public IEntityUseCard
{
public:
    void UseCard() override;
};