#pragma once

#include "Button.hpp"

class ButtonContinue : public Button
{
public:
    ButtonContinue() = default;
    ~ButtonContinue() = default;
    ButtonContinue(const ButtonContinue& other) = default;
    ButtonContinue& operator=(const ButtonContinue& other) = default;
    ButtonContinue(ButtonContinue&& other) noexcept = default;
    ButtonContinue& operator=(ButtonContinue&& other) noexcept = default;

private:
    void ClickEvent() override;
};