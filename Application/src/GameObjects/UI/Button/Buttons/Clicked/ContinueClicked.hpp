#pragma once
#include "IClicked.hpp"
#include <iostream>

class ContinueClicked : public IClicked
{
public:
    void Clicked() override;
};