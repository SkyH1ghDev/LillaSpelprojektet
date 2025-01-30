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
	Sprite(MW::ComPtr<ID3D11Device> device, std::string filepath, int frameCount = 1);
	~Sprite();

	inline MW::ComPtr<ID3D11ShaderResourceView> GetSRV();
	inline DX::XMFLOAT2 GetOrigin();
	RECT GetSourceRectangle(int frameIndex);
	void ResetRectangle();

private:
	int m_frameWidth;
	int m_frameCount = 1;
	DX::XMFLOAT2 m_origin;
	RECT m_sourceRect;
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

