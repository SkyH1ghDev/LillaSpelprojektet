#pragma once
#include "IUIClicked.hpp"
#include <iostream>

class MenuClicked : public IUIClicked
{
public:
    void Clicked() override;
};