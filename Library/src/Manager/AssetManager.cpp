#include "AssetManager.hpp"
#include "APNGLoader/uc_apng_loader.h"

enum AssetManager::fileFormat : std::uint8_t
{
	FileFormat_JPG = 0,
	FileFormat_PNG = 1,
	FileFormat_APNG = 2,
	FileFormat_WAV = 3
};

std::unordered_map<std::string, std::vector<Sprite>> AssetManager::m_textureMap = {};
std::unordered_map<std::string, int> AssetManager::m_extensionIndex =
	{
		{".jpg", FileFormat_JPG}, {".jpeg", FileFormat_JPG},
		{".png", FileFormat_PNG},
		{".apng", FileFormat_APNG},
		{".wav", FileFormat_WAV}
	};

std::unique_ptr<DX::AudioEngine> AssetManager::audEngine;
std::unordered_map<std::string, std::shared_ptr<DX::SoundEffect>> AssetManager::m_sfxMap = {};

//Reads all png and jpg files in folder specified by path string
//All read files are added to the instance of the asset manager
bool AssetManager::ReadFolder(const MW::ComPtr<ID3D11Device>& device, const std::string& path)
{
	// Load default texture
	m_textureMap["default"] = { Sprite(device) };

	std::wstring_convert< std::codecvt<wchar_t, char, std::mbstate_t> > conv;

	// Load all textures in the Application/Resources/ folder
	for (const auto& entry : FS::directory_iterator(path))
	{
		std::string filepath = entry.path().string();
		filepath.at(filepath.find('\\')) = '/';
		size_t folderIndex = filepath.find_last_of('/');
		std::string filename = filepath.substr(folderIndex + 1, filepath.length() - folderIndex);
		std::string extension = filename.substr(filename.find_last_of('.'));

		if (m_extensionIndex.contains(extension))
		{
			switch (m_extensionIndex[extension])
				{
					case FileFormat_JPG:
					case FileFormat_PNG:
					{
						m_textureMap[filename] = { Sprite(device, filepath) };
						break;
					}

					case FileFormat_APNG:
					{
						uc::apng::loader loader = uc::apng::create_file_loader(filepath);
						std::vector<Sprite> sprites;

						while (loader.has_frame())
						{
							uc::apng::frame frame = loader.next_frame();
							sprites.push_back(Sprite(device, frame));
						}

						m_textureMap[filename] = sprites;
						break;
					}

					case FileFormat_WAV:
					{
						std::wstring wstr = conv.from_bytes(filepath);
						m_sfxMap[filename] = std::make_shared<DX::SoundEffect>(AssetManager::audEngine.get(), wstr.c_str());
						break;
					}

				default:
					break;
			}
		}
	}

	return true;
}

void AssetManager::InitializeAudioEngine()
{
	AssetManager::audEngine = std::make_unique<DX::AudioEngine>();
}