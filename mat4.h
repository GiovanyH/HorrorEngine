#pragma once

// Includes
#include <cmath>

// Class definition
class gioMat4
{
	public:
	// Constructors
	gioMat4();
	gioMat4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);

	// Destructor
	~gioMat4();

	// Functions
	float determinant();
	gioMat4 inverse();
	gioMat4 transpose();

	// Operators
	gioMat4 operator+(const gioMat4& m);
	gioMat4 operator-(const gioMat4& m);
	gioMat4 operator*(const gioMat4& m);
	gioMat4 operator*(const float& f);
	gioMat4 operator/(const float& f);
	gioMat4& operator+=(const gioMat4& m);
	gioMat4& operator-=(const gioMat4& m);
	gioMat4& operator*=(const gioMat4& m);
	gioMat4& operator*=(const float& f);
	gioMat4& operator/=(const float& f);
	float& operator()(const int& i, const int& j);
	float operator()(const int& i, const int& j) const;

	// Variables
	float m[4][4];
};

// Constructors
gioMat4::gioMat4()
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = 0.0f;
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

gioMat4::gioMat4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p)
{
	this->m[0][0] = a;
	this->m[0][1] = b;
	this->m[0][2] = c;
	this->m[0][3] = d;
	this->m[1][0] = e;
	this->m[1][1] = f;
	this->m[1][2] = g;
	this->m[1][3] = h;
	this->m[2][0] = i;
	this->m[2][1] = j;
	this->m[2][2] = k;
	this->m[2][3] = l;
	this->m[3][0] = m;
	this->m[3][1] = n;
	this->m[3][2] = o;
	this->m[3][3] = p;
}

// Destructor
gioMat4::~gioMat4()
{
}