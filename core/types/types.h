#pragma once

/*
	For now, I'm going to have the following types inspired by glm:
	- vec2
	- vec3
	- vec4
	- mat2
	- mat3
	- mat4

	Naming convention is going to be the same as glm, but with a prefix of "gio":
	- gioVec2
	- gioVec3
	- gioVec4
	- gioMat2
	- gioMat3
	- gioMat4
*/

/*
	We're going to use float instead of double, because we're going to be using OpenGL
	and OpenGL uses float, so we're going to use float as well
*/

// TODO: put those types into separate files

// vec2
struct gioVec2
{
	float x, y;
};

// vec3
struct gioVec3
{
	float x, y, z;
};

// vec4
struct gioVec4
{
	float x, y, z, w;
};

// mat2
struct gioMat2
{
	float m00, m01;
	float m10, m11;
};

// mat3
struct gioMat3
{
	float m00, m01, m02;
	float m10, m11, m12;
	float m20, m21, m22;
};

// mat4
struct gioMat4
{
	float m00, m01, m02, m03;
	float m10, m11, m12, m13;
	float m20, m21, m22, m23;
	float m30, m31, m32, m33;
};

// constructors

// vec2
gioVec2 gioVec2Create(float x, float y)
{
	return { x, y };
}

// vec3
gioVec3 gioVec3Create(float x, float y, float z)
{
	return { x, y, z };
}

// vec4
gioVec4 gioVec4Create(float x, float y, float z, float w)
{
	return { x, y, z, w };
}

// mat2
gioMat2 gioMat2Create(float m00, float m01, float m10, float m11)
{
	return { m00, m01, m10, m11 };
}

