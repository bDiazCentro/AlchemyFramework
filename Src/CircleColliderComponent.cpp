#include "CircleColliderComponent.hpp"
#include <iostream>
#include "Object.hpp"

CircleColliderComponent::CircleColliderComponent()
{
	isTrigger = false;
	offset = Vector2::zero;
	radius = 1;
}

CircleColliderComponent::CircleColliderComponent(Object *obj)
{
	isTrigger = false;
	offset = Vector2::zero;
	radius = 1;
	Father(obj);
}

void CircleColliderComponent::IsTrigger(const bool state)
{
	isTrigger = state;
}

bool CircleColliderComponent::IsTrigger()
{
	return isTrigger;
}

float CircleColliderComponent::Radius()
{
	return radius;
}

void CircleColliderComponent::Radius(const float circleRadius)
{
	radius = circleRadius;
}

Vector2 CircleColliderComponent::Offset()
{
	return offset;
}

void CircleColliderComponent::Offset(const Vector2 &circleOffset)
{
	offset = circleOffset;
}

void CircleColliderComponent::Debug()
{
	std::cout << "Is trigger: " << isTrigger << std::endl;
	std::cout << "Radius: " << radius << std::endl;
	std::cout << "Offset: " << "(" << offset.X() << ", " << offset.Y() << ")" << std::endl;
}

void CircleColliderComponent::Update()
{

}

void CircleColliderComponent::Draw()
{

}

Object CircleColliderComponent::Father()
{
	return *father;
}

void CircleColliderComponent::Father(Object *obj)
{
	father = obj;
}

void CircleColliderComponent::ShowCollider(const bool state)
{
	showCollider = state;
}

bool CircleColliderComponent::ShowCollider()
{
	return showCollider;
}