#pragma once
#include "IUIClicked.hpp"

class ContinueClicked : public IUIClicked
{
public:
    void Clicked(int value) override;
};