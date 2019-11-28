#ifndef PARTICLE_TRANSFORM_COMPONENT_H
#define PARTICLE_TRANSFORM_COMPONENT_H

#include "Vector2.hpp"
#include "Vector3.hpp"

class Object;

class ParticleTransformComponent
{
private:
	Vector2 position, scale;
	Object *father;
	ParticleTransformComponent *parent;
public:
	ParticleTransformComponent();
	ParticleTransformComponent(const Vector2 &p, const Vector2 &s);
	ParticleTransformComponent(Object *obj);

	Vector2 Position();
	Vector2 Scale();

	void Set(const Vector2 &t, const Vector2 &s);
	void Position(const Vector2 &newTranslate);
	void Scale(const Vector2 &newScale);

	void Translate(const Vector2 &translateValue);

	Object *Father();
	void Father(Object *obj);
	ParticleTransformComponent *Parent();
	void Parent(ParticleTransformComponent *transform);

	void Debug();
	void Update();
	void Draw();
};

#endif