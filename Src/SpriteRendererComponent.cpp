#include "SpriteRendererComponent.hpp"
#include "Object.hpp"
#include "AssetsManager.hpp"

SpriteRendererComponent::SpriteRendererComponent()
{

}

SpriteRendererComponent::SpriteRendererComponent(const std::string name)
{

}

SpriteRendererComponent::SpriteRendererComponent(Object *obj)
{
	Father(obj);
}

void SpriteRendererComponent::LoadImage(const std::string name)
{
	spriteData = &AssetsManager::Instance()->GetImage(name);
	spriteName = name;
}

void SpriteRendererComponent::Draw()
{
	system("cls");
	cout << "This must be drawing something" << endl;
}

void SpriteRendererComponent::Debug()
{
	cout << "Vertex Shader path: " << SpriteMaterial().VertShaderPath() << endl;
	cout << "Fragment Shader path: " << SpriteMaterial().FragShaderPath() << endl;
	//cout << "Texture mipmaplevel: " << spriteData.layerCount << endl;
}

Sprites *SpriteRendererComponent::SpriteData()
{
	return spriteData;
}

void SpriteRendererComponent::Update()
{

}

Material SpriteRendererComponent::SpriteMaterial()
{
	return *material;
}

void SpriteRendererComponent::SpriteMaterial(Material *mat)
{
	material = mat;
}

Object SpriteRendererComponent::Father()
{
	return *father;
}

void SpriteRendererComponent::Father(Object *obj)
{
	father = obj;
}