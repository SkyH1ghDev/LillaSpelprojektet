#pragma once

#include "Button.hpp"

class ButtonPause : public Button
{
public:
    ButtonPause() = default;
    ~ButtonPause() = default;
    ButtonPause(const ButtonPause& other) = default;
    ButtonPause& operator=(const ButtonPause& other) = default;
    ButtonPause(ButtonPause&& other) noexcept = default;
    ButtonPause& operator=(ButtonPause&& other) noexcept = default;

private:
    void ClickEvent() override;
};