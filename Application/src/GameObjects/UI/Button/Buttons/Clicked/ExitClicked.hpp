#pragma once
#include "IUIClicked.hpp"

class ExitClicked : public IUIClicked
{
public:
    void Clicked() override;
};