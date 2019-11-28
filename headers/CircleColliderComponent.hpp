#ifndef CIRCLE_COLLIDER_COMPONENT_H
#define CIRCLE_COLLIDER_COMPONENT_H
#include "Vector2.hpp"

class Object;

class CircleColliderComponent
{
private:
	bool isTrigger;
	bool showCollider;
	float radius;
	Vector2 offset;
	Object *father;
public:
	Object Father();
	void Father(Object *obj);
	CircleColliderComponent();
	CircleColliderComponent(Object *obj);
	bool IsTrigger();
	void IsTrigger(const bool state);
	float Radius();
	void Radius(const float circleRadius);
	Vector2 Offset();
	void Offset(const Vector2 &circleOffset);
	void Debug();
	bool ShowCollider();
	void ShowCollider(const bool state);
	void Update();
	void Draw();
};

#endif