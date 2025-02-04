#pragma once
#include <gtest/gtest.h>
#include <Renderer.hpp>
#include <Window.hpp>

TEST(Renderer, BlendStateSetup)
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    Window window = Window(hInstance, SW_SHOW, width, height);
    Renderer renderer = Renderer(window.GetWindowHandle());
    
    ASSERT_NE(renderer.GetBlendState().Get(), nullptr);
}

TEST(Renderer, SamplerStateSetup)
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    Window window = Window(hInstance, SW_SHOW, width, height);
    Renderer renderer = Renderer(window.GetWindowHandle());

    ASSERT_NE(renderer.GetSamplerState().Get(), nullptr);
}

TEST(Renderer, RasterStateSetup)
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    Window window = Window(hInstance, SW_SHOW, width, height);
    Renderer renderer = Renderer(window.GetWindowHandle());

    ASSERT_NE(renderer.GetRasterState().Get(), nullptr);
}

TEST(Renderer, PipelineDevice)
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    Window window = Window(hInstance, SW_SHOW, width, height);
    Renderer renderer = Renderer(window.GetWindowHandle());

    ASSERT_NE(renderer.GetDevice().Get(), nullptr);
}

TEST(Renderer, PipelineDeviceContext)
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    Window window = Window(hInstance, SW_SHOW, width, height);
    Renderer renderer = Renderer(window.GetWindowHandle());

    ASSERT_NE(renderer.GetContext().Get(), nullptr);
}

TEST(Renderer, PipelineRendertarget)
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    Window window = Window(hInstance, SW_SHOW, width, height);
    Renderer renderer = Renderer(window.GetWindowHandle());

    ASSERT_NE(renderer.GetRTV().Get(), nullptr);
}

TEST(Renderer, PipelineSwapchain)
{
    HINSTANCE hInstance;
    UINT width = 1920;
    UINT height = 1080;

    Window window = Window(hInstance, SW_SHOW, width, height);
    Renderer renderer = Renderer(window.GetWindowHandle());

    ASSERT_NE(renderer.GetSwapChain().Get(), nullptr);
}
