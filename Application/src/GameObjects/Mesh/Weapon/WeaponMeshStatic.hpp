#pragma once
#include "IMeshStatic.hpp"
#include <iostream>

class WeaponMeshStatic : public IMeshStatic
{
public:
    void Static() override;
};