#pragma once
#include <SpEngine/Assets/Game/IGameObject.hpp>
#include <SpEngine/Input/Action/OnMouseClick.hpp>

#include "IUIVisible.hpp"
#include "IUIClicked.hpp"

// Define an enum for the entity type
enum class ButtonType {
    Play,
    Continue,
    Quit,
    Exit
};

class Button : public IGameObject
{
public:
    Button() = default;
    ~Button() = default;
    Button(const Button& other) = default;
    Button& operator=(const Button& other) = default;
    Button(Button&& other) noexcept = default;
    Button& operator=(Button&& other) noexcept = default;

    Button(ButtonType type);
    void PerformClicked();

    void Update() override;
    void OnStart() override;

private:
    std::shared_ptr<IUIVisible> m_visible;
    std::shared_ptr<IUIClicked> m_clicked;
    std::shared_ptr<OnMouseClick> m_mouseClick = std::make_shared<OnMouseClick>();
    ButtonType m_type;

private:
    void PerformVisible();
    void PerformHover();
};