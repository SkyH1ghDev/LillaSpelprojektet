#pragma once

#include "IGameObject.hpp"
class IScene {
public:
    virtual ~IScene() = default;
    virtual void Display() const = 0; // Add const   
};


