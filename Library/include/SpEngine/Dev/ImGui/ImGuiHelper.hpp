#pragma once
#include "ImGuiKeyWrapper.hpp"

#include <ImGui/imgui.h>
#include <unordered_map>

class ImGuiHelper
{
public:
    ImGuiHelper() = delete;
    ~ImGuiHelper() = delete;
    ImGuiHelper(const ImGuiHelper& other) = delete;
    ImGuiHelper& operator=(const ImGuiHelper& other) = delete;
    ImGuiHelper(ImGuiHelper&& other) noexcept = delete;
    ImGuiHelper& operator=(ImGuiHelper&& other) noexcept = delete;

    static std::unordered_map<int, ImGuiKeyWrapper> GetBindableKeys();
    static ImGuiKeyWrapper GetKey(const ImGuiKey& imGuiKey);

private:
    
    static std::unordered_map<int, ImGuiKeyWrapper> m_validKeys;
};

inline std::unordered_map<int, ImGuiKeyWrapper> ImGuiHelper::GetBindableKeys()
{
    return m_validKeys;
}

inline ImGuiKeyWrapper ImGuiHelper::GetKey(const ImGuiKey& imGuiKey)
{ 
    return m_validKeys[imGuiKey];
}