// mat3
gioMat3 gioMat3Create(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
{
	return { m00, m01, m02, m10, m11, m12, m20, m21, m22 };
}

// mat4
gioMat4 gioMat4Create(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
{
	return { m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 };
}

// for math functions like sqrt and sin/cos
#include <cmath>

// some functions for those types

// vec2
gioVec2 gioVec2Add(gioVec2 a, gioVec2 b)
{
	return { a.x + b.x, a.y + b.y };
}

gioVec2 gioVec2Sub(gioVec2 a, gioVec2 b)
{
	return { a.x - b.x, a.y - b.y };
}

gioVec2 gioVec2Mul(gioVec2 a, gioVec2 b)
{
	return { a.x * b.x, a.y * b.y };
}

gioVec2 gioVec2Div(gioVec2 a, gioVec2 b)
{
	return { a.x / b.x, a.y / b.y };
}

// vec3

gioVec3 gioVec3Add(gioVec3 a, gioVec3 b)
{
	return { a.x + b.x, a.y + b.y, a.z + b.z };
}

gioVec3 gioVec3Sub(gioVec3 a, gioVec3 b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

gioVec3 gioVec3Mul(gioVec3 a, gioVec3 b)
{
	return { a.x * b.x, a.y * b.y, a.z * b.z };
}

gioVec3 gioVec3Div(gioVec3 a, gioVec3 b)
{
	return { a.x / b.x, a.y / b.y, a.z / b.z };
}

// vec4

gioVec4 gioVec4Add(gioVec4 a, gioVec4 b)
{
	return { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

gioVec4 gioVec4Sub(gioVec4 a, gioVec4 b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

gioVec4 gioVec4Mul(gioVec4 a, gioVec4 b)
{
	return { a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}

gioVec4 gioVec4Div(gioVec4 a, gioVec4 b)
{
	return { a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
}

// mat2

gioMat2 gioMat2Add(gioMat2 a, gioMat2 b)
{
	return { a.m00 + b.m00, a.m01 + b.m01, a.m10 + b.m10, a.m11 + b.m11 };
}

gioMat2 gioMat2Sub(gioMat2 a, gioMat2 b)
{
	return { a.m00 - b.m00, a.m01 - b.m01, a.m10 - b.m10, a.m11 - b.m11 };
}

gioMat2 gioMat2Mul(gioMat2 a, gioMat2 b)
{
	return { a.m00 * b.m00 + a.m01 * b.m10, a.m00 * b.m01 + a.m01 * b.m11, a.m10 * b.m00 + a.m11 * b.m10, a.m10 * b.m01 + a.m11 * b.m11 };
}

gioMat2 gioMat2Div(gioMat2 a, gioMat2 b)
{
	return { a.m00 / b.m00, a.m01 / b.m01, a.m10 / b.m10, a.m11 / b.m11 };
}

// mat3

gioMat3 gioMat3Add(gioMat3 a, gioMat3 b)
{
	return { a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02, a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12, a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22 };
}

gioMat3 gioMat3Sub(gioMat3 a, gioMat3 b)
{
	return { a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02, a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12, a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22 };
}

gioMat3 gioMat3Mul(gioMat3 a, gioMat3 b)
{
	return { a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20, a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21, a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22, a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20, a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21, a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22, a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20, a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21, a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 };
}

gioMat3 gioMat3Div(gioMat3 a, gioMat3 b)
{
	return { a.m00 / b.m00, a.m01 / b.m01, a.m02 / b.m02, a.m10 / b.m10, a.m11 / b.m11, a.m12 / b.m12, a.m20 / b.m20, a.m21 / b.m21, a.m22 / b.m22 };
}

// mat4

gioMat4 gioMat4Add(gioMat4 a, gioMat4 b)
{
	return { a.m00 + b.m00, a.m01 + b.m01, a.m02 + b.m02, a.m03 + b.m03, a.m10 + b.m10, a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13, a.m20 + b.m20, a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23, a.m30 + b.m30, a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33 };
}

gioMat4 gioMat4Sub(gioMat4 a, gioMat4 b)
{
	return { a.m00 - b.m00, a.m01 - b.m01, a.m02 - b.m02, a.m03 - b.m03, a.m10 - b.m10, a.m11 - b.m11, a.m12 - b.m12, a.m13 - b.m13, a.m20 - b.m20, a.m21 - b.m21, a.m22 - b.m22, a.m23 - b.m23, a.m30 - b.m30, a.m31 - b.m31, a.m32 - b.m32, a.m33 - b.m33 };
}

gioMat4 gioMat4Mul(gioMat4 a, gioMat4 b)
{
	return { a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30, a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31, a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32, a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23 + a.m03 * b.m33, a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30, a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31, a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32, a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33, a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30, a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31, a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32, a.m20 * b.m03 + a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33, a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30, a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31, a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32, a.m30 * b.m03 + a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33 };
}

gioMat4 gioMat4Div(gioMat4 a, gioMat4 b)
{
	return { a.m00 / b.m00, a.m01 / b.m01, a.m02 / b.m02, a.m03 / b.m03, a.m10 / b.m10, a.m11 / b.m11, a.m12 / b.m12, a.m13 / b.m13, a.m20 / b.m20, a.m21 / b.m21, a.m22 / b.m22, a.m23 / b.m23, a.m30 / b.m30, a.m31 / b.m31, a.m32 / b.m32, a.m33 / b.m33 };
}

// some other functions

// vec2
gioVec2 gioVec2Negate(gioVec2 a)
{
	return { -a.x, -a.y };
}

gioVec2 gioVec2Normalize(gioVec2 a)
{
	float length = sqrt(a.x * a.x + a.y * a.y);
	return { a.x / length, a.y / length };
}

float gioVec2Dot(gioVec2 a, gioVec2 b)
{
	return a.x * b.x + a.y * b.y;
}

float gioVec2Length(gioVec2 a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

// vec3

gioVec3 gioVec3Negate(gioVec3 a)
{
	return { -a.x, -a.y, -a.z };
}

gioVec3 gioVec3Normalize(gioVec3 a)
{
	float length = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return { a.x / length, a.y / length, a.z / length };
}

float gioVec3Dot(gioVec3 a, gioVec3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

gioVec3 gioVec3Cross(gioVec3 a, gioVec3 b)
{
	return { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x };
}

float gioVec3Length(gioVec3 a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

// vec4

gioVec4 gioVec4Negate(gioVec4 a)
{
	return { -a.x, -a.y, -a.z, -a.w };
}

gioVec4 gioVec4Normalize(gioVec4 a)
{
	float length = sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
	return { a.x / length, a.y / length, a.z / length, a.w / length };
}

float gioVec4Dot(gioVec4 a, gioVec4 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

float gioVec4Length(gioVec4 a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

// mat2

gioMat2 gioMat2Transpose(gioMat2 a)
{
	return { a.m00, a.m10, a.m01, a.m11 };
}

// mat3

gioMat3 gioMat3Transpose(gioMat3 a)
{
	return { a.m00, a.m10, a.m20, a.m01, a.m11, a.m21, a.m02, a.m12, a.m22 };
}

// mat4

gioMat4 gioMat4Transpose(gioMat4 a)
{
	return { a.m00, a.m10, a.m20, a.m30, a.m01, a.m11, a.m21, a.m31, a.m02, a.m12, a.m22, a.m32, a.m03, a.m13, a.m23, a.m33 };
}

// some constants

// vec2
gioVec2 gioVec2Zero = { 0.0f, 0.0f };
gioVec2 gioVec2One = { 1.0f, 1.0f };

// vec3
gioVec3 gioVec3Zero = { 0.0f, 0.0f, 0.0f };
gioVec3 gioVec3One = { 1.0f, 1.0f, 1.0f };

// vec4
gioVec4 gioVec4Zero = { 0.0f, 0.0f, 0.0f, 0.0f };
gioVec4 gioVec4One = { 1.0f, 1.0f, 1.0f, 1.0f };

// mat2
gioMat2 gioMat2Identity = { 1.0f, 0.0f, 0.0f, 1.0f };

// mat3
gioMat3 gioMat3Identity = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };

// mat4
gioMat4 gioMat4Identity = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };

// some operator overloads

// vec2
gioVec2 operator+(gioVec2 a, gioVec2 b)
{
	return gioVec2Add(a, b);
}

gioVec2 operator-(gioVec2 a, gioVec2 b)
{
	return gioVec2Sub(a, b);
}

gioVec2 operator*(gioVec2 a, gioVec2 b)
{
	return gioVec2Mul(a, b);
}

gioVec2 operator/(gioVec2 a, gioVec2 b)
{
	return gioVec2Div(a, b);
}

// vec3

gioVec3 operator+(gioVec3 a, gioVec3 b)
{
	return gioVec3Add(a, b);
}

gioVec3 operator-(gioVec3 a, gioVec3 b)
{
	return gioVec3Sub(a, b);
}

gioVec3 operator*(gioVec3 a, gioVec3 b)
{
	return gioVec3Mul(a, b);
}

gioVec3 operator/(gioVec3 a, gioVec3 b)
{
	return gioVec3Div(a, b);
}

// vec4

gioVec4 operator+(gioVec4 a, gioVec4 b)
{
	return gioVec4Add(a, b);
}

gioVec4 operator-(gioVec4 a, gioVec4 b)
{
	return gioVec4Sub(a, b);
}

gioVec4 operator*(gioVec4 a, gioVec4 b)
{
	return gioVec4Mul(a, b);
}

gioVec4 operator/(gioVec4 a, gioVec4 b)
{
	return gioVec4Div(a, b);
}

// mat2

gioMat2 operator+(gioMat2 a, gioMat2 b)
{
	return gioMat2Add(a, b);
}

gioMat2 operator-(gioMat2 a, gioMat2 b)
{
	return gioMat2Sub(a, b);
}

// mat3

gioMat3 operator+(gioMat3 a, gioMat3 b)
{
	return gioMat3Add(a, b);
}

gioMat3 operator-(gioMat3 a, gioMat3 b)
{
	return gioMat3Sub(a, b);
}

// mat4

gioMat4 operator+(gioMat4 a, gioMat4 b)
{
	return gioMat4Add(a, b);
}

gioMat4 operator-(gioMat4 a, gioMat4 b)
{
	return gioMat4Sub(a, b);
}

// some other operator overloads

// vec2
gioVec2 operator-(gioVec2 a)
{
	return gioVec2Negate(a);
}

gioVec2 operator*(gioVec2 a, float b)
{
	return { a.x * b, a.y * b };
}

gioVec2 operator*(float a, gioVec2 b)
{
	return { a * b.x, a * b.y };
}

gioVec2 operator/(gioVec2 a, float b)
{
	return { a.x / b, a.y / b };
}

// vec3

gioVec3 operator-(gioVec3 a)
{
	return gioVec3Negate(a);
}

gioVec3 operator*(gioVec3 a, float b)
{
	return { a.x * b, a.y * b, a.z * b };
}

gioVec3 operator*(float a, gioVec3 b)
{
	return { a * b.x, a * b.y, a * b.z };
}

gioVec3 operator/(gioVec3 a, float b)
{
	return { a.x / b, a.y / b, a.z / b };
}

// vec4

gioVec4 operator-(gioVec4 a)
{
	return gioVec4Negate(a);
}

gioVec4 operator*(gioVec4 a, float b)
{
	return { a.x * b, a.y * b, a.z * b, a.w * b };
}

gioVec4 operator*(float a, gioVec4 b)
{
	return { a * b.x, a * b.y, a * b.z, a * b.w };
}

gioVec4 operator/(gioVec4 a, float b)
{
	return { a.x / b, a.y / b, a.z / b, a.w / b };
}

// mat2

gioMat2 operator*(gioMat2 a, gioMat2 b)
{
	return gioMat2Mul(a, b);
}

gioVec2 operator*(gioMat2 a, gioVec2 b)
{
	return { a.m00 * b.x + a.m01 * b.y, a.m10 * b.x + a.m11 * b.y };
}

gioMat2 operator*(gioMat2 a, float b)
{
	return { a.m00 * b, a.m01 * b, a.m10 * b, a.m11 * b };
}

gioMat2 operator*(float a, gioMat2 b)
{
	return { a * b.m00, a * b.m01, a * b.m10, a * b.m11 };
}

gioMat2 operator/(gioMat2 a, float b)
{
	return { a.m00 / b, a.m01 / b, a.m10 / b, a.m11 / b };
}

// mat3

gioMat3 operator*(gioMat3 a, gioMat3 b)
{
	return gioMat3Mul(a, b);
}

gioVec3 operator*(gioMat3 a, gioVec3 b)
{
	return { a.m00 * b.x + a.m01 * b.y + a.m02 * b.z, a.m10 * b.x + a.m11 * b.y + a.m12 * b.z, a.m20 * b.x + a.m21 * b.y + a.m22 * b.z };
}

gioMat3 operator*(gioMat3 a, float b)
{
	return { a.m00 * b, a.m01 * b, a.m02 * b, a.m10 * b, a.m11 * b, a.m12 * b, a.m20 * b, a.m21 * b, a.m22 * b };
}

gioMat3 operator*(float a, gioMat3 b)
{
	return { a * b.m00, a * b.m01, a * b.m02, a * b.m10, a * b.m11, a * b.m12, a * b.m20, a * b.m21, a * b.m22 };
}

gioMat3 operator/(gioMat3 a, float b)
{
	return { a.m00 / b, a.m01 / b, a.m02 / b, a.m10 / b, a.m11 / b, a.m12 / b, a.m20 / b, a.m21 / b, a.m22 / b };
}

// mat4

gioMat4 operator*(gioMat4 a, gioMat4 b)
{
	return gioMat4Mul(a, b);
}

gioVec4 operator*(gioMat4 a, gioVec4 b)
{
	return { a.m00 * b.x + a.m01 * b.y + a.m02 * b.z + a.m03 * b.w, a.m10 * b.x + a.m11 * b.y + a.m12 * b.z + a.m13 * b.w, a.m20 * b.x + a.m21 * b.y + a.m22 * b.z + a.m23 * b.w, a.m30 * b.x + a.m31 * b.y + a.m32 * b.z + a.m33 * b.w };
}

gioMat4 operator*(gioMat4 a, float b)
{
	return { a.m00 * b, a.m01 * b, a.m02 * b, a.m03 * b, a.m10 * b, a.m11 * b, a.m12 * b, a.m13 * b, a.m20 * b, a.m21 * b, a.m22 * b, a.m23 * b, a.m30 * b, a.m31 * b, a.m32 * b, a.m33 * b };
}

gioMat4 operator*(float a, gioMat4 b)
{
	return { a * b.m00, a * b.m01, a * b.m02, a * b.m03, a * b.m10, a * b.m11, a * b.m12, a * b.m13, a * b.m20, a * b.m21, a * b.m22, a * b.m23, a * b.m30, a * b.m31, a * b.m32, a * b.m33 };
}

gioMat4 operator/(gioMat4 a, float b)
{
	return { a.m00 / b, a.m01 / b, a.m02 / b, a.m03 / b, a.m10 / b, a.m11 / b, a.m12 / b, a.m13 / b, a.m20 / b, a.m21 / b, a.m22 / b, a.m23 / b, a.m30 / b, a.m31 / b, a.m32 / b, a.m33 / b };
}



// some other functions

// vec2

gioVec2 gioVec2Lerp(gioVec2 a, gioVec2 b, float t)
{
	return a + t * (b - a);
}

// vec3

gioVec3 gioVec3Lerp(gioVec3 a, gioVec3 b, float t)
{
	return a + t * (b - a);
}

// vec4

gioVec4 gioVec4Lerp(gioVec4 a, gioVec4 b, float t)
{
	return a + t * (b - a);
}

// mat2

gioMat2 gioMat2Lerp(gioMat2 a, gioMat2 b, float t)
{
	return a + t * (b - a);
}

// mat3

gioMat3 gioMat3Lerp(gioMat3 a, gioMat3 b, float t)
{
	return a + t * (b - a);
}

// mat4

gioMat4 gioMat4Lerp(gioMat4 a, gioMat4 b, float t)
{
	return a + t * (b - a);
}

// some other functions

// vec2

gioVec2 gioVec2Rotate(gioVec2 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.x * c - a.y * s, a.x * s + a.y * c };
}

// vec3

gioVec3 gioVec3RotateX(gioVec3 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.x, a.y * c - a.z * s, a.y * s + a.z * c };
}

gioVec3 gioVec3RotateY(gioVec3 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.x * c + a.z * s, a.y, -a.x * s + a.z * c };
}

gioVec3 gioVec3RotateZ(gioVec3 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.x * c - a.y * s, a.x * s + a.y * c, a.z };
}

// vec4

gioVec4 gioVec4RotateX(gioVec4 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.x, a.y * c - a.z * s, a.y * s + a.z * c, a.w };
}

gioVec4 gioVec4RotateY(gioVec4 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.x * c + a.z * s, a.y, -a.x * s + a.z * c, a.w };
}

gioVec4 gioVec4RotateZ(gioVec4 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.x * c - a.y * s, a.x * s + a.y * c, a.z, a.w };
}

// mat2

gioMat2 gioMat2Rotate(gioMat2 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.m00 * c - a.m01 * s, a.m00 * s + a.m01 * c, a.m10 * c - a.m11 * s, a.m10 * s + a.m11 * c };
}

// mat3

gioMat3 gioMat3RotateX(gioMat3 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.m00, a.m01 * c - a.m02 * s, a.m01 * s + a.m02 * c, a.m10, a.m11 * c - a.m12 * s, a.m11 * s + a.m12 * c, a.m20, a.m21 * c - a.m22 * s, a.m21 * s + a.m22 * c };
}

gioMat3 gioMat3RotateY(gioMat3 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.m00 * c + a.m02 * s, a.m01, -a.m00 * s + a.m02 * c, a.m10 * c + a.m12 * s, a.m11, -a.m10 * s + a.m12 * c, a.m20 * c + a.m22 * s, a.m21, -a.m20 * s + a.m22 * c };
}

gioMat3 gioMat3RotateZ(gioMat3 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.m00 * c - a.m01 * s, a.m00 * s + a.m01 * c, a.m02, a.m10 * c - a.m11 * s, a.m10 * s + a.m11 * c, a.m12, a.m20 * c - a.m21 * s, a.m20 * s + a.m21 * c, a.m22 };
}

