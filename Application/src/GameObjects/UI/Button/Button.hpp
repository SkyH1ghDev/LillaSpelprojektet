#pragma once
#include <SpEngine/Assets/IGameObject.hpp>
#include <SpEngine/Input/Action/OnMouseClick.hpp>
#include <iostream>

#include "IUIVisible.hpp"
#include "IUIClicked.hpp"

// Define an enum for the entity type
enum class ButtonType {
    Play,
    Exit,
    Menu,
    Continue,
    ExitMenu
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
    void PerformVisible() { if (m_visible) m_visible->Visible(m_textureName, m_layerFloat, m_scaleFloat, m_position); };
    void PerformClicked();


    void Update() override;
    void OnStart() override;

private:
    std::shared_ptr<IUIVisible> m_visible;
    std::shared_ptr<IUIClicked> m_clicked;
    std::shared_ptr<OnMouseClick> m_mouseClick = std::make_shared<OnMouseClick>();
    ButtonType m_type;
};