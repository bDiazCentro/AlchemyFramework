#include "AssetsManager.hpp"
#include "VulkanFunctions.hpp"
#include "Object.hpp"

AssetsManager *AssetsManager::instance = nullptr;

AssetsManager::~AssetsManager() {}

AssetsManager::AssetsManager(void) {}

void AssetsManager::LoadImage(const std::string &filename, Sprites textureData)
{
	sprites.insert(std::pair<std::string, Sprites>(filename, textureData));
}

Sprites AssetsManager::GetImage(const std::string &imageName)
{
	if (sprites.find(imageName) != sprites.end())
		return sprites.find(imageName)->second;
}

void AssetsManager::UpdateDescriptor(VkDescriptorSet vds, Object *obj)
{
	//if (sprites.find(filename) != sprites.end())
	//	sprites.find(filename)->second.descriptorSet = vds;
	obj->descriptorSet = vds;
}

Sprites* AssetsManager::GetImagePtr(const std::string &imageName)
{
	if (sprites.find(imageName) != sprites.end())
	return &sprites.find(imageName)->second;
}

void AssetsManager::DebugAssetsManager()
{
	std::cout << "\nImages size: " << sprites.size() << std::endl;
}
