#include "Vector2.hpp"

#pragma region constructors setters and getters

void Vector2::X(const float xValue)
{
	x = xValue;
}

void Vector2::Y(const float yValue)
{
	y = yValue;
}

float Vector2::X() const
{
	return x;
}

float Vector2::Y() const
{
	return y;
}


Vector2::Vector2()
{
	X(0);
	Y(0);
	z = 0;
	w = 1;
}

Vector2::Vector2(const float xValue, const float yValue)
{
	X(xValue);
	Y(yValue);
	z = 0;
	w = 1;
}

void Vector2::Set(const float xValue, const float yValue)
{
	X(xValue);
	Y(yValue);
}

#pragma endregion

#pragma region overload operators

Vector2 Vector2::operator+(const Vector2 &v)const
{
	return Vector2(v.x + x, v.y + y);
}

Vector2 Vector2::operator-(const Vector2 &v)const
{
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator-()const
{
	return Vector2(-x, -y);
}

Vector2 Vector2::operator*(const float scalar)const
{
	return Vector2(x*scalar, y*scalar);
}

Vector2 Vector2::operator+= (const Vector2 &v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vector2 Vector2::operator-= (const Vector2 &v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Vector2 Vector2::operator*=(const float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

bool Vector2::operator==(const Vector2 &v)const
{
	return x == v.x && y == v.y;
}

bool Vector2::operator!=(const Vector2 &v)const
{
	return x != v.x || y != v.y;
}

#pragma endregion

#pragma region static variables
const Vector2 Vector2::zero = Vector2(0, 0);
const Vector2 Vector2::one = Vector2(1, 1);
const Vector2 Vector2::left = Vector2(-1, 0);
const Vector2 Vector2::right = Vector2(1, 0);
const Vector2 Vector2::up = Vector2(0, 1);
const Vector2 Vector2::down = Vector2(0, -1);
#pragma endregion


