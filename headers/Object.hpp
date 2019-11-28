#ifndef OBJECT_H
#define OBJETC_H
#include <iostream>
#include <vector>
#include "Component.hpp"
#include "VulkanFunctions.hpp"

using namespace std;

class Object
{
private:
	string objectName;
public:
	bool objectHasSpriteComponent;
	UniformBufferObject ubo = {};
	VkBuffer uniformBuffer;
	VkDeviceMemory uniformBufferMemory;
	VkDescriptorSet descriptorSet;
	float *vertexPoints;
	unsigned int arraySizeInBytes;
	int numVertex;
	vector<Component*> components;
	vector<ComponentType> componentType;
	Object();
	Object(string name);
	string ObjectName();
	void ObjectName(string name);
	void DebugObjectInfo();

	int GetIndex(const ComponentType type);

	Component *GetComponent(const ComponentType type);

	string GetComponentName(ComponentType type);
	void AddComponent(ComponentType type);
	void RemoveComponent(ComponentType type);
	
	void Update();
	void Draw();

	void SetVertexPoints(unsigned const int size, float *v_array);
};

#endif // !OBJECT_H
