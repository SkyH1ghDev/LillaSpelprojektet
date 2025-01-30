#pragma once
#include <gtest/gtest.h>
#include <Renderer.hpp>
#include "SetupHelper.hpp"

TEST(Renderer, BlendStateSetup) 
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

    Renderer renderer = Renderer(device);

    ASSERT_NE(renderer.GetBlendState().Get(), nullptr);
}

TEST(Renderer, SamplerStateSetup)
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

    Renderer renderer = Renderer(device);

    ASSERT_NE(renderer.GetSamplerState().Get(), nullptr);
}

TEST(Renderer, RasterStateSetup)
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

    Renderer renderer = Renderer(device);

    ASSERT_NE(renderer.GetRasterState().Get(), nullptr);
}
