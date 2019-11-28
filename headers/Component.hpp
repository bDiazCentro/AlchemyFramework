#ifndef COMPONENT_H
#define COMPONENT_H
#include "TransformComponent.hpp"
#include "SpriteRendererComponent.hpp"
#include "CircleColliderComponent.hpp"
#include "Box2dColliderComponent.hpp"
#include "ParticleTransformComponent.hpp"
#include "ParticleRendererComponent.hpp"
#include "ParticleRendererComponent.hpp"
#include "BackgroundBehaviourComponent.hpp"
#include "FluidBehaviourComponent.hpp"
#include "CameraComponent.hpp"

union Component
{
public:
	TransformComponent transform;
	SpriteRendererComponent spriteRenderer;
	Box2dColliderComponent box2dCollider;
	CircleColliderComponent circleCollider;
	CameraComponent cameraComponent;

	Component() {}
	~Component() {}
};


enum ComponentType {
	TRANSFORM,
	SPRITE,
	BOX_2D_COLLIDER,
	CIRCLE_COLLIDER,
	CAMERA
};
#endif // !COMPONENT_H