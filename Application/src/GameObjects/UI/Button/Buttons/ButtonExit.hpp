#pragma once

#include "Button.hpp"

class ButtonExit : public Button
{
public:
    ButtonExit() = default;
    ~ButtonExit() = default;
    ButtonExit(const ButtonExit& other) = default;
    ButtonExit& operator=(const ButtonExit& other) = default;
    ButtonExit(ButtonExit&& other) noexcept = default;
    ButtonExit& operator=(ButtonExit&& other) noexcept = default;

private:
    void ClickEvent() override;
};