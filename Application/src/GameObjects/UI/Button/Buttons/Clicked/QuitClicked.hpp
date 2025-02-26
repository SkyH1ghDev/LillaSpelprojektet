#pragma once
#include "IUIClicked.hpp"

class QuitClicked : public IUIClicked
{
public:
    void Clicked() override;
};