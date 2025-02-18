#pragma once

#include <d3d11.h>
#include <string>
#include <directxtk/SpriteBatch.h>
#include <wrl/client.h>
#include <APNGLoader/uc_apng_loader.h>


namespace MW = Microsoft::WRL;
namespace DX = DirectX;

//Class for wrapping texture resources
class Sprite
{
public:
	Sprite() = default;
	Sprite(const MW::ComPtr<ID3D11Device>& device);
	Sprite(const MW::ComPtr<ID3D11Device>& device, const std::string& filepath);
	Sprite(const MW::ComPtr<ID3D11Device>& device, const uc::apng::frame& frame);
	Sprite(const Sprite& other);
	Sprite& operator=(const Sprite& other);
	virtual ~Sprite() = default;

	inline MW::ComPtr<ID3D11ShaderResourceView> GetSRV();
	inline DX::XMFLOAT2 GetOrigin();
	std::shared_ptr<RECT> GetSourceRectangle();

protected:
	DX::XMFLOAT2 m_origin;
	std::shared_ptr<RECT> m_sourceRect;
	MW::ComPtr<ID3D11ShaderResourceView> m_srv;

};

inline MW::ComPtr<ID3D11ShaderResourceView> Sprite::GetSRV()
{
	return m_srv;
}

inline DX::XMFLOAT2 Sprite::GetOrigin()
{
	return m_origin;
}

inline std::shared_ptr<RECT> Sprite::GetSourceRectangle()
{
	return m_sourceRect;
}


