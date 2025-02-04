# pragma once
#include <SpEngine/Assets/IGameObject.hpp>
#include <iostream>

class Button : public IGameObject
{
public:
    Button() = default;
    ~Button() = default;
    Button(const Button& other) = default;
    Button& operator=(const Button& other) = default;
    Button(Button&& other) noexcept = default;
    Button& operator=(Button&& other) noexcept = default;

    void Update() override;
    void OnStart() override;
    void Clicked();

private:
    virtual void ClickEvent() = 0;

private:
    float width;
    float height;
};