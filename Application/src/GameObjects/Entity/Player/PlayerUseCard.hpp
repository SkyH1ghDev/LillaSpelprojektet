#pragma once
#include "IUseCard.hpp"
#include <iostream>

class PlayerUseCard : public IUseCard
{
public:
    void UseCard() override;
};