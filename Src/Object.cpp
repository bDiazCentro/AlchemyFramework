#include "Object.hpp"
#include <algorithm>
#include "GameManager.hpp"

#define VNAME(x) #x

#pragma region CONSTRUCTORS

Object::Object()
{
	std::string name = "object";
	int renameTry = 1;
	std::string nameComplement = "";
	while (GameManager::Instance()->ReturnGameObjectByName(name + nameComplement) != nullptr)
	{
		nameComplement = " (" + std::to_string(renameTry++) + ")";
	}
	objectName = name + nameComplement;
	AddComponent(ComponentType::TRANSFORM);
}

Object::Object(string name)
{
	int renameTry = 1;
	std::string nameComplement = "";
	while (GameManager::Instance()->ReturnGameObjectByName(name+nameComplement) != nullptr)
	{
		nameComplement = " ("+std::to_string(renameTry++)+")";
	}
	objectName = name+nameComplement;
	AddComponent(ComponentType::TRANSFORM);
	GameManager::Instance()->AddGameObject(this);
}

#pragma endregion

#pragma region SETTERS AND GETTERS

string Object::ObjectName()
{
	return objectName;
}

void Object::ObjectName(string name)
{
	int renameTry = 1;
	std::string nameComplement = "";
	while (GameManager::Instance()->ReturnGameObjectByName(name + nameComplement) != nullptr)
	{
		nameComplement = " (" + std::to_string(renameTry++) + ")";
	}
	objectName = name+nameComplement;
}
#pragma endregion

#pragma region OBJECT FUNCTIONS

void Object::DebugObjectInfo()
{
	cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Object name: " << ObjectName().c_str() << endl << endl;
	for (int i = 0; i < components.size(); i++)
	{
		switch (componentType[i])
		{
		case TRANSFORM:
			cout << "TRANSFORM INFO" << endl;
			components[i]->transform.Debug();
			break;
		case SPRITE:
			cout << "SPRITE RENDERER INFO" << endl;
			components[i]->spriteRenderer.Debug();
			break;
		case BOX_2D_COLLIDER:
			cout << "BOX 2D COLLIDER INFO" << endl;
			components[i]->box2dCollider.Debug();
			break;
		case CIRCLE_COLLIDER:
			cout << "CIRCLE COLLIDER INFO" << endl;
			components[i]->circleCollider.Debug();
			break;
		case CAMERA:
			cout << "CAMERA INFO" << endl;
			components[i]->cameraComponent.Debug();
			break;
		default:
			break;
		}
		cout << endl;
	}
}

void Object::AddComponent(ComponentType type)
{
	if (std::find(componentType.begin(), componentType.end(), type) != componentType.end())
	{
		cout << "(" << objectName << ") already has a " << GetComponentName(type) << " component." << endl;
		return;
	}

	Component *component = new Component();
	switch (type)
	{
	case ComponentType::TRANSFORM:
		new (&component->transform) TransformComponent(this);
		break;
	case ComponentType::SPRITE:
		new (&component->spriteRenderer) SpriteRendererComponent(this);
		objectHasSpriteComponent = true;
		break;
	case CIRCLE_COLLIDER:
		new (&component->circleCollider) CircleColliderComponent(this);
		break;
	case BOX_2D_COLLIDER:
		new (&component->box2dCollider) Box2dColliderComponent(this);
		break;
	case CAMERA:
		new (&component->cameraComponent) CameraComponent(this);
		break;
	default:
		cout << "(" << objectName << ") " << GetComponentName(type) << " component cannot be add to a gameObject object." << endl;
		break;
	}

	components.push_back(component);
	componentType.push_back(type);
}


void Object::RemoveComponent(ComponentType type)
{
	if (TRANSFORM == type )
	{
		cout << "(" << objectName << ") " << GetComponentName(type) << " component cannot be removed from object." << endl;
		return;
	}
	if (std::find(componentType.begin(), componentType.end(), type) != componentType.end())
	{
		int index = GetIndex(type);
		components.erase(components.begin() + index);
		componentType.erase(componentType.begin() + index);
		if (type == SPRITE)objectHasSpriteComponent = false;
	}
	else {
		cout << "(" << objectName << ")" << " object doesn't have a " << GetComponentName(type) << " component to remove" << endl;
	}
}

void Object::Draw()
{
	components[GetIndex(ComponentType::SPRITE)]->spriteRenderer.Draw();
}

int Object::GetIndex(const ComponentType type)
{
	return find(componentType.begin(), componentType.end(), type) - componentType.begin();
}

Component *Object::GetComponent(const ComponentType type)
{
	auto componentTypeIterator = std::find(componentType.cbegin(), componentType.cend(), type);
	for (int i = 0; i < componentType.size(); ++i)
	{
		if (componentType[i] == type)
		{
			return components[i];
		}
	}
	cout << objectName << " object doesn't have a " << GetComponentName(type) << " component." << endl;
	return nullptr;
}

void Object::Update()
{
	for (int i = 0; i < components.size(); i++)
	{
		switch (componentType[i])
		{
		case TRANSFORM:
			components[i]->transform.Update();
			break;
		case SPRITE:
			components[i]->spriteRenderer.Update();
			break;
		case CIRCLE_COLLIDER:
			components[i]->circleCollider.Update();
			break;
		case BOX_2D_COLLIDER:
			components[i]->box2dCollider.Update();
			break;
		case CAMERA:
			components[i]->cameraComponent.Update();
			break;
		default:
			break;
		}
	}
}

string Object::GetComponentName(ComponentType type)
{
	switch (type)
	{
	case TRANSFORM:
		return "transform";
		break;
	case SPRITE:
		return "sprite";
		break;
	case CIRCLE_COLLIDER:
		return "circle collider";
		break;
	case BOX_2D_COLLIDER:
		return "box 2d collider";
		break;
	case CAMERA:
		return "camera";
		break;
	default:
		break;
	}
}

void Object::SetVertexPoints(unsigned const int size, float *v_array)
{
	vertexPoints = new float[size];
	arraySizeInBytes = size * sizeof(float);
	numVertex = size / 3;
	for (int i = 0; i < size; i++)
	{
		vertexPoints[i] = v_array[i];
	}
}

#pragma endregion