#pragma once

#include <windows.h>
#include <d3d11.h>
#include <wrl/client.h>

namespace MW = Microsoft::WRL;

class ImGuiTool
{
public:
    ImGuiTool() = default;
    ~ImGuiTool() = default;
    ImGuiTool(const ImGuiTool& other) = default;
    ImGuiTool& operator=(const ImGuiTool& other) = default;
    ImGuiTool(ImGuiTool&& other) noexcept = default;
    ImGuiTool& operator=(ImGuiTool&& other) noexcept = default;

    static void Initialize(const HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& context);
    static void Start();
    static void Run();
    static void End();
    static void Shutdown();

private:
    static void AssetManagerTab();
    static void SceneManagerTab();
    static void StatisticsTab();
    static void KeyBindTab();

};
