#include "CameraManager.hpp"
#include "Object.hpp"

CameraManager *CameraManager::instance = nullptr;

void CameraManager::CreateCamera(std::string cameraName)
{
	string cameraNumber = std::to_string((int)cameras.size());
	Object *newCamera = new Object(cameraName);
	newCamera->AddComponent(ComponentType::CAMERA);
	cameras.push_back(&newCamera->GetComponent(ComponentType::CAMERA)->cameraComponent);
	number_of_cameras = cameras.size();
	UpdateCamerasId();
}

void CameraManager::RemoveCamera(int camera_id)
{
	if (camera_id >= cameras.size())
	{
		cout << "Camera Id out of bounds." << endl << "The max number for camera_id is " << std::to_string((int)cameras.size() - 1) << endl;
		return;
	}
	bool erasedCameraWasActive = false;
	if (cameras[camera_id]->active)
	{
		erasedCameraWasActive = true;
	}
	cameras.erase(cameras.begin() + current_active_camera);
	UpdateCamerasId();
	number_of_cameras = cameras.size();
	if (erasedCameraWasActive) 
	{
		SwitchActiveCamera(0);
	}
}

void CameraManager::SwitchActiveCamera(int camera_id)
{
	if (camera_id >= number_of_cameras || camera_id < 0)
	{
		cout << "Camera id out of bounds." << endl;
		return;
	}
	cameras[current_active_camera]->active = false;
	current_active_camera = camera_id;
	cameras[current_active_camera]->active = true;
}

void CameraManager::UpdateCamerasId()
{
	for (int i = 0; i < cameras.size(); i++)
	{
		cameras[i]->cameraId = i;
	}
}

CameraComponent *CameraManager::GetActiveCamera()
{
	return cameras[current_active_camera];
}

CameraComponent *CameraManager::GetCameraAt(int index)
{
	return cameras[index];
}

CameraManager::~CameraManager() {}

CameraManager::CameraManager(void) {}