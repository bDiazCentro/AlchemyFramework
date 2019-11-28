#include "Color.hpp"

Color::Color()
{
	SetColor(Color::black);
}

Color::Color(float r, float g, float b, float a)
{
	SetColor(r, g, b, a);
}

Color::Color(float r, float g, float b)
{
	SetColor(r, g, b, 1);
}

Color Color::GetColor()
{
	return *this;
}

void Color::SetColor(Color c)
{
	SetColor(c.a, c.g, c.b, c.a);
}

void Color::SetColor(float r, float g, float b, float a)
{
	R(r);
	G(g);
	B(b);
	A(a);
}

void Color::SetColor(float r, float g, float b)
{
	SetColor(r, g, b, 1);
}

float Color::R()
{
	return r;
}

float Color::G()
{
	return g;
}

float Color::B()
{
	return b;
}

float Color::A()
{
	return a;
}

void Color::R(float redValue)
{
	r = redValue;
}

void Color::G(float greenValue)
{
	g = greenValue;
}

void Color::B(float blueValue)
{
	b = blueValue;
}

void Color::A(float alphaValue)
{
	a = alphaValue;
}

const Color Color::white = Color(1, 1, 1, 1);
const Color Color::black = Color(0, 0, 0, 1);
const Color Color::red = Color(1, 0, 0, 1);
const Color Color::blue = Color(0, 0, 1, 1);
const Color Color::green = Color(0, 1, 0, 1);
const Color Color::yellow = Color(1, 1, 0, 1);
const Color Color::cyan = Color(0, 1, 1, 1);
const Color Color::magenta = Color(1, 0, 1, 1);