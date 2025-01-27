#pragma once
#include "IVisible.hpp"
#include <iostream>

class PlayerVisible : public IVisible
{
public:
    void Visible() override;
};