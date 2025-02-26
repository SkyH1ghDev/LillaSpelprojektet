#pragma once
#include "IMeshStatic.hpp"
#include <iostream>

class PauseMeshStatic : public IMeshStatic
{
public:
    void Static() override;
};
