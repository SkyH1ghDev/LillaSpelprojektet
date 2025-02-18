#pragma once
#include "IUIClicked.hpp"
#include <iostream>

class PlayClicked : public IUIClicked
{
public:
    void Clicked() override;
};