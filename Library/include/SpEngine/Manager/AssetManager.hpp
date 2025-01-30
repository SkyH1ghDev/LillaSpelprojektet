#pragma once
#include <filesystem>
#include <map>
#include <SpEngine/Renderer/Texture.hpp>

namespace FS = std::filesystem;
namespace MW = Microsoft::WRL;
//namespace DX = DirectX;

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	bool ReadFolder(MW::ComPtr<ID3D11Device>& device, std::string path);
	inline MW::ComPtr<ID3D11ShaderResourceView> GetSRV(std::string filename);

private:

	std::map<std::string, ShaderResourceTexture> m_textureMap;
};

inline MW::ComPtr<ID3D11ShaderResourceView> AssetManager::GetSRV(std::string filename)
{
	return m_textureMap[filename].GetSRV();
}

