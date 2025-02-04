#pragma once
#include "IVisible.hpp"
#include <iostream>

class EnemyVisible : public IVisible
{
public:
    void Visible(std::string& texture, EntityState entityState) override;
};