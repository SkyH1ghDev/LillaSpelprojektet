#pragma once
#include "Texture.hpp"
#include "SetupHelper.hpp"
#include <SpriteBatch.h>

namespace DX = DirectX;

namespace DX = DirectX;

class Application
{
public:
    void Run(HINSTANCE hInstance, int nCmdShow);

private:

    void Setup(HINSTANCE hInstance, int nCmdShow, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<IDXGISwapChain>& swapChain, 
        MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv, D3D11_VIEWPORT &viewport, const UINT &width, const UINT &height);
};
