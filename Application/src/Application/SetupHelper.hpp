#include <Windows.h>
#include <iostream>
#include <d3d11.h>

class SetupHelper
{
public:

	/**
	 *
	 * @param hInstance Instance handle
	 * @param nCmdShow Window display value
	 * @param[OUT] window Window handle
	 * @param[OUT] device DirectX11 device
	 * @param[OUT] immediateContext DirectX11 context
	 * @param[OUT] swapChain DirectX11 swapchain
	 * @param[OUT] dsTexture DirectX11 depth stencil texture
	 * @param[OUT] dsView DirectX11 depth stencil view
	 * @param[OUT] rtv DirectX11 render target view
	 * @return 0 on Success, -1 on Fail
	 */
	bool Setup(const HINSTANCE& hInstance, const int& nCmdShow, HWND &window, ID3D11Device*& device, ID3D11DeviceContext*& immediateContext,
	           IDXGISwapChain*& swapChain, ID3D11Texture2D*& dsTexture, ID3D11DepthStencilView*& dsView, ID3D11RenderTargetView*& rtv);

private:

	/**
	 * Creates the window, we should pass a variable to change the startup size, maybe based on save data
	 *
	 * @param instance Instance handle
	 * @param nCmdShow Window display value
	 * @param[OUT] window Window handle
	 * @return 0 on Success, -1 on Fail
	 */
	bool SetupWindow(const HINSTANCE& instance, const int& nCmdShow, HWND &window);

	/**
	 * Creates a device and context along with a swapchain based on window dimensions
	 *
	 * @param immediateContext DirectX11 context
	 * @param width Window width
	 * @param height Window height
	 * @param window Window handle
	 * @param[OUT] device DirectX11 device
	 * @param[OUT] swapChain DirectX11 swapchain
	 * @return 0 on Success, -1 on Fail
	 */
	bool SetupInterfaces(const ID3D11DeviceContext*& immediateContext, const UINT& width, const UINT& height, const HWND& window, ID3D11Device*& device, IDXGISwapChain*& swapChain);

	/**
	 * Creates a depth stencil view with a texture2d
	 *
	 * @param device DirectX11 device
	 * @param width Window width
	 * @param height Window height
	 * @param[OUT] dsTexture DirectX11 depth stencil texture
	 * @param[OUT] dsView DirectX11 depth stencil view
	 * @return 0 on Success, -1 on Fail
	 */
	bool SetupDepthStencil(const ID3D11Device*& device, const UINT& width, const UINT& height, ID3D11Texture2D*& dsTexture, ID3D11DepthStencilView*& dsView);

	/**
	 *
	 * @param device DirectX11 device
	 * @param swapChain DirectX11 swapchain
	 * @param[OUT] rtv DirectX11 render target view
	 * @return 0 on Success, -1 on Fail
	 */
	bool SetupRenderTargetView(const ID3D11Device*& device, const IDXGISwapChain*& swapChain, ID3D11RenderTargetView*& rtv);

	/**
	 * Sets initial values to the viewport
	 *
	 * @param width Window width
	 * @param height Window height
	 * @param[OUT] viewport DirectX11 Window
	 */
	void SetViewport(const UINT& width, const UINT& height, D3D11_VIEWPORT& viewport);

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};