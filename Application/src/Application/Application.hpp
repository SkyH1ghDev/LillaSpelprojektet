#pragma once
#include "SetupHelper.hpp"

class Application
{
public:
    void Run(HINSTANCE hInstance, int nCmdShow);

private:

    void Setup(HINSTANCE, int nCmdShow, ID3D11Device*& device, ID3D11DeviceContext*& immediateContext,
        IDXGISwapChain*& swapChain, ID3D11Texture2D*& dsTexture, ID3D11DepthStencilView*& dsView, ID3D11RenderTargetView*& rtv);
};
