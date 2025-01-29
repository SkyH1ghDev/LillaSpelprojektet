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
	void DrawTexture(std::unique_ptr<DX::SpriteBatch> &spriteBatch, DX::XMFLOAT2 position);

	inline MW::ComPtr<ID3D11ShaderResourceView> GetSRV() 
	{
		return this->srv;
	}

private:
	int width = 0;
	int height = 0;
	MW::ComPtr<ID3D11ShaderResourceView> srv;
};

