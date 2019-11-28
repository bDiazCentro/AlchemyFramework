#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
private:
	float x, y, z, w;
public:

#pragma region Constructors setters and getters
	Vector2();
	Vector2(const float xValue, const float yValue);
	float X()const;
	float Y()const;
	void X(const float newXvalue);
	void Y(const float newYvalue);
	void Set(const float newXvalue, const float newYvalue);
#pragma endregion

#pragma region StaticVariables
	static const Vector2 zero;
	static const Vector2 one;
	static const Vector2 left;
	static const Vector2 right;
	static const Vector2 up;
	static const Vector2 down;

#pragma endregion

#pragma region overload operators
	Vector2 operator+(const Vector2 &v)const;
	Vector2 operator-(const Vector2 &v)const;
	Vector2 operator-()const;
	Vector2 operator*(const float scalar)const;
	Vector2 operator+= (const Vector2 &v);
	Vector2 operator-= (const Vector2 &v);
	Vector2 operator*=(const float scalar);
	bool operator==(const Vector2 &v)const;
	bool operator!=(const Vector2 &v)const;

#pragma endregion

};

#endif // !VECTOR3_H