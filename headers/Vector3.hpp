#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
private:
	float x, y, z;
public:

#pragma region Constructors setters and getters
	Vector3();
	Vector3(const float xValue, const float yValue, const float zValue);
	float X()const;
	float Y()const;
	float Z()const;
	void X(const float newXvalue);
	void Y(const float newYvalue);
	void Z(const float newZvalue);
	void Set(const float newXvalue, const float newYvalue, const float newZvalue);
#pragma endregion

#pragma region StaticVariables
	static const Vector3 zero;
	static const Vector3 one;
	static const Vector3 left;
	static const Vector3 right;
	static const Vector3 up;
	static const Vector3 down;
	static const Vector3 forward;
	static const Vector3 backward;
#pragma endregion

#pragma region overload operators
	Vector3 operator+(const Vector3 &v) const;
	Vector3 operator-(const Vector3 &v) const;
	Vector3 operator-() const;
	Vector3 operator*(const float scalar) const;
	Vector3 operator+= (const Vector3 &v);
	Vector3 operator-= (const Vector3 &v);
	Vector3 operator*=(const float scalar);
	bool operator==(const Vector3 &v)const;
	bool operator!=(const Vector3 &v)const;

#pragma endregion

};

#endif // !VECTOR3_H