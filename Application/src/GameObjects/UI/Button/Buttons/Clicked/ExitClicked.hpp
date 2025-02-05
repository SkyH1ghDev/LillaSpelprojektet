#pragma once
#include "IClicked.hpp"
#include <iostream>

class ExitClicked : public IClicked
{
public:
    void Clicked() override;
};