#pragma once
#include "IUIClicked.hpp"

class ExitClicked : public IUIClicked
{
public:
    void Clicked(int value) override;
};