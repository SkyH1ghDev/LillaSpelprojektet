#include "SetupHelper.hpp"
#include <iostream>

bool SetupHelper::SetupInterfaces(MW::ComPtr<ID3D11DeviceContext>& immediateContext, const UINT& width, const UINT& height, const HWND& window, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<IDXGISwapChain>& swapChain)
{
	UINT flags = 0;
	if (_DEBUG)
		flags = D3D11_CREATE_DEVICE_DEBUG;

	D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };

	DXGI_SWAP_CHAIN_DESC swapChainDesc = {};

	ID3D11DeviceContext* immediateContextCpy;
	ID3D11Device* deviceCpy;
	IDXGISwapChain* swapChainCpy;

	swapChainDesc.BufferDesc.Width = width;
	swapChainDesc.BufferDesc.Height = height;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	// Default
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;

	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = window;
	swapChainDesc.Windowed = true;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = 0;

	HRESULT hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, featureLevels, 1, D3D11_SDK_VERSION, &swapChainDesc, &swapChainCpy, &deviceCpy, nullptr, &immediateContextCpy);

	immediateContext.Attach(immediateContextCpy);
	device.Attach(deviceCpy);
	swapChain.Attach(swapChainCpy);

	return !(FAILED(hr));
}

bool SetupHelper::SetupRenderTargetView(MW::ComPtr<ID3D11Device>& device, MW::ComPtr<IDXGISwapChain>& swapChain, MW::ComPtr<ID3D11RenderTargetView>& rtv)
{
	// get the address of the back buffer

	ID3D11RenderTargetView* rtvCpy;
	ID3D11Texture2D* backBuffer = nullptr;
	if (FAILED(swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer))))
	{
		std::cerr << "Failed to get back buffer! \n";
		return false;
	}

	// use the back buffer address to create the render target
	// null as description to base it on the backbuffers values
	HRESULT hr = device->CreateRenderTargetView(backBuffer, NULL, &rtvCpy);
	backBuffer->Release();

	rtv.Attach(rtvCpy);

	return !(FAILED(hr));
}

bool SetupHelper::SetupDepthStencil(MW::ComPtr<ID3D11Device>& device, const UINT& width, const UINT& height, MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView)
{
	ID3D11Texture2D* dsTextureCpy;
	ID3D11DepthStencilView* dsViewCpy;

	D3D11_TEXTURE2D_DESC textureDesc;
	textureDesc.Width = width;
	textureDesc.Height = height;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	textureDesc.SampleDesc.Count = 1;
	textureDesc.SampleDesc.Quality = 0;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	textureDesc.CPUAccessFlags = 0;
	textureDesc.MiscFlags = 0;
	if (FAILED(device->CreateTexture2D(&textureDesc, nullptr, &dsTextureCpy)))
	{
		std::cerr << "Failed to create depth stencil texture! \n";
		return false;
	}

	HRESULT hr = device->CreateDepthStencilView(dsTextureCpy, 0, &dsViewCpy);

	dsTexture.Attach(dsTextureCpy);

	dsView.Attach(dsViewCpy);

	return !(FAILED(hr));
}

void SetupHelper::SetViewport(const UINT& width, const UINT& height, D3D11_VIEWPORT& viewport)
{
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = FLOAT(width);
	viewport.Height = FLOAT(height);
	viewport.MinDepth = 0;
	viewport.MaxDepth = 1;
}

bool SetupHelper::Setup(HWND &window, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext,
                        MW::ComPtr<IDXGISwapChain>& swapChain, MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv, const UINT &width, const UINT &height)
{

	if (!SetupInterfaces(immediateContext, width, height, window, device, swapChain))
	{
		throw std::runtime_error("Failed to setup Interfaces");
	}

	if (!SetupDepthStencil(device, width, height, dsTexture, dsView))
	{
		throw std::runtime_error("Failed to setup Depth Stencil View");
	}

	if (!SetupRenderTargetView(device, swapChain, rtv))
	{
		throw std::runtime_error("Failed to setup Render Target View");
	}

	return true;
}
