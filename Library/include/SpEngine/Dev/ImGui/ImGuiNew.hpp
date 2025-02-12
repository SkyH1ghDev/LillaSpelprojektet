#pragma once

#include <windows.h>
#include <d3d11.h>
#include <wrl/client.h>

namespace MW = Microsoft::WRL;

class ImGuiNew
{
public:
    ImGuiNew() = default;
    ~ImGuiNew();
    ImGuiNew(const ImGuiNew& other) = default;
    ImGuiNew& operator=(const ImGuiNew& other) = default;
    ImGuiNew(ImGuiNew&& other) noexcept = default;
    ImGuiNew& operator=(ImGuiNew&& other) noexcept = default;

    static void Initialize(const HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& context);
    static void Start();
    static void Run();
    static void End();
    static void Shutdown();

};
