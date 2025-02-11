#pragma once

#include <windows.h>
#include <d3d11.h>
#include <wrl/client.h>

namespace MW = Microsoft::WRL;

class ImGuiNew
{
public:
    ImGuiNew();
    ~ImGuiNew();
    ImGuiNew(const ImGuiNew& other);
    ImGuiNew& operator=(const ImGuiNew& other);
    ImGuiNew(ImGuiNew&& other) noexcept;
    ImGuiNew& operator=(ImGuiNew&& other) noexcept;

    static void Initialize(const HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& context);
    static void Start();
    static void Run();
    static void End();

};
