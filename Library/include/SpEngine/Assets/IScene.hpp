#pragma once

class IScene {
public:
    virtual void display() const = 0; // Add const
    virtual ~IScene() = default;
};


