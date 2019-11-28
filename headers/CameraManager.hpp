#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H
#include <vector>
#include <string>
class Object;
class CameraComponent;
class CameraManager
{
private:
	CameraManager(void);	
	static CameraManager *instance;
	std::vector<CameraComponent*> cameras;
	int current_active_camera = 0;
public:
	int number_of_cameras = 0;
	~CameraManager();
	static CameraManager *Instance(void)
	{
		if (!instance)
		{
			instance = new CameraManager();
		}
		return instance;
	}
	void CreateCamera(std::string cameraName);
	void RemoveCamera(int camera_id);
	void SwitchActiveCamera(int camera_id);
	void UpdateCamerasId();
	CameraComponent *GetCameraAt(int index);
	CameraComponent *GetActiveCamera();
};

#endif