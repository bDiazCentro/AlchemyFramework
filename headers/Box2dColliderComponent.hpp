#ifndef BOX_2D_COLLIDER_COMPONENT_H
#define BOX_2D_COLLIDER_COMPONENT_H
#include "Vector2.hpp"

class Object;

class Box2dColliderComponent
{
private:
	bool isTrigger;
	bool showCollider;
	Vector2 size;
	Vector2 offset;
	Object *father;
public:
	Object Father();
	void Father(Object *obj);
	Box2dColliderComponent();
	Box2dColliderComponent(Object *obj);
	bool IsTrigger();
	void IsTrigger(const bool state);
	bool ShowCollider();
	void ShowCollider(const bool state);
	Vector2 Size();
	void Size(const Vector2 &box2dsize);
	Vector2 Offset();
	void Offset(const Vector2 &box2doffset);
	void Debug();
	void Update();
	void Draw();
};

#endif // !BOX_2D_COLLIDER_COMPONENT_H