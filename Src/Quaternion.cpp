#include "Quaternion.hpp"

#pragma region constructors getters and setters

void Quaternion::X(const float xValue)
{
	x = xValue;
}

void Quaternion::Y(const float yValue)
{
	y = yValue;
}

void Quaternion::Z(const float zValue)
{
	z = zValue;
}

float Quaternion::X()
{
	return x;
}

float Quaternion::Y()
{
	return y;
}

float Quaternion::Z()
{
	return z;
}

Quaternion::Quaternion()
{
	X(0);
	Y(0);
	Z(0);
	w = 1;
}

Quaternion::Quaternion(const float xValue, const float yValue, const float zValue)
{
	X(xValue);
	Y(yValue);
	Z(zValue);
	w = 1;
}

void Quaternion::Set(const float xValue, const float yValue, const float zValue)
{
	X(xValue);
	Y(yValue);
	Z(zValue);
}

#pragma endregion

#pragma region overload operators

Quaternion Quaternion::operator+(const Quaternion &v)
{
	return Quaternion(v.x + x, v.y + y, v.z + z);
}

Quaternion Quaternion::operator-(const Quaternion &v)
{
	return Quaternion(x - v.x, y - v.y, z - v.z);
}

Quaternion Quaternion::operator-()
{
	return Quaternion(-x, -y, -z);
}

Quaternion Quaternion::operator*(const float scalar)
{
	return Quaternion(x*scalar, y*scalar, z*scalar);
}

Quaternion Quaternion::operator+= (const Quaternion &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Quaternion Quaternion::operator-= (const Quaternion &v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Quaternion Quaternion::operator*=(const float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

bool Quaternion::operator==(const Quaternion &v)
{
	return x == v.x && y == v.y && z == v.z;
}

bool Quaternion::operator!=(const Quaternion &v)
{
	return x != v.x || y != v.y || z != v.z;
}

#pragma endregion

#pragma region static variables

const Quaternion Quaternion::zero = Quaternion(0, 0, 0);
const Quaternion Quaternion::one = Quaternion(1,1,1);

#pragma endregion