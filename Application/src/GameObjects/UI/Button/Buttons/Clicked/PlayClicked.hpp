#pragma once
#include "IClicked.hpp"
#include <iostream>

class PlayClicked : public IClicked
{
public:
    void Clicked() override;
};