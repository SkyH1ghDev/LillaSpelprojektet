#pragma once
#include "IUIClicked.hpp"
#include <iostream>

class QuitClicked : public IUIClicked
{
public:
    void Clicked() override;
};