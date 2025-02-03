#include <d3d11.h>
#include <string>
#include <directxtk/SpriteBatch.h>
#include <wrl/client.h>
#include <iostream>

namespace MW = Microsoft::WRL;
namespace DX = DirectX;

//Class for wrapping texture resources
class Sprite
{
public:
	Sprite() = default;
	Sprite(MW::ComPtr<ID3D11Device> device, std::string filepath);
	Sprite(const Sprite& other);
	Sprite& operator=(const Sprite& other);
	~Sprite() = default;

	inline MW::ComPtr<ID3D11ShaderResourceView> GetSRV();
	inline DX::XMFLOAT2 GetOrigin();
	std::shared_ptr<RECT> GetSourceRectangle();

private:
	DX::XMFLOAT2 m_origin;
	std::shared_ptr<RECT> m_sourceRect;
	MW::ComPtr<ID3D11ShaderResourceView> m_srv;
};

inline MW::ComPtr<ID3D11ShaderResourceView> Sprite::GetSRV()
{
	return this->m_srv;
}

inline DX::XMFLOAT2 Sprite::GetOrigin()
{
	return this->m_origin;
}

inline std::shared_ptr<RECT> Sprite::GetSourceRectangle()
{
	return this->m_sourceRect;
}


