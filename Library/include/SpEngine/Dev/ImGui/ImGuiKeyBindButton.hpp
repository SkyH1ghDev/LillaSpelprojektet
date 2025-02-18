#pragma once

#include <memory>
#include <ImGui/imgui.h>
#include <string>

#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>

class ImGuiKeyBindButton
{
public:
    ImGuiKeyBindButton() = delete;
    ImGuiKeyBindButton(const std::string& keyName, const std::string& actionName, const ImGuiKey& imGuiKey);
    
    ~ImGuiKeyBindButton() = default;
    ImGuiKeyBindButton(const ImGuiKeyBindButton& other) = default;
    ImGuiKeyBindButton& operator=(const ImGuiKeyBindButton& other) = default;
    ImGuiKeyBindButton(ImGuiKeyBindButton&& other) noexcept = default;
    ImGuiKeyBindButton& operator=(ImGuiKeyBindButton&& other) noexcept = default;

    std::string GetKeyName() const;
    std::string GetActionName() const;
    ImGuiKey GetImGuiKey() const;
    bool IsPressed() const;

    void SetKeyName(const std::string& keyName);
    void SetImGuiKey(const ImGuiKey& imGuiKey);
    void SetPressedState(const bool& pressed);
    
private:
    std::string m_keyName = "Unbound";
    std::string m_actionName;
    std::shared_ptr<IObserver> m_action;
    ImGuiKey m_imGuiKey;
    bool m_pressed = false;
};

// Constructors

inline ImGuiKeyBindButton::ImGuiKeyBindButton(const std::string& keyName, const std::string& actionName, const ImGuiKey& imGuiKey)
{
    this->m_keyName = keyName;
    this->m_actionName = actionName;
    this->m_imGuiKey = imGuiKey;
}

// Getters & Setters

inline std::string ImGuiKeyBindButton::GetKeyName() const
{
    return this->m_keyName;
}

inline std::string ImGuiKeyBindButton::GetActionName() const
{
    return this->m_actionName;
}

inline ImGuiKey ImGuiKeyBindButton::GetImGuiKey() const
{
    return this->m_imGuiKey;
}

inline bool ImGuiKeyBindButton::IsPressed() const
{
    return this->m_pressed;
}

inline void ImGuiKeyBindButton::SetKeyName(const std::string& keyName)
{
    this->m_keyName = keyName;
}

inline void ImGuiKeyBindButton::SetImGuiKey(const ImGuiKey& imGuiKey)
{
    this->m_imGuiKey = imGuiKey;
}

inline void ImGuiKeyBindButton::SetPressedState(const bool& pressed)
{
    this->m_pressed = pressed;
}
