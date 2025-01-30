//#pragma once
//#include <gtest/gtest.h>
//#include <SpEngine/ImGui/ImGuiTool.hpp>
//#include <Mouse.hpp>
//#include <imgui/imgui.h>
//#include <imgui/imgui_impl_win32.h>
//#include <imgui/imgui_impl_dx11.h>
//
//TEST(ImGuiTool, TestInitialize) 
//{
//    HWND window = reinterpret_cast<HWND>(1);
//    MW::ComPtr<ID3D11Device> device;
//    MW::ComPtr<ID3D11DeviceContext> immediateContext;
//
//    ImGuiTool imGui;
//    imGui = ImGuiTool(window, device, immediateContext);
//
//    ASSERT_NE(ImGui::GetCurrentContext(), nullptr);
//}
//
//TEST(ImGuiTool, TestStart) 
//{
//    HWND window = reinterpret_cast<HWND>(1);
//    MW::ComPtr<ID3D11Device> device;
//    MW::ComPtr<ID3D11DeviceContext> immediateContext;
//    D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &device, nullptr, &immediateContext);
//
//    ImGuiTool imGui;
//    imGui = ImGuiTool(window, device, immediateContext);
//    imGui.Start();
//
//    EXPECT_TRUE(ImGui::GetCurrentContext());
//}
//
//TEST(ImGuiTool, TestEnd) 
//{
//    HWND window = reinterpret_cast<HWND>(1);
//
//    MW::ComPtr<ID3D11Device> device;
//    MW::ComPtr<ID3D11DeviceContext> immediateContext;
//    D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &device, nullptr, &immediateContext);
//
//    ImGuiTool imGui;
//    imGui = ImGuiTool(window, device, immediateContext);
//
//    imGui.Start();
//    imGui.End();
//
//    EXPECT_TRUE(ImGui::GetDrawData() != nullptr);
//}
//
//TEST(ImGuiTool, TestShutdown) 
//{
//    HWND window = reinterpret_cast<HWND>(1);
//    MW::ComPtr<ID3D11Device> device;
//    MW::ComPtr<ID3D11DeviceContext> immediateContext;
//    D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &device, nullptr, &immediateContext);
//
//    ImGuiTool imGui;
//    imGui = ImGuiTool(window, device, immediateContext);
//
//    ASSERT_NE(ImGui::GetCurrentContext(), nullptr);
//
//    imGui.Shutdown();
//    ASSERT_EQ(ImGui::GetCurrentContext(), nullptr);
//}
//
//TEST(ImGuiTool, TestRun) {
//    HWND window = reinterpret_cast<HWND>(1);
//
//    MW::ComPtr<ID3D11Device> device;
//    MW::ComPtr<ID3D11DeviceContext> immediateContext;
//    MW::ComPtr<ID3D11RenderTargetView> rtv;
//
//    D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &device, nullptr, &immediateContext);
//
//    device->CreateRenderTargetView(nullptr, nullptr, &rtv);
//
//    ImGuiTool imGui;
//    imGui = ImGuiTool(window, device, immediateContext);
//
//    Mouse mouse(window);
//    mouse.IsButtonPressed(true);
//
//
//    imGui.Run(immediateContext, rtv, mouse);
//
//    ImGuiIO& io = ImGui::GetIO();
//    ASSERT_TRUE(io.MouseDown[0]);
//    ASSERT_TRUE(ImGui::GetCurrentContext() != nullptr);
//
//}
