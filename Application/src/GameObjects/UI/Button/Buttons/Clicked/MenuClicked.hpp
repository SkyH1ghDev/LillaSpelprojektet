#pragma once
#include "IClicked.hpp"
#include <iostream>

class MenuClicked : public IClicked
{
public:
    void Clicked() override;
};