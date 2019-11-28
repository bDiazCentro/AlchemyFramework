#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion
{
private:
	float x, y, z, w;
public:
#pragma region constructors getters and setters
	Quaternion();
	Quaternion(const float xValue, const float yValue, const float zValue);
	float X();
	float Y();
	float Z();
	void X(const float newXvalue);
	void Y(const float newYvalue);
	void Z(const float newZvalue);
	void Set(const float newXvalue, const float newYvalue, const float newZvalue);
#pragma endregion

#pragma region overload operators
	Quaternion operator+(const Quaternion &v);
	Quaternion operator-(const Quaternion &v);
	Quaternion operator-();
	Quaternion operator*(const float scalar);
	Quaternion operator+= (const Quaternion &v);
	Quaternion operator-= (const Quaternion &v);
	Quaternion operator*=(const float scalar);
	bool operator==(const Quaternion &v);
	bool operator!=(const Quaternion &v);

#pragma endregion

#pragma region static variables

	static const Quaternion zero;
	static const Quaternion one;

#pragma endregion
};

#endif // !QUATERNION_H