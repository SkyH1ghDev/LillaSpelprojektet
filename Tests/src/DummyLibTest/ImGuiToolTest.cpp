#pragma once
#include <gtest/gtest.h>
#include <SpEngine/ImGui/ImGuiTool.hpp>
#include <Mouse.hpp>

class ImGuiToolTest : public ::testing::Test {
protected:
    ImGuiTool imGui;
    MW::ComPtr<ID3D11Device> device;
    MW::ComPtr<ID3D11DeviceContext> immediateContext;
    HWND window;

    void SetUp() override {
        window = reinterpret_cast<HWND>(1);
        D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0,
            D3D11_SDK_VERSION, &device, nullptr, &immediateContext);

        if (ImGui::GetCurrentContext() == nullptr) {
            ImGuiTool imGui(window, device, immediateContext);
        }
    }

    void TearDown() override {
        if (ImGui::GetCurrentContext() != nullptr) {
            imGui.Shutdown();
        }
    }
};

TEST(ImGuiTool, TestInitialize)
{
    HWND window = reinterpret_cast<HWND>(1);
    MW::ComPtr<ID3D11Device> device;
    MW::ComPtr<ID3D11DeviceContext> immediateContext;
    D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION, &device, nullptr, &immediateContext);

    ImGuiTool imGui;
    imGui = ImGuiTool(window, device, immediateContext);

    ASSERT_NE(ImGui::GetCurrentContext(), nullptr);
}
TEST_F(ImGuiToolTest, TestStart) {
    imGui.Start();
    ASSERT_NE(ImGui::GetCurrentContext(), nullptr);
}

TEST_F(ImGuiToolTest, TestEnd) {
    imGui.Start();
    imGui.End();
    ASSERT_NE(ImGui::GetDrawData(), nullptr);
}

TEST_F(ImGuiToolTest, TestShutdown) {
    imGui.Shutdown();
    ASSERT_EQ(ImGui::GetCurrentContext(), nullptr);
}



