#ifndef COLOR_H
#define COLOR_H

class Color
{
private:
	float r, g, b, a;
public:
	Color();
	Color(float r, float g, float b, float a);
	Color(float r, float g, float b);
	Color GetColor();
	void SetColor(float r, float g, float b, float a);
	void SetColor(Color c);
	void SetColor(float r, float g, float b);
	float R();
	float G();
	float B();
	float A();
	void R(float redValue);
	void G(float greenValue);
	void B(float blueValue);
	void A(float alphaValue);

	static const Color white;
	static const Color black;
	static const Color red;
	static const Color blue;
	static const Color green;
	static const Color yellow;
	static const Color cyan;
	static const Color magenta;

};

#endif // !COLOR?H