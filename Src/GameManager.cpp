#include "GameManager.hpp"
#include "Object.hpp"

GameManager *GameManager::instance = nullptr;

GameManager::~GameManager() {}

GameManager::GameManager(void) {}

void GameManager::AddGameObject(Object *obj)
{
	gameObjects.push_back(obj);
}

Object *GameManager::ReturnGameObjectByName(const std::string objectName)
{
	for (int i = 0; i < NumberOfGameObjects(); i++)
	{
		if (objectName == gameObjects[i]->ObjectName())
		{
			return gameObjects[i];
		}
	}
	return nullptr;
}

void GameManager::DestroyObject(const std::string objectName)
{

}

int GameManager::NumberOfGameObjects()
{
	return gameObjects.size();
}
