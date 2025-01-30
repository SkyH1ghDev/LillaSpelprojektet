#pragma once
#include <gtest/gtest.h>
#include "SetupHelper.hpp"

TEST(DirectX11, DeviceSetup)
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

    ASSERT_NE(device.Get(), nullptr);
}

TEST(DirectX11, ContextSetup)
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

    ASSERT_NE(deviceContext.Get(), nullptr);
}

TEST(DirectX11, SwapChainSetup)
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

    ASSERT_NE(swapChain.Get(), nullptr);
}

TEST(DirectX11, dsTextureSetup)
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

    ASSERT_NE(texture.Get(), nullptr);
}

TEST(DirectX11, dsViewSetup)
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

    ASSERT_NE(dsView.Get(), nullptr);
}

TEST(DirectX11, rtvSetup)
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

    ASSERT_NE(rtv.Get(), nullptr);
}

TEST(Viewport, ViewportSetup)
{
    const UINT height = 1080;
    const UINT width = 1920;

    D3D11_VIEWPORT viewport;
    SetupHelper setup;
    setup.SetViewport(width, height, viewport);

    int testValue = viewport.Height * viewport.Width;

    ASSERT_EQ(testValue, height * width);
}
