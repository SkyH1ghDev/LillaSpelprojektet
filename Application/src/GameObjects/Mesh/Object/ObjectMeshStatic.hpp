#pragma once
#include "IMeshStatic.hpp"
#include <iostream>

class ObjectMeshStatic : public IMeshStatic
{
public:
    void Static() override;
};