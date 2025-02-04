#pragma once
#include "Game.hpp"

#include <SpEngine/Dev/ImGui/ImGuiTool.hpp>
#include <SpEngine/Renderer/Renderer.hpp>
#include <SpEngine/Renderer/Window.hpp>

#include <directxtk/SpriteBatch.h>

namespace DX = DirectX;

class GameLoop
{
public:
    /**
     * Starts and runs the game loop
     *
     * @param[In] hInstance Window instance handle
     * @param[In] nCmdShow Window show state
     */
    void Run(HINSTANCE hInstance, int nCmdShow);

private:
    /**
     * Sets up the necessities for renderer
     *
     * @param[In] hInstance Window instance handle
     * @param[In] nCmdShow Window show state
     * @param[Out] device DirectX11 Device
     * @param[Out] immediateContext DirectX11 DeviceContext
     * @param[Out] swapChain DirectX11 SwapChain
     * @param[Out] dsTexture DirectX11 DepthStencilTexture
     * @param[Out] dsView DirectX11 DepthStencilView
     * @param[Out] rtv DirectX11 RenderTargetView
     * @param[Out] viewport DirectX11 Viewport
     * @param[In] width Window width
     * @param[In] height Window height
     * @param[Out] window Window handle
     */
    void Setup(HINSTANCE hInstance, int nCmdShow, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<IDXGISwapChain>& swapChain,
               MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv, D3D11_VIEWPORT &viewport, const UINT &width,
               const UINT &height, HWND &window);

    /**
     * Sets up the necessities for imGui
     *
     * @param[In] device DirectX11 Device
     * @param[In] immediateContext DirectX11 DeviceContext
     * @param[In] window Window handle
     */
    void SetupImGui(MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, HWND& window);

private:
    SetupHelper m_setup;
    ImGuiTool m_imGui;
    Game m_game;
};

