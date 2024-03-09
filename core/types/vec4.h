#pragma once

// Includes
#include <cmath>

// Class definition
class gioVec4
{
	public:
	// Constructors
	gioVec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
	gioVec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	// Operators
	gioVec4 operator+(const gioVec4& v) const { return gioVec4(x + v.x, y + v.y, z + v.z, w + v.w); }
	gioVec4 operator-(const gioVec4& v) const { return gioVec4(x - v.x, y - v.y, z - v.z, w - v.w); }
	gioVec4 operator*(float s) const { return gioVec4(x * s, y * s, z * s, w * s); }
	gioVec4 operator/(float s) const { return gioVec4(x / s, y / s, z / s, w / s); }
	gioVec4& operator+=(const gioVec4& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
	gioVec4& operator-=(const gioVec4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }
	gioVec4& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
	gioVec4& operator/=(float s) { x /= s; y /= s; z /= s; w /= s; return *this; }
	bool operator==(const gioVec4& v) const { return x == v.x && y == v.y && z == v.z && w == v.w; }
	bool operator!=(const gioVec4& v) const { return x != v.x || y != v.y || z != v.z || w != v.w; }

	// Methods
	float Length() const { return sqrtf(x * x + y * y + z * z + w * w); }
	float LengthSquared() const { return x * x + y * y + z * z + w * w; }
	gioVec4 Normalized() const { return *this / Length(); }
	void Normalize() { *this /= Length(); }
	float Dot(const gioVec4& v) const { return x * v.x + y * v.y + z * v.z + w * v.w; }

	static gioVec4 Lerp(const gioVec4& a, const gioVec4& b, float t) { return a + (b - a) * t; }
	static gioVec4 Rotate(const gioVec4& v, const gioVec4& axis, float angle)
	{
		float s = sinf(angle);
		float c = cosf(angle);
		float t = 1.0f - c;
		gioVec4 r;
		r.x = v.x * (t * axis.x * axis.x + c) + v.y * (t * axis.x * axis.y - s * axis.z) + v.z * (t * axis.x * axis.z + s * axis.y);
		r.y = v.x * (t * axis.x * axis.y + s * axis.z) + v.y * (t * axis.y * axis.y + c) + v.z * (t * axis.y * axis.z - s * axis.x);
		r.z = v.x * (t * axis.x * axis.z - s * axis.y) + v.y * (t * axis.y * axis.z + s * axis.x) + v.z * (t * axis.z * axis.z + c);
		r.w = v.w;
		return r;
	}

	// get a struct with the values
	struct { float x; float y; float z; float w; } GetStruct() { return { x, y, z, w }; };
	
	// Members
	float x, y, z, w;
};

// Constants
const gioVec4 gioVec4Zero(0.0f, 0.0f, 0.0f, 0.0f);
const gioVec4 gioVec4One(1.0f, 1.0f, 1.0f, 1.0f);
const gioVec4 gioVec4UnitX(1.0f, 0.0f, 0.0f, 0.0f);
const gioVec4 gioVec4UnitY(0.0f, 1.0f, 0.0f, 0.0f);
const gioVec4 gioVec4UnitZ(0.0f, 0.0f, 1.0f, 0.0f);
const gioVec4 gioVec4UnitW(0.0f, 0.0f, 0.0f, 1.0f);
const gioVec4 gioVec4NegUnitX(-1.0f, 0.0f, 0.0f, 0.0f);
const gioVec4 gioVec4NegUnitY(0.0f, -1.0f, 0.0f, 0.0f);
const gioVec4 gioVec4NegUnitZ(0.0f, 0.0f, -1.0f, 0.0f);
const gioVec4 gioVec4NegUnitW(0.0f, 0.0f, 0.0f, -1.0f);
const gioVec4 gioVec4Infinity(INFINITY, INFINITY, INFINITY, INFINITY);
const gioVec4 gioVec4NegInfinity(-INFINITY, -INFINITY, -INFINITY, -INFINITY);
const gioVec4 gioVec4NaN(NAN, NAN, NAN, NAN);
const gioVec4 gioVec4NegNaN(-NAN, -NAN, -NAN, -NAN);
const gioVec4 gioVec4Pi(3.14159265358979323846f, 3.14159265358979323846f, 3.14159265358979323846f, 3.14159265358979323846f);