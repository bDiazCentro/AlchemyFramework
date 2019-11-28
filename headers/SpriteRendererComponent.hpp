#ifndef  SPRITE_RENDERER_COMPONENT_H
#define SPRITE_RENDERER_COMPONENT_H
#include <iostream>
#include<string>
#include "Material.hpp"
#include "FrameworkFunctions.hpp"

using namespace std;;

class Object;

class SpriteRendererComponent
{
private:
	Material *material;
	Object *father;
	Sprites *spriteData;
public:
	std::string spriteName;
	bool enabled = true;
	VkBuffer indexBuffer;
	VkDeviceMemory indexBufferMemory;
	Object Father();
	void Father(Object *obj);
	SpriteRendererComponent();
	SpriteRendererComponent(const string path);
	SpriteRendererComponent(Object *obj);
	void LoadImage(const string name);
	Material SpriteMaterial();
	void SpriteMaterial(Material *mat);
	Sprites *SpriteData();
	void Draw();
	void Debug();
	void Update();
};

#endif // !SPRITE_RENDERER_COMPONENT_H