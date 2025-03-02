#pragma once
#include "IUIClicked.hpp"

class PlayClicked : public IUIClicked
{
public:
    void Clicked(int value) override;
};