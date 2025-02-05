#pragma once
#include "IVisible.hpp"
#include <iostream>

class ExitMenuVisible : public IVisible
{
public:
    void Visible(std::string& texture) override;
};