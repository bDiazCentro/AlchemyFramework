#include "Matrix4x4.hpp"

Matrix4x4::Matrix4x4(float m_00, float m_01, float m_02, float m_03,
	float m_10, float m_11, float m_12, float m_13,
	float m_20, float m_21, float m_22, float m_23,
	float m_30, float m_31, float m_32, float m_33) {
	m00 = m_00;
	m01 = m_01;
	m02 = m_02;
	m03 = m_03;
	m10 = m_10;
	m11 = m_11;
	m12 = m_12;
	m13 = m_13;
	m20 = m_20;
	m21 = m_21;
	m22 = m_22;
	m23 = m_23;
	m30 = m_30;
	m31 = m_31;
	m32 = m_32;
	m33 = m_33;
}

Matrix4x4::Matrix4x4(Vector3 pos, Vector3 rot, Vector3 sca)
{
	m00 = pos.X();
	m01 = pos.Y();
	m02 = pos.Z();
	m03 = 0;
	m10 = rot.X();
	m11 = rot.Y();
	m12 = rot.Z();
	m13 = 0;
	m20 = sca.X();
	m21 = sca.Y();
	m22 = sca.Z();
	m23 = 0;
	m30 = 0;
	m31 = 0;
	m32 = 0;
	m33 = 1;
}

const Matrix4x4 Matrix4x4::identity = Matrix4x4(
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1);

const Matrix4x4 Matrix4x4::zero = Matrix4x4(
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
);

const Matrix4x4 Matrix4x4::one = Matrix4x4(
	1, 1, 1, 1,
	1, 1, 1, 1,
	1, 1, 1, 1,
	1, 1, 1, 1
);

