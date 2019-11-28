#ifndef MATRIX_4X4_H
#define MATRIX_4X4_H
#include "Vector3.hpp"

class TransformComponent;


class Matrix4x4
{
private:
	float m00 = 0;
	float m01 = 0;
	float m02 = 0;
	float m03 = 0;
	float m10 = 0;
	float m11 = 0;
	float m12 = 0;
	float m13 = 0;
	float m20 = 0;
	float m21 = 0;
	float m22 = 0;
	float m23 = 0;
	float m30 = 0;
	float m31 = 0;
	float m32 = 0;
	float m33 = 0;
public:
	Matrix4x4(float m_00, float m_01, float m_02, float m_03,
		float m_10, float m_11, float m_12, float m_13,
		float m_20, float m_21, float m_22, float m_23,
		float m_30, float m_31, float m_32, float m_33);

	Matrix4x4(Vector3 pos, Vector3 rot, Vector3 sca);

	static const Matrix4x4 identity;
	static const Matrix4x4 zero;
	static const Matrix4x4 one;
};

#endif // !MATRIX_4X4_H
