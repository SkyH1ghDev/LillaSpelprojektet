#pragma once
#include <gtest/gtest.h>
#include <Window.hpp>
#include "AssetManager.hpp"
#include "SetupHelper.hpp"

TEST(AssetManagement, HashMap)
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    MW::ComPtr<ID3D11Device> device;
    MW::ComPtr<ID3D11DeviceContext> deviceContext;
    MW::ComPtr<IDXGISwapChain> swapChain;
    MW::ComPtr<ID3D11Texture2D> texture;
    MW::ComPtr<ID3D11DepthStencilView> dsView;
    MW::ComPtr<ID3D11RenderTargetView> rtv;

    Window window = Window(hInstance, SW_SHOW, width, height);

    SetupHelper setup;
    setup.Setup(window.GetWindowHandle(), device, deviceContext, swapChain, texture, dsView, rtv, width, height);

	AssetManager as;
	as.ReadFolder(device, "../Tests/src/Resources");
    std::string filename = "testTile.png";

    ASSERT_NE(as.GetSprite(filename).GetSRV().Get(), nullptr);
}

TEST(Sprites, CopyAssignment) 
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    MW::ComPtr<ID3D11Device> device;
    MW::ComPtr<ID3D11DeviceContext> deviceContext;
    MW::ComPtr<IDXGISwapChain> swapChain;
    MW::ComPtr<ID3D11Texture2D> texture;
    MW::ComPtr<ID3D11DepthStencilView> dsView;
    MW::ComPtr<ID3D11RenderTargetView> rtv;

    Window window = Window(hInstance, SW_SHOW, width, height);

    SetupHelper setup;
    setup.Setup(window.GetWindowHandle(), device, deviceContext, swapChain, texture, dsView, rtv, width, height);

    Sprite srt1(device, "../Tests/src/Resources/testTile.png");
    Sprite srt2 = srt1;

    ASSERT_EQ(srt1.GetSRV().Get(), srt2.GetSRV().Get());
}

TEST(Sprites, Copy)
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    MW::ComPtr<ID3D11Device> device;
    MW::ComPtr<ID3D11DeviceContext> deviceContext;
    MW::ComPtr<IDXGISwapChain> swapChain;
    MW::ComPtr<ID3D11Texture2D> texture;
    MW::ComPtr<ID3D11DepthStencilView> dsView;
    MW::ComPtr<ID3D11RenderTargetView> rtv;

    Window window = Window(hInstance, SW_SHOW, width, height);

    SetupHelper setup;
    setup.Setup(window.GetWindowHandle(), device, deviceContext, swapChain, texture, dsView, rtv, width, height);

    Sprite srt1(device, "../Tests/src/Resources/testTile.png");
    Sprite srt2(srt1);

    ASSERT_EQ(srt1.GetSRV().Get(), srt2.GetSRV().Get());
}
