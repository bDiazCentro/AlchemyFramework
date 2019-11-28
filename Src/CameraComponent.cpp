#include "CameraComponent.hpp"
#include <iostream>
#include "Object.hpp"
using namespace std;
void CameraComponent::Debug()
{
	std::string projectionString = "";
	projectionString = (projection == Projection::ORTHOGRAPHIC) ? "Orthographic." : "Perspective.";
	cout << "Projection: " << projectionString.c_str() << endl <<
		"Field of view: " << fov << endl <<
		"Near: " << near << endl <<
		"Far: " << far << endl <<
		"Camera Id: " << cameraId << endl <<
		"Camera active state: " << active << endl;
}

void CameraComponent::Update()
{
	
}

Object CameraComponent::Father()
{
	return *father;
}

void CameraComponent::Father(Object *obj)
{
	father = obj;
}

CameraComponent::CameraComponent()
{
	fov = 60.0;
	near = 0.3f;
	far = 1000.0f;
	cameraId = 0;
	active = false;
	lookTarget = nullptr;
}

CameraComponent::CameraComponent(Object *obj)
{
	Father(obj);
	fov = 60.0;
	near = 0.1f;
	far = 10.0f;
	cameraId = 0;
	active = false;
	lookTarget = nullptr;
}
void CameraComponent::LookAt(TransformComponent *target)
{
	lookTarget = target;
}