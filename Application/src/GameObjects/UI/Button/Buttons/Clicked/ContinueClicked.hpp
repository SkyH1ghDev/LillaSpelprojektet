#pragma once
#include "IUIClicked.hpp"
#include <iostream>

class ContinueClicked : public IUIClicked
{
public:
    void Clicked() override;
};