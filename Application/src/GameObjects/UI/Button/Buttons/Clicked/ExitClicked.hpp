#pragma once
#include "IUIClicked.hpp"
#include <iostream>

class ExitClicked : public IUIClicked
{
public:
    void Clicked() override;
};