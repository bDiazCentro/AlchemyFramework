#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <vector>
#include <string>

class Object;

class GameManager
{
private:
	GameManager(void);
	static GameManager *instance;
public:
	~GameManager();
	std::vector<Object*> gameObjects;
	static GameManager *Instance(void)
	{
		if (!instance)
		{
			instance = new GameManager();
		}
		return instance;
	}
	void AddGameObject(Object *obj);
	void DestroyObject(const std::string objectName);
	Object *ReturnGameObjectByName(const std::string objectName);
	int NumberOfGameObjects();
};

#endif