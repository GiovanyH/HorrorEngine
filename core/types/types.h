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
// Including the vectors
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

// some functions for those types

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

// mat2
gioMat2 gioMat2Identity = { 1.0f, 0.0f, 0.0f, 1.0f };

// mat3
gioMat3 gioMat3Identity = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };

// mat4
gioMat4 gioMat4Identity = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };

// some operator overloads

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

// mat2

gioMat2 operator*(gioMat2 a, gioMat2 b)
{
	return gioMat2Mul(a, b);
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