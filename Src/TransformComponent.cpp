#include "TransformComponent.hpp"

#include <iostream>
#include "Object.hpp"

using namespace std;

Vector3 TransformComponent::Position()
{
	return position;
}

Vector3 TransformComponent::Rotation()
{
	return rotation;
}

Vector3 TransformComponent::Scale()
{
	return scale;
}

void TransformComponent::Position(const Vector3 &newPosition)
{
	position = newPosition;
}

void TransformComponent::Scale(const Vector3 &newScale)
{
	scale = newScale;
}

void TransformComponent::Rotation(const Vector3 &newRotation)
{
	rotation = newRotation;
}

TransformComponent::TransformComponent()
{
	Position(Vector3(0, 0, 0));
	Rotation(Vector3(0, 0, 0));
	Scale(Vector3(1, 1, 1));
	Parent(nullptr);
}

TransformComponent::TransformComponent(const Vector3 &positionValue, const Vector3 &rotationValue, const Vector3 &scaleValue)
{
	Position(positionValue);
	Rotation(rotationValue);
	Scale(scaleValue);
	Parent(nullptr);
}

TransformComponent::TransformComponent(Object *obj)
{
	Position(Vector3(0, 0, 0));
	Rotation(Vector3(0, 0, 0));
	Scale(Vector3(1, 1, 1));
	Father(obj);
	Parent(nullptr);
}

void TransformComponent::Set(const Vector3 &positionValue, const Vector3 &rotationValue, const Vector3 &scaleValue)
{
	Position(positionValue);
	Rotation(rotationValue);
	Scale(scaleValue);
}

void TransformComponent::Translate(const Vector3 &translateValue)
{
	position += translateValue;
}

void TransformComponent::Rotate(const Vector3 &rotateValue)
{

}

void TransformComponent::Debug()
{
	cout << "Position: " << "(" << position.X() << ", " << position.Y() << ", " << position.Z() << ")" << endl
		<< "Rotation: " << "(" << rotation.X() << ", " << rotation.Y() << ", " << rotation.Z() << ")" << endl
		<< "Scale: " << "(" << scale.X() << ", " << scale.Y() << ", " << scale.Z() << ")" << endl
		<< "Father: " << Father()->ObjectName() << endl;
}

Object *TransformComponent::Father()
{
	return father;
}

void TransformComponent::Father(Object *obj)
{
	father = obj;
}

TransformComponent *TransformComponent::Parent()
{
	return parent;
}

void TransformComponent::Parent(TransformComponent *transform)
{
	parent = transform;
}

void TransformComponent::Update()
{
}

void TransformComponent::Draw()
{

}