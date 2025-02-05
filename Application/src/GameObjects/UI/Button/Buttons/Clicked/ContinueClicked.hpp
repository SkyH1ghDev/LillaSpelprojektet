#pragma once
#include "IVisible.hpp"
#include <iostream>

class ContinueVisible : public IVisible
{
public:
    void Visible(std::string& texture) override;
};