#pragma once
#include <gtest/gtest.h>
#include "AssetManager.hpp"
#include "SetupHelper.hpp"

TEST(AssetManagement, HashMap)
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

	AssetManager as;
	as.ReadFolder(device, "../Tests/src/Resources");
    std::string filename = "testTile.png";

    ASSERT_NE(as.GetSprite(filename).GetSRV().Get(), nullptr);
}

TEST(Sprites, CopyAssignment) 
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

    Sprite srt1(device, "../Tests/src/Resources/testTile.png");
    Sprite srt2 = srt1;

    ASSERT_EQ(srt1.GetSRV().Get(), srt2.GetSRV().Get());
}

TEST(Sprites, Copy)
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

    Sprite srt1(device, "../Tests/src/Resources/testTile.png");
    Sprite srt2(srt1);

    ASSERT_EQ(srt1.GetSRV().Get(), srt2.GetSRV().Get());
}