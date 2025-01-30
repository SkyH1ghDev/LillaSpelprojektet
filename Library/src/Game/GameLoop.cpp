#include <directxtk/SpriteBatch.h>
#include <GameLoop.hpp>
#include <SceneManager.hpp>
#include <MouseInput/mouseInput.hpp>

//Setup function handling all initialisation of resources
void GameLoop::Setup(HINSTANCE hInstance, int nCmdShow, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<IDXGISwapChain>& swapChain,
	MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv, D3D11_VIEWPORT &viewport, const UINT &width, const UINT &height, HWND &window)
{
	SetupHelper setup;

	setup.Setup(hInstance, nCmdShow, window, device, immediateContext, swapChain, dsTexture, dsView, rtv, width, height);

	setup.SetViewport(width, height, viewport);
}

//Extension of Main
void GameLoop::Run(HINSTANCE hInstance, int nCmdShow)
{
	MW::ComPtr<ID3D11Device> device;
	MW::ComPtr<ID3D11DeviceContext> immediateContext;
	MW::ComPtr<IDXGISwapChain> swapChain;

	MW::ComPtr<ID3D11Texture2D> dsTexture;
	MW::ComPtr<ID3D11DepthStencilView> dsView;
	MW::ComPtr<ID3D11RenderTargetView> rtv;
	

	HWND window;
	D3D11_VIEWPORT viewport;

	int initWidth = 1280;
	int initHeight = 720;

	Setup(hInstance, nCmdShow, device, immediateContext, swapChain, dsTexture, dsView, rtv, viewport, initWidth, initHeight, window);

	Renderer renderer = Renderer(device);

	AssetManager ass;
	ass.ReadFolder(device, "../Application/Resources");
	
	std::unique_ptr<DX::DX11::SpriteBatch> spriteBatch;
	spriteBatch = std::make_unique<DX::DX11::SpriteBatch>(immediateContext.Get());

	MSG msg = {};

	mouseInput mi(window);

	float clearColour[4] = { 0, 0, 0, 0 };

	//Render- / main application loop
	//May want to change the condition to a bool variable
	while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && msg.message != WM_QUIT)
	{
		mi.update();


		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		immediateContext->RSSetViewports(1, &viewport);
		immediateContext->OMSetRenderTargets(1, rtv.GetAddressOf(), dsView.Get());
		immediateContext->ClearRenderTargetView(rtv.Get(), clearColour);

		spriteBatch->Begin(DX::DX11::SpriteSortMode_Texture, renderer.GetBlendState().Get(), renderer.GetSamplerState().Get(), nullptr, renderer.GetRasterState().Get(), nullptr, DX::XMMatrixIdentity());
		renderer.DrawTexture(spriteBatch, ass.GetSRV("Toe.png").Get(), DX::XMFLOAT2(mi.getMousePositionX(), mi.getMousePositionY()), DX::Colors::White);
		spriteBatch->End();

		swapChain->Present(0, 0);

	}

	DestroyWindow(window);
}
