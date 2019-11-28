	#ifndef INPUT_H
#define INPUT_H
#include "Vector2.hpp"

namespace Input
{
	Vector2 mousePosition;
	//keyboard
	int releaseKey = -1;
	int holdkey = -1;
	int presskey = -1;
	bool releaseState = false;
	bool holdState = false;
	bool pressState = false;
	//mouse
	int releaseButton = -1;
	int pressButton = -1;
	bool releaseStateButton = false;
	bool pressStateButton = false;

	bool GetKeyDown(int key)
	{
		if (key == presskey && pressState)
		{
			presskey = -1;
			pressState = false;
			return true;
		}
		return false;
	}

	bool GetKey(int key)
	{
		if (key == holdkey && holdState)
		{
			holdkey = -1;
			holdState = false;
			return true;
		}
		return false;
	}

	bool GetKeyUp(int key)
	{
		if (key == releaseKey && releaseState)
		{
			releaseKey = -1;
			releaseState = false;
			return true;
		}
		return false;
	}

	bool GetMouseButtonDown(int button)
	{
		if (button == pressButton && pressStateButton)
		{
			pressButton = -1;
			pressStateButton = false;
			return true;
		}
		return false;
	}

	bool GetMouseButtonUp(int button)
	{
		if (button == releaseButton && releaseStateButton)
		{
			releaseButton = -1;
			releaseStateButton = false;
			return true;
		}
		return false;
	}
};

#endif