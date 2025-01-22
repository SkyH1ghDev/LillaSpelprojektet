#include <Windows.h>
#include <iostream>
#include <d3d11.h>

class SetupHelper
{
public:
	bool SetupWindow(HINSTANCE instance, int nCmdShow, HWND &window);
	bool SetupInterfaces(ID3D11Device*& device, ID3D11DeviceContext*& immediateContext, IDXGISwapChain*& swapChain, UINT width, UINT height, HWND &window);
	bool SetupDepthStencil(ID3D11Device* device, UINT width, UINT height, ID3D11Texture2D*& dsTexture, ID3D11DepthStencilView*& dsView);
	bool SetupRenderTargetView(ID3D11Device* device, IDXGISwapChain* swapChain, ID3D11RenderTargetView*& rtv);
	void SetViewport(D3D11_VIEWPORT& viewport, UINT width, UINT height);
	bool Setup(HINSTANCE hIntance, int nCmdShow, HWND &window, ID3D11Device*& device, ID3D11DeviceContext*& immediateContext, 
		IDXGISwapChain*& swapChain, ID3D11Texture2D*& dsTexture, ID3D11DepthStencilView*& dsView, ID3D11RenderTargetView*& rtv);

private:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};