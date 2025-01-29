#pragma once
#include <gtest/gtest.h>
#include <Texture.hpp>
#include <SetupHelper.hpp>
#include <mouseInput.hpp>

TEST(Mouse, GetPosition) 
{
    UINT height = 1080;
    UINT width = 1920;

    HINSTANCE hInstance;
    HWND window;
    MW::ComPtr<ID3D11Device> device;
    MW::ComPtr<ID3D11DeviceContext> deviceContext;
    MW::ComPtr<IDXGISwapChain> swapChain;
    MW::ComPtr<ID3D11Texture2D> texture;
    MW::ComPtr<ID3D11DepthStencilView> dsView;
    MW::ComPtr<ID3D11RenderTargetView> rtv;

    SetupHelper setup;
    setup.Setup(hInstance, SW_SHOW, window, device, deviceContext, swapChain, texture, dsView, rtv, width, height);
    POINT p;
    GetCursorPos(&p);
    mouseInput mouse(window);
    ASSERT_EQ(p.x, mouse.getMousePositionX());

    ASSERT_EQ(p.y, mouse.getMousePositionY());
}

TEST(Mouse, setupMouse)
{
    UINT height = 1080;
    UINT width = 1920;

    HINSTANCE hInstance;
    HWND window;
    MW::ComPtr<ID3D11Device> device;
    MW::ComPtr<ID3D11DeviceContext> deviceContext;
    MW::ComPtr<IDXGISwapChain> swapChain;
    MW::ComPtr<ID3D11Texture2D> texture;
    MW::ComPtr<ID3D11DepthStencilView> dsView;
    MW::ComPtr<ID3D11RenderTargetView> rtv;

    SetupHelper setup;
    setup.Setup(hInstance, SW_SHOW, window, device, deviceContext, swapChain, texture, dsView, rtv, width, height);

    mouseInput mouse(window);
    
    ASSERT_NE(device.Get(), nullptr);
}

TEST(Mouse, anybutton)
{
    UINT height = 1080;
    UINT width = 1920;

    HINSTANCE hInstance;
    HWND window;
    MW::ComPtr<ID3D11Device> device;
    MW::ComPtr<ID3D11DeviceContext> deviceContext;
    MW::ComPtr<IDXGISwapChain> swapChain;
    MW::ComPtr<ID3D11Texture2D> texture;
    MW::ComPtr<ID3D11DepthStencilView> dsView;
    MW::ComPtr<ID3D11RenderTargetView> rtv;

    SetupHelper setup;
    setup.Setup(hInstance, SW_SHOW, window, device, deviceContext, swapChain, texture, dsView, rtv, width, height);

    mouseInput mouse(window);
    int testvalue = mouse.Anybutton();
    ASSERT_EQ(testvalue, -1);
}

TEST(Mouse, pressbutton)
{
    UINT height = 1080;
    UINT width = 1920;

    HINSTANCE hInstance;
    HWND window;
    MW::ComPtr<ID3D11Device> device;
    MW::ComPtr<ID3D11DeviceContext> deviceContext;
    MW::ComPtr<IDXGISwapChain> swapChain;
    MW::ComPtr<ID3D11Texture2D> texture;
    MW::ComPtr<ID3D11DepthStencilView> dsView;
    MW::ComPtr<ID3D11RenderTargetView> rtv;

    SetupHelper setup;
    setup.Setup(hInstance, SW_SHOW, window, device, deviceContext, swapChain, texture, dsView, rtv, width, height);

    mouseInput mouse(window);
    bool testvalue = mouse.IsButtonPressed(0);
    ASSERT_EQ(testvalue, false);
}

