#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "Vector3.hpp"

class Object;

class TransformComponent
{
private:
	Vector3 position, rotation, scale;
	Object *father;
	TransformComponent *parent;
public:
	TransformComponent();
	TransformComponent(const Vector3 &t, const Vector3 &r, const Vector3 &s);
	TransformComponent(Object *obj);
	Vector3 Position();
	Vector3 Rotation();
	Vector3 Scale();

	void Set(const Vector3 &t, const Vector3 &r, const Vector3 &s);
	void Position(const Vector3 &newTranslate);
	void Rotation(const Vector3 &newRotation);
	void Scale(const Vector3 &newScale);
	Object *Father();
	void Father(Object *obj);
	TransformComponent *Parent();
	void Parent(TransformComponent *transform);

	void Translate(const Vector3 &translateValue);
	void Rotate(const Vector3 &rotateValue);

	void Debug();
	void Update();
	void Draw();
};

#endif // !TRANSFORM_COMPONENT_H