#pragma once

#include "ISprite.hpp"

#include <directxtk/SpriteBatch.h>
#include <wrl/client.h>
#include <APNGLoader/uc_apng_loader.h>


namespace MW = Microsoft::WRL;
namespace DX = DirectX;
namespace APNG = uc::apng;

//Class for wrapping texture resources
class StaticSprite : public ISprite
{
public:
	StaticSprite() = default;
	~StaticSprite() override = default;
	StaticSprite(const MW::ComPtr<ID3D11Device>& device);
	StaticSprite(const MW::ComPtr<ID3D11Device>& device, const std::string& filepath);
	StaticSprite(const MW::ComPtr<ID3D11Device>& device, const APNG::frame& frame);
	StaticSprite(const StaticSprite& other) = default;
	StaticSprite& operator=(const StaticSprite& other) = default;
	StaticSprite(StaticSprite&& other) = default;
	StaticSprite& operator=(StaticSprite&& other) = default;
	
	MW::ComPtr<ID3D11ShaderResourceView> GetSRV() const;
	DX::XMFLOAT2 GetOrigin() const;
	std::shared_ptr<RECT> GetSourceRectangle() const;

private:
	DX::XMFLOAT2 m_origin;
	std::shared_ptr<RECT> m_sourceRect;
	MW::ComPtr<ID3D11ShaderResourceView> m_srv;
	
};

inline MW::ComPtr<ID3D11ShaderResourceView> StaticSprite::GetSRV() const
{
	return m_srv;
}

inline DX::XMFLOAT2 StaticSprite::GetOrigin() const
{
	return m_origin;
}

inline std::shared_ptr<RECT> StaticSprite::GetSourceRectangle() const
{
	return m_sourceRect;
}

