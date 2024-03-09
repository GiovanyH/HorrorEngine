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

// for math functions like sqrt and sin/cos
#include <cmath>
// Including the vectors
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
// Including the matrices
#include "mat2.h"
#include "mat3.h"
#include "mat4.h"