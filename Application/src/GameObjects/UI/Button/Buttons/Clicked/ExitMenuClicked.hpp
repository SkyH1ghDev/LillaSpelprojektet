#pragma once
#include "IClicked.hpp"
#include <iostream>

class ExitMenuClicked : public IClicked
{
public:
    void Clicked() override;
};