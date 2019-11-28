#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H
#include <map>
#include "FrameworkFunctions.hpp"

class AssetsManager
{
private:
	AssetsManager(void);
	static AssetsManager *instance;

public:
	~AssetsManager();
	static AssetsManager *Instance(void)
	{
		if (!instance)
		{
			instance = new AssetsManager();
		}
		return instance;
	}

	std::map<std::string, Sprites> sprites;
	Sprites GetImage(const std::string &imageName);
	Sprites* GetImagePtr(const std::string &imageName);
	void UpdateDescriptor(VkDescriptorSet vds, Object *obj);

	void LoadImage(const std::string &filename, Sprites textureData);

	void DebugAssetsManager();
};

#endif