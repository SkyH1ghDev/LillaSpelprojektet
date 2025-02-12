#pragma once
#include "IUIClicked.hpp"
#include <iostream>

class ExitMenuClicked : public IUIClicked
{
public:
    void Clicked() override;
};