// mat4

gioMat4 gioMat4RotateX(gioMat4 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.m00, a.m01 * c - a.m02 * s, a.m01 * s + a.m02 * c, a.m03, a.m10, a.m11 * c - a.m12 * s, a.m11 * s + a.m12 * c, a.m13, a.m20, a.m21 * c - a.m22 * s, a.m21 * s + a.m22 * c, a.m23, a.m30, a.m31 * c - a.m32 * s, a.m31 * s + a.m32 * c, a.m33 };
}

gioMat4 gioMat4RotateY(gioMat4 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.m00 * c + a.m02 * s, a.m01, -a.m00 * s + a.m02 * c, a.m03, a.m10 * c + a.m12 * s, a.m11, -a.m10 * s + a.m12 * c, a.m13, a.m20 * c + a.m22 * s, a.m21, -a.m20 * s + a.m22 * c, a.m23, a.m30, a.m31 * c + a.m32 * s, -a.m31 * s + a.m32 * c, a.m33 };
}

gioMat4 gioMat4RotateZ(gioMat4 a, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	return { a.m00 * c - a.m01 * s, a.m00 * s + a.m01 * c, a.m02, a.m03, a.m10 * c - a.m11 * s, a.m10 * s + a.m11 * c, a.m12, a.m13, a.m20 * c - a.m21 * s, a.m20 * s + a.m21 * c, a.m22, a.m23, a.m30, a.m31 * c - a.m32 * s, a.m31 * s + a.m32 * c, a.m33 };
}

// some other functions

// vec2

gioVec2 gioVec2Transform(gioVec2 a, gioMat2 b)
{
	return { b.m00 * a.x + b.m01 * a.y, b.m10 * a.x + b.m11 * a.y };
}

// vec3

gioVec3 gioVec3Transform(gioVec3 a, gioMat3 b)
{
	return { b.m00 * a.x + b.m01 * a.y + b.m02 * a.z, b.m10 * a.x + b.m11 * a.y + b.m12 * a.z, b.m20 * a.x + b.m21 * a.y + b.m22 * a.z };
}

// vec4

gioVec4 gioVec4Transform(gioVec4 a, gioMat4 b)
{
	return { b.m00 * a.x + b.m01 * a.y + b.m02 * a.z + b.m03 * a.w, b.m10 * a.x + b.m11 * a.y + b.m12 * a.z + b.m13 * a.w, b.m20 * a.x + b.m21 * a.y + b.m22 * a.z + b.m23 * a.w, b.m30 * a.x + b.m31 * a.y + b.m32 * a.z + b.m33 * a.w };
}

// some other functions

// vec2

gioVec2 gioVec2TransformNormal(gioVec2 a, gioMat2 b)
{
	return { b.m00 * a.x + b.m01 * a.y, b.m10 * a.x + b.m11 * a.y };
}

// vec3

gioVec3 gioVec3TransformNormal(gioVec3 a, gioMat3 b)
{
	return { b.m00 * a.x + b.m01 * a.y + b.m02 * a.z, b.m10 * a.x + b.m11 * a.y + b.m12 * a.z, b.m20 * a.x + b.m21 * a.y + b.m22 * a.z };
}

// vec4

gioVec4 gioVec4TransformNormal(gioVec4 a, gioMat4 b)
{
	return { b.m00 * a.x + b.m01 * a.y + b.m02 * a.z + b.m03 * a.w, b.m10 * a.x + b.m11 * a.y + b.m12 * a.z + b.m13 * a.w, b.m20 * a.x + b.m21 * a.y + b.m22 * a.z + b.m23 * a.w, b.m30 * a.x + b.m31 * a.y + b.m32 * a.z + b.m33 * a.w };
}