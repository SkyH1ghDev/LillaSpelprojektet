#include "AssetManager.hpp"
#include <APNGLoader/uc_apng_loader.h>

//Included for debugging
#include <chrono>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

namespace APNG = uc::apng;

enum AssetManager::fileFormat : std::uint8_t
{
	FileFormat_JPG = 0,
	FileFormat_PNG = 1,
	FileFormat_APNG = 2,
	FileFormat_WAV = 3
};

std::unordered_map<std::string, std::shared_ptr<ISprite>> AssetManager::m_textureMap = {};
std::unordered_map<std::string, int> AssetManager::m_extensionIndex =
	{
		{".jpg", FileFormat_JPG}, {".jpeg", FileFormat_JPG},
		{".png", FileFormat_PNG},
		{".apng", FileFormat_APNG},
		{".wav", FileFormat_WAV}
	};

std::unique_ptr<DX::AudioEngine> AssetManager::m_audioEngine = {};
std::unordered_map<std::string, std::shared_ptr<DX::SoundEffect>> AssetManager::m_sfxMap = {};

//Reads all png and jpg files in folder specified by path string
//All read files are added to the instance of the asset manager
bool AssetManager::ReadFolder(const MW::ComPtr<ID3D11Device>& device, const std::string& path)
{
	// Load default texture
	m_textureMap["default"] = { std::make_shared<StaticSprite>(device) };

	std::wstring_convert< std::codecvt<wchar_t, char, std::mbstate_t> > conv;

	// Load all textures in the Application/Resources/ folder
	for (const auto& entry : FS::recursive_directory_iterator(path))
	{
		if (entry.is_directory()) {
			continue;
		}
		std::string filepath = entry.path().string();

		std::vector<int> positions;
		int res = -1;
		char sub[] = "\\";
		while ((res = filepath.find(sub, res + 1)) != std::string::npos)
		{
			positions.push_back(res);
		}

		for (int pos : positions) 
		{
			filepath.at(pos) = '/';
		}

		//filepath.at(filepath.find('\\')) = '/';
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
						m_textureMap[filename] = { std::make_shared<StaticSprite>(device, filepath) };
						break;
					}

					case FileFormat_APNG:
					{
						auto loader = APNG::create_file_loader(filepath);
						std::vector<std::shared_ptr<StaticSprite>> sprites;

						APNG::frame frame = loader.next_frame();

						float frameTime = static_cast<float>(frame.delay_num) / static_cast<float>(frame.delay_den);
						while (loader.has_frame())
						{
							//
							sprites.push_back(std::make_shared<StaticSprite>(device, frame));
							/* Debug section for dumping images*/
							//std::chrono::milliseconds ms = duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
							//stbi_write_png(std::string("../ImageDump/" + std::to_string(ms.count()) + ".png").c_str(), frame.image.width(), frame.image.height(), 4, frame.image.data(), frame.image.width() * 4);
							/**/
							frame = loader.next_frame();
						}

						m_textureMap[filename] = std::make_shared<AnimatedSprite>(sprites, frameTime);
						break;	
					}

					case FileFormat_WAV:
					{
						std::wstring wstr = conv.from_bytes(filepath);
						m_sfxMap[filename] = std::make_shared<DX::SoundEffect>(m_audioEngine.get(), wstr.c_str());
						break;
					}

				default:
					break;
			}
		}
	}

	return true;
}

//For animations at 12 fps
bool AssetManager::ReadAnimations(const MW::ComPtr<ID3D11Device>& device, const std::string& path)
{
	std::unordered_map<std::string, std::vector<std::shared_ptr<StaticSprite>>> frameMap;
	std::vector<std::string> animationNames;

	for (const auto& entry : FS::recursive_directory_iterator(path))
	{
		if (entry.is_directory()) {
			continue;
		}
		std::string filepath = entry.path().string();

		std::vector<int> positions;
		int res = -1;
		char sub[] = "\\";
		while ((res = filepath.find(sub, res + 1)) != std::string::npos)
		{
			positions.push_back(res);
		}

		for (int pos : positions)
		{
			filepath.at(pos) = '/';
		}

		size_t subFolderIndex = filepath.find_last_of('/');
		size_t folderIndex = filepath.find_last_of('/', subFolderIndex - 1);
		std::string filename = filepath.substr(subFolderIndex + 1, filepath.length() - subFolderIndex);
		std::string extension = filename.substr(filename.find_last_of('.')); 
		std::string animName = filepath.substr(folderIndex + 1 , subFolderIndex - folderIndex - 1);

		if (animationNames.empty())
			animationNames.push_back(animName);

		for (size_t i = 0; i < animationNames.size(); i++)
		{
			if (animationNames[i] == animName)
				break;
			if (i == animationNames.size() - 1)
				animationNames.push_back(animName);
		}

		if (m_extensionIndex.contains(extension))
		{
			switch (m_extensionIndex[extension])
			{
			case FileFormat_PNG:
			{
				frameMap[animName].push_back(std::make_shared<StaticSprite>(device, filepath));
				break;
			}
			default:
				break;
			}
		}
	}

	for (auto name : animationNames)
	{
		m_textureMap[name] = std::make_shared<AnimatedSprite>(frameMap[name], 1.0f/24.0f);
	}

	return true;
}

void AssetManager::InitializeAudioEngine()
{
	m_audioEngine = std::make_unique<DX::AudioEngine>();
}

void AssetManager::ResetAudioEngine()
{
	AssetManager::m_audioEngine.reset();
}