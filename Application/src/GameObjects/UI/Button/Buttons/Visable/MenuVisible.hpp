#pragma once
#include "IVisible.hpp"
#include <iostream>

class MenuVisible: public IVisible
{
public:
    void Visible(std::string& texture) override;
};