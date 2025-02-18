#pragma once

#include <string>

class ImGuiKeyWrapper {
public:
    ImGuiKeyWrapper() = default;
    ImGuiKeyWrapper(const std::string& keyName, const int& vKey);
    ~ImGuiKeyWrapper() = default;
    ImGuiKeyWrapper(const ImGuiKeyWrapper& other) = default;
    ImGuiKeyWrapper& operator=(const ImGuiKeyWrapper& other) = default;
    ImGuiKeyWrapper(ImGuiKeyWrapper&& other) noexcept = default;
    ImGuiKeyWrapper& operator=(ImGuiKeyWrapper&& other) noexcept = default;

    std::string GetString() const;
    int GetVKey() const;

private:
    std::string m_keyString;
    int m_vKey;
};

// Constructors

inline ImGuiKeyWrapper::ImGuiKeyWrapper(const std::string& keyName, const int& vKey)
{
    this->m_keyString = keyName;
    this->m_vKey = vKey;
}

// Getters & Setters

inline std::string ImGuiKeyWrapper::GetString() const
{
    return this->m_keyString;
}

inline int ImGuiKeyWrapper::GetVKey() const
{
    return this->m_vKey;
}