#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H

enum Projection {ORTHOGRAPHIC, PERSPECTIVE};

class Object;
class TransformComponent;

class CameraComponent
{
private:
	Object *father;
	TransformComponent *lookTarget;
public:
	Projection projection = Projection::ORTHOGRAPHIC;
	float fov;
	float near;
	float far;
	int cameraId;
	bool active;
	void Debug();
	void Update();
	Object Father();
	void Father(Object *obj);
	void LookAt(TransformComponent *target);
	CameraComponent();
	CameraComponent(Object *obj);
};

#endif