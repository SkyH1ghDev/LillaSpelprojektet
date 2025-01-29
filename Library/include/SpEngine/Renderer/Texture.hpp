#include <d3d11.h>
#include <string>
#include <directxtk/SpriteBatch.h>
#include <wrl/client.h>
#include <iostream>

namespace MW = Microsoft::WRL;
namespace DX = DirectX;

//Class for wrapping texture resources
class ShaderResourceTexture
{
public:
	ShaderResourceTexture() = default;
	ShaderResourceTexture(MW::ComPtr<ID3D11Device> device, std::string filepath);
	~ShaderResourceTexture();

	inline MW::ComPtr<ID3D11ShaderResourceView> GetSRV() 
	{
		return this->srv;
	}

private:
	int m_width = 0;
	int m_height = 0;
	MW::ComPtr<RECT> m_rect;
	MW::ComPtr<ID3D11ShaderResourceView> m_srv;
};

