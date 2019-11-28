#include "ParticleTransformComponent.hpp"
#include <iostream>
#include "Object.hpp"

ParticleTransformComponent::ParticleTransformComponent() 
{
	Position(Vector2(0, 0));
	Scale(Vector2(1, 1));
}

ParticleTransformComponent::ParticleTransformComponent(const Vector2 &p, const Vector2 &s)
{
	Position(p);
	Scale(s);
}

ParticleTransformComponent::ParticleTransformComponent(Object *obj)
{
	Position(Vector2(0, 0));
	Scale(Vector2(1, 1));
	father = obj;
}

Object *ParticleTransformComponent::Father()
{
	return father;
}

void ParticleTransformComponent::Father(Object *obj)
{
	father = obj;
}

ParticleTransformComponent *ParticleTransformComponent::Parent()
{
	return parent;
}

void ParticleTransformComponent::Parent(ParticleTransformComponent *transform)
{
	parent = transform;
}


Vector2 ParticleTransformComponent::Position()
{
	return position;
}

Vector2 ParticleTransformComponent::Scale()
{
	return scale;
}

void ParticleTransformComponent::Set(const Vector2 &t, const Vector2 &s)
{
	Position(t);
	Scale(s);
}

void ParticleTransformComponent::Position(const Vector2 &newPosition)
{
	position = newPosition;
}

void ParticleTransformComponent::Scale(const Vector2 &newScale)
{
	scale = newScale;
}

void ParticleTransformComponent::Translate(const Vector2 &translateValue)
{
	position += translateValue;
}

void ParticleTransformComponent::Debug()
{
	std::cout << "Position: " << "(" << position.X() << ", " << position.Y() << ")" << std::endl
		<< "Scale: " << "(" << scale.X() << ", " << scale.Y() << ")" << std::endl;
}

void ParticleTransformComponent::Update()
{

}

void ParticleTransformComponent::Draw()
{

}