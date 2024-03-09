#pragma once

// Includes
#include <cmath>

// Class definition
class gioVec3
{
	public:
	// Constructors
	gioVec3() : x(0.0f), y(0.0f), z(0.0f) {}
	gioVec3(float x, float y, float z) : x(x), y(y), z(z) {}

	// Operators
	gioVec3 operator+(const gioVec3& v) const { return gioVec3(x + v.x, y + v.y, z + v.z); }
	gioVec3 operator-(const gioVec3& v) const { return gioVec3(x - v.x, y - v.y, z - v.z); }
	gioVec3 operator*(float s) const { return gioVec3(x * s, y * s, z * s); }
	gioVec3 operator/(float s) const { return gioVec3(x / s, y / s, z / s); }
	gioVec3& operator+=(const gioVec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
	gioVec3& operator-=(const gioVec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
	gioVec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
	gioVec3& operator/=(float s) { x /= s; y /= s; z /= s; return *this; }
	bool operator==(const gioVec3& v) const { return x == v.x && y == v.y && z == v.z; }
	bool operator!=(const gioVec3& v) const { return x != v.x || y != v.y || z != v.z; }

	// Methods
	float Length() const { return sqrtf(x * x + y * y + z * z); }
	float LengthSquared() const { return x * x + y * y + z * z; }
	gioVec3 Normalized() const { return *this / Length(); }
	void Normalize() { *this /= Length(); }
	float Dot(const gioVec3& v) const { return x * v.x + y * v.y + z * v.z; }
	gioVec3 Cross(const gioVec3& v) const { return gioVec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }

	static gioVec3 Lerp(const gioVec3& a, const gioVec3& b, float t) { return a + (b - a) * t; }
	static gioVec3 Rotate(const gioVec3& v, const gioVec3& axis, float angle)
	{
		float s = sinf(angle);
		float c = cosf(angle);
		float t = 1.0f - c;
		gioVec3 r;
		r.x = v.x * (t * axis.x * axis.x + c) + v.y * (t * axis.x * axis.y - s * axis.z) + v.z * (t * axis.x * axis.z + s * axis.y);
		r.y = v.x * (t * axis.x * axis.y + s * axis.z) + v.y * (t * axis.y * axis.y + c) + v.z * (t * axis.y * axis.z - s * axis.x);
		r.z = v.x * (t * axis.x * axis.z - s * axis.y) + v.y * (t * axis.y * axis.z + s * axis.x) + v.z * (t * axis.z * axis.z + c);
		return r;
	}

	// Members
	float x, y, z;
};

// Constants
const gioVec3 gioVec3Zero(0.0f, 0.0f, 0.0f);
const gioVec3 gioVec3One(1.0f, 1.0f, 1.0f);
const gioVec3 gioVec3UnitX(1.0f, 0.0f, 0.0f);
const gioVec3 gioVec3UnitY(0.0f, 1.0f, 0.0f);
const gioVec3 gioVec3UnitZ(0.0f, 0.0f, 1.0f);
const gioVec3 gioVec3NegUnitX(-1.0f, 0.0f, 0.0f);
const gioVec3 gioVec3NegUnitY(0.0f, -1.0f, 0.0f);
const gioVec3 gioVec3NegUnitZ(0.0f, 0.0f, -1.0f);
const gioVec3 gioVec3Infinity(INFINITY, INFINITY, INFINITY);
const gioVec3 gioVec3NegInfinity(-INFINITY, -INFINITY, -INFINITY);
const gioVec3 gioVec3NaN(NAN, NAN, NAN);
const gioVec3 gioVec3NegNaN(-NAN, -NAN, -NAN);
const gioVec3 gioVec3Pi(3.14159265358979323846f, 3.14159265358979323846f, 3.14159265358979323846f);
const gioVec3 gioVec3NegPi(-3.14159265358979323846f, -3.14159265358979323846f, -3.14159265358979323846f);