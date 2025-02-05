#pragma once
#include "IEntityUseCard.hpp"
#include <iostream>

class PlayerUseCard : public IEntityUseCard
{
public:
    void UseCard() override;
};