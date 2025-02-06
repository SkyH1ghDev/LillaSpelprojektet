#pragma once
#include <SpEngine/Assets/IGameObject.hpp>
#include <SpEngine/Input/Action/OnMouseClick.hpp>
#include <iostream>

#include "IVisible.hpp"
#include "IClicked.hpp"

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
    void PerformVisible() { if (m_visible) m_visible->Visible(this->m_texture); }
    void PerformClicked();


    void Update() override;
    void OnStart() override;

private:
    std::shared_ptr<IVisible> m_visible;
    std::shared_ptr<IClicked> m_clicked;

    std::shared_ptr<OnMouseClick> m_mouseClick = std::make_shared<OnMouseClick>();
    ButtonType m_type;

    float width;
    float height;
};