#pragma once

// Includes
#include <cmath>

// Class definition
class gioMat2
{
	public:
	// Constructors
	gioMat2();
	gioMat2(float a, float b, float c, float d);

	// Destructor
	~gioMat2();

	// Functions
	float determinant();
	gioMat2 inverse();
	gioMat2 transpose();

	// Operators
	gioMat2 operator+(const gioMat2& m);
	gioMat2 operator-(const gioMat2& m);
	gioMat2 operator*(const gioMat2& m);
	gioMat2 operator*(const float& f);
	gioMat2 operator/(const float& f);
	gioMat2& operator+=(const gioMat2& m);
	gioMat2& operator-=(const gioMat2& m);
	gioMat2& operator*=(const gioMat2& m);
	gioMat2& operator*=(const float& f);
	gioMat2& operator/=(const float& f);
	float& operator()(const int& i, const int& j);
	float operator()(const int& i, const int& j) const;

	// Variables
	float m[2][2];
};

// Constructors
gioMat2::gioMat2()
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
}

gioMat2::gioMat2(float a, float b, float c, float d)
{
	m[0][0] = a;
	m[0][1] = b;
	m[1][0] = c;
	m[1][1] = d;
}

// Destructor
gioMat2::~gioMat2()
{
}