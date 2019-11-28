#include "Vector3.hpp"

#pragma region constructors setters and getters

void Vector3::X(const float xValue)
{
	x = xValue;
}

void Vector3::Y(const float yValue)
{
	y = yValue;
}

void Vector3::Z(const float zValue)
{
	z = zValue;
}

float Vector3::X() const
{
	return x;
}

float Vector3::Y() const
{
	return y;
}

float Vector3::Z() const
{
	return z;
}

Vector3::Vector3()
{
	X(0);
	Y(0);
	Z(0);
}

Vector3::Vector3(const float xValue, const float yValue, const float zValue)
{
	X(xValue);
	Y(yValue);
	Z(zValue);
}

void Vector3::Set(const float xValue, const float yValue, const float zValue)
{
	X(xValue);
	Y(yValue);
	Z(zValue);
}

#pragma endregion

#pragma region overload operators

Vector3 Vector3::operator+(const Vector3 &v) const
{
	return Vector3(v.x + x, v.y + y, v.z + z);
}

Vector3 Vector3::operator-(const Vector3 &v) const
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator*(const float scalar) const
{
	return Vector3(x*scalar, y*scalar, z*scalar);
}

Vector3 Vector3::operator+= (const Vector3 &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3 Vector3::operator-= (const Vector3 &v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3 Vector3::operator*=(const float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

bool Vector3::operator==(const Vector3 &v) const
{
	return x == v.x && y == v.y && z == v.z;
}

bool Vector3::operator!=(const Vector3 &v) const
{
	return x != v.x || y != v.y || z != v.z;
}

#pragma endregion

#pragma region static members
const Vector3 Vector3::zero = Vector3(0, 0, 0);
const Vector3 Vector3::one = Vector3(1,1,1);
const Vector3 Vector3::left = Vector3(-1,0,0);
const Vector3 Vector3::right = Vector3(1, 0, 0);
const Vector3 Vector3::up = Vector3(0, 1, 0);
const Vector3 Vector3::down = Vector3(0, -1, 0);
const Vector3 Vector3::forward = Vector3(0, 0, 1);
const Vector3 Vector3::backward = Vector3(0, 0, -1);

#pragma endregion
