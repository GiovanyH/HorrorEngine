#pragma once

// Includes
#include <cmath>

// Class definition
class gioVec2
{
	public:
	// Constructors
	gioVec2() : x(0.0f), y(0.0f) {}
	gioVec2(float x, float y) : x(x), y(y) {}

	// Operators
	gioVec2 operator+(const gioVec2& v) const { return gioVec2(x + v.x, y + v.y); }
	gioVec2 operator-(const gioVec2& v) const { return gioVec2(x - v.x, y - v.y); }
	gioVec2 operator*(float s) const { return gioVec2(x * s, y * s); }
	gioVec2 operator/(float s) const { return gioVec2(x / s, y / s); }
	gioVec2& operator+=(const gioVec2& v) { x += v.x; y += v.y; return *this; }
	gioVec2& operator-=(const gioVec2& v) { x -= v.x; y -= v.y; return *this; }
	gioVec2& operator*=(float s) { x *= s; y *= s; return *this; }
	gioVec2& operator/=(float s) { x /= s; y /= s; return *this; }
	bool operator==(const gioVec2& v) const { return x == v.x && y == v.y; }
	bool operator!=(const gioVec2& v) const { return x != v.x || y != v.y; }

	// Methods
	float Length() const { return sqrtf(x * x + y * y); }
	float LengthSquared() const { return x * x + y * y; }
	gioVec2 Normalized() const { return *this / Length(); }
	void Normalize() { *this /= Length(); }
	float Dot(const gioVec2& v) const { return x * v.x + y * v.y; }

	static gioVec2 Lerp(const gioVec2& a, const gioVec2& b, float t) { return a + (b - a) * t; }
	static gioVec2 Rotate(const gioVec2& v, float angle) { return gioVec2(v.x * cosf(angle) - v.y * sinf(angle), v.x * sinf(angle) + v.y * cosf(angle)); }

	// Members
	float x, y;
};

// Constants
const gioVec2 gioVec2Zero(0.0f, 0.0f);
const gioVec2 gioVec2One(1.0f, 1.0f);
const gioVec2 gioVec2UnitX(1.0f, 0.0f);
const gioVec2 gioVec2UnitY(0.0f, 1.0f);
const gioVec2 gioVec2NegUnitX(-1.0f, 0.0f);
const gioVec2 gioVec2NegUnitY(0.0f, -1.0f);
const gioVec2 gioVec2Infinity(INFINITY, INFINITY);
const gioVec2 gioVec2NegInfinity(-INFINITY, -INFINITY);
const gioVec2 gioVec2NaN(NAN, NAN);
const gioVec2 gioVec2NegNaN(-NAN, -NAN);
const gioVec2 gioVec2Pi(3.14159265358979323846f, 3.14159265358979323846f);
const gioVec2 gioVec2NegPi(-3.14159265358979323846f, -3.14159265358979323846f);