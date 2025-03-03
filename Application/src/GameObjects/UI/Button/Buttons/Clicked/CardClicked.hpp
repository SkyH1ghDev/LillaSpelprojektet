#pragma once
#include "IUIClicked.hpp"

class CardClicked : public IUIClicked
{
public:
    void Clicked(int value) override;
};