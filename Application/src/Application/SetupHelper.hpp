#include <Windows.h>
#include <iostream>
#include <d3d11.h>

class SetupHelper
{
public:

	/**
	 * Creates the window, we should pass a variable to change the startup size, maybe based on save data
	 *
	 * @param instance Instance handle
	 * @param nCmdShow Window display value
	 * @param[OUT] window Window handle
	 * @return 0 on Success, -1 on Fail
	 */
	bool SetupWindow(HINSTANCE instance, int nCmdShow, HWND &window);

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
	bool SetupInterfaces(ID3D11DeviceContext*& immediateContext, UINT width, UINT height, HWND &window, ID3D11Device*& device, IDXGISwapChain*& swapChain);

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
	bool SetupDepthStencil(ID3D11Device* device, UINT width, UINT height, ID3D11Texture2D*& dsTexture, ID3D11DepthStencilView*& dsView);

	/**
	 * 
	 * @param device DirectX11 device
	 * @param swapChain DirectX11 swapchain
	 * @param[OUT] rtv DirectX11 render target view
	 * @return 0 on Success, -1 on Fail
	 */
	bool SetupRenderTargetView(ID3D11Device* device, IDXGISwapChain* swapChain, ID3D11RenderTargetView*& rtv);

	/**
	 * Sets initial values to the viewport
	 *
	 * @param width Window width
	 * @param height Window height
	 * @param[OUT] viewport DirectX11 Window
	 */
	void SetViewport(UINT width, UINT height, D3D11_VIEWPORT& viewport);

	/**
	 *
	 * @param hInstance Instance handle
	 * @param nCmdShow Window display value
	 * @param window Window handle
	 * @param device DirectX11 device
	 * @param immediateContext DirectX11 context
	 * @param swapChain DirectX11 swapchain
	 * @param dsTexture DirectX11 depth stencil texture
	 * @param dsView DirectX11 depth stencil view
	 * @param rtv DirectX11 render target view
	 * @return 0 on Success, -1 on Fail
	 */
	bool Setup(HINSTANCE hInstance, int nCmdShow, HWND &window, ID3D11Device*& device, ID3D11DeviceContext*& immediateContext,
	           IDXGISwapChain*& swapChain, ID3D11Texture2D*& dsTexture, ID3D11DepthStencilView*& dsView, ID3D11RenderTargetView*& rtv);

private:

	/**
	 * Function to display order of operation, mainly for visibility
	 *
	 * @param hWnd Window handle
	 * @param message Windows message
	 * @param wParam Word (16-bit) parameter
	 * @param lParam Long (32-bit) parameter
	 * @return Windows message result
	 */
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};