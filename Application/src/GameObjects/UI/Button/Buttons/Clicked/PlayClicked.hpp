#pragma once
#include "IVisible.hpp"
#include <iostream>

class PlayVisible : public IVisible
{
public:
    void Visible(std::string& texture) override;
};