#pragma once

#include "Button.hpp"

class ButtonPlay : public Button
{
public:
    ButtonPlay() = default;
    ~ButtonPlay() = default;
    ButtonPlay(const ButtonPlay& other) = default;
    ButtonPlay& operator=(const ButtonPlay& other) = default;
    ButtonPlay(ButtonPlay&& other) noexcept = default;
    ButtonPlay& operator=(ButtonPlay&& other) noexcept = default;

private:
    void ClickEvent() override;
};