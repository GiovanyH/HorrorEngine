#pragma once

// Includes
#include <cmath>

// Class definition
class gioMat3
{
	public:
	// Constructors
	gioMat3();
	gioMat3(float a, float b, float c, float d, float e, float f, float g, float h, float i);

	// Destructor
	~gioMat3();

	// Functions
	float determinant();
	gioMat3 inverse();
	gioMat3 transpose();

	// Operators
	gioMat3 operator+(const gioMat3& m);
	gioMat3 operator-(const gioMat3& m);
	gioMat3 operator*(const gioMat3& m);
	gioMat3 operator*(const float& f);
	gioMat3 operator/(const float& f);
	gioMat3& operator+=(const gioMat3& m);
	gioMat3& operator-=(const gioMat3& m);
	gioMat3& operator*=(const gioMat3& m);
	gioMat3& operator*=(const float& f);
	gioMat3& operator/=(const float& f);
	float& operator()(const int& i, const int& j);
	float operator()(const int& i, const int& j) const;

	// Variables
	float m[3][3];
};

// Constructors
gioMat3::gioMat3()
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
}

gioMat3::gioMat3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
	m[0][0] = a;
	m[0][1] = b;
	m[0][2] = c;
	m[1][0] = d;
	m[1][1] = e;
	m[1][2] = f;
	m[2][0] = g;
	m[2][1] = h;
	m[2][2] = i;
}

// Destructor
gioMat3::~gioMat3()
{
}