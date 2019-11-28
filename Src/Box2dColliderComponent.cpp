#include "Box2dColliderComponent.hpp"
#include <iostream>
#include "Object.hpp"

Box2dColliderComponent::Box2dColliderComponent()
{
	isTrigger = false;
}

Box2dColliderComponent::Box2dColliderComponent(Object *obj)
{
	isTrigger = false;
	Father(obj);
}

void Box2dColliderComponent::IsTrigger(const bool state)
{
	isTrigger = state;
}

bool Box2dColliderComponent::IsTrigger()
{
	return isTrigger;
}

Vector2 Box2dColliderComponent::Size()
{
	return size;
}

void Box2dColliderComponent::Size(const Vector2 &box2dsize)
{
	size = box2dsize;
}

Vector2 Box2dColliderComponent::Offset()
{
	return offset;
}

void Box2dColliderComponent::Offset(const Vector2 &box2doffset)
{
	offset = box2doffset;
}

void Box2dColliderComponent::Debug()
{
	std::cout << "Is trigger: " << isTrigger << std::endl;
	std::cout << "Size: " << "(" << size.X() << ", " << size.Y() << ")" << std::endl;
	std::cout << "Offset: " << "(" << offset.X() << ", " << offset.Y() << ")" << std::endl;
}

void Box2dColliderComponent::ShowCollider(const bool state)
{
	showCollider = state;
}

bool Box2dColliderComponent::ShowCollider()
{
	return showCollider;
}

void Box2dColliderComponent::Update()
{

}

void Box2dColliderComponent::Draw()
{

}

Object Box2dColliderComponent::Father()
{
	return *father;
}

void Box2dColliderComponent::Father(Object *obj)
{
	father = obj;
}