#pragma once
#include "IVisible.hpp"
#include <iostream>

class ExitVisible : public IVisible
{
public:
    void Visible(std::string& texture) override;
};