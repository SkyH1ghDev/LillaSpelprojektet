#include "Application.hpp"
#include <SpriteBatch.h>

//Setup function handling all initialisation of resources
void Application::Setup(HINSTANCE hInstance, int nCmdShow, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, 
	MW::ComPtr<IDXGISwapChain>& swapChain, MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv)
{
	SetupHelper setup;
	D3D11_VIEWPORT viewport;
	HWND window;

	setup.Setup(hInstance, nCmdShow, window, device, immediateContext, swapChain, dsTexture, dsView, rtv);

	setup.SetViewport(720, 560, viewport);
}

//Extension of Main
void Application::Run(HINSTANCE hInstance, int nCmdShow)
{
	MW::ComPtr<ID3D11Device> device;
	MW::ComPtr<ID3D11DeviceContext> immediateContext;
	MW::ComPtr<IDXGISwapChain> swapChain;

	MW::ComPtr<ID3D11Texture2D> dsTexture;
	MW::ComPtr<ID3D11DepthStencilView> dsView;
	MW::ComPtr<ID3D11RenderTargetView> rtv;

	Setup(hInstance, nCmdShow, device, immediateContext, swapChain, dsTexture, dsView, rtv);

	ID3D11DeviceContext* deviceContext = immediateContext.Get();

	std::unique_ptr<DX::DX11::SpriteBatch> spriteBatch;
	spriteBatch = std::make_unique<DX::DX11::SpriteBatch>(deviceContext);

	MSG msg = {};

	ShaderResourceTexture toe(device.Get(), "../Application/Resources/Toe.png");

	//Render- / main application loop
	//May want to change the condition to a bool variable
	while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		spriteBatch->Begin();
		toe.DrawTexture(spriteBatch, DX::XMFLOAT2(100.0f, 100.0f));
		spriteBatch->End();

		swapChain->Present(0, 0);
	}

}
