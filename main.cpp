// naming convention: gioVec2

/*
	Vectors are now classes for better handling
*/


#include <iostream>

// including types.h
#include "core/types/types.h"

// Layout of the application/game
void Init()
{
	// Initialize the game
	// No need for fancy stuff

	// testing the types.h
	// testing the vector2
	gioVec2 vec2(1.0f, 2.0f);
	std::cout << "vec2.x: " << vec2.x << std::endl;
	std::cout << "vec2.y: " << vec2.y << std::endl;

	// testing the vector3
	gioVec3 vec3(1.0f, 2.0f, 3.0f);
	std::cout << "vec3.x: " << vec3.x << std::endl;
	std::cout << "vec3.y: " << vec3.y << std::endl;
	std::cout << "vec3.z: " << vec3.z << std::endl;

	// testing the vector4
	gioVec4 vec4(1.0f, 2.0f, 3.0f, 4.0f);
	std::cout << "vec4.x: " << vec4.x << std::endl;
	std::cout << "vec4.y: " << vec4.y << std::endl;
	std::cout << "vec4.z: " << vec4.z << std::endl;
	std::cout << "vec4.w: " << vec4.w << std::endl;

	/*
		Testing maths with vectors
		--------------------------
	*/

	// doing maths with vector2
	// addition
	std::cout << "Added 1 to vector2" << std::endl;
	std::cout << "x: " << (vec2 + gioVec2One).x << std::endl;
	std::cout << "y: " << (vec2 + gioVec2One).y << std::endl;

	// subtraction
	std::cout << "Subtracted 1 from vector2" << std::endl;
	std::cout << "x: " << (vec2 - gioVec2One).x << std::endl;
	std::cout << "y: " << (vec2 - gioVec2One).y << std::endl;

	// multiplication
	std::cout << "Multiplied vector2 by 2" << std::endl;
	std::cout << "x: " << (vec2 * 2).x << std::endl;
	std::cout << "y: " << (vec2 * 2).y << std::endl;

	// division
	std::cout << "Divided vector2 by 2" << std::endl;
	std::cout << "x: " << (vec2 / 2).x << std::endl;
	std::cout << "y: " << (vec2 / 2).y << std::endl;

	// doing maths with vector3
	// addition
	std::cout << "Added 1 to vector3" << std::endl;
	std::cout << "x: " << (vec3 + gioVec3One).x << std::endl;
	std::cout << "y: " << (vec3 + gioVec3One).y << std::endl;
	std::cout << "z: " << (vec3 + gioVec3One).z << std::endl;

	// subtraction
	std::cout << "Subtracted 1 from vector3" << std::endl;
	std::cout << "x: " << (vec3 - gioVec3One).x << std::endl;
	std::cout << "y: " << (vec3 - gioVec3One).y << std::endl;
	std::cout << "z: " << (vec3 - gioVec3One).z << std::endl;

	// multiplication
	std::cout << "Multiplied vector3 by 2" << std::endl;
	std::cout << "x: " << (vec3 * 2).x << std::endl;
	std::cout << "y: " << (vec3 * 2).y << std::endl;
	std::cout << "z: " << (vec3 * 2).z << std::endl;

	// division
	std::cout << "Divided vector3 by 2" << std::endl;
	std::cout << "x: " << (vec3 / 2).x << std::endl;
	std::cout << "y: " << (vec3 / 2).y << std::endl;
	std::cout << "z: " << (vec3 / 2).z << std::endl;

	// testing the matrix2
	gioMat2 mat2 = { 1.0f, 2.0f, 3.0f, 4.0f };
	std::cout << "mat2[0][0]: " << mat2.m00 << std::endl;
	std::cout << "mat2[0][1]: " << mat2.m01 << std::endl;
	std::cout << "mat2[1][0]: " << mat2.m10 << std::endl;
	std::cout << "mat2[1][1]: " << mat2.m11 << std::endl;

	// testing the matrix3
	gioMat3 mat3 = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f };
	std::cout << "mat3[0][0]: " << mat3.m00 << std::endl;
	std::cout << "mat3[0][1]: " << mat3.m01 << std::endl;
	std::cout << "mat3[0][2]: " << mat3.m02 << std::endl;
	std::cout << "mat3[1][0]: " << mat3.m10 << std::endl;
	std::cout << "mat3[1][1]: " << mat3.m11 << std::endl;
	std::cout << "mat3[1][2]: " << mat3.m12 << std::endl;
	std::cout << "mat3[2][0]: " << mat3.m20 << std::endl;
	std::cout << "mat3[2][1]: " << mat3.m21 << std::endl;
	std::cout << "mat3[2][2]: " << mat3.m22 << std::endl;
	
	// testing the matrix4
	gioMat4 mat4 = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f };
	std::cout << "mat4[0][0]: " << mat4.m00 << std::endl;
	std::cout << "mat4[0][1]: " << mat4.m01 << std::endl;
	std::cout << "mat4[0][2]: " << mat4.m02 << std::endl;
	std::cout << "mat4[0][3]: " << mat4.m03 << std::endl;
	std::cout << "mat4[1][0]: " << mat4.m10 << std::endl;
	std::cout << "mat4[1][1]: " << mat4.m11 << std::endl;
	std::cout << "mat4[1][2]: " << mat4.m12 << std::endl;
	std::cout << "mat4[1][3]: " << mat4.m13 << std::endl;
	std::cout << "mat4[2][0]: " << mat4.m20 << std::endl;
	std::cout << "mat4[2][1]: " << mat4.m21 << std::endl;
	std::cout << "mat4[2][2]: " << mat4.m22 << std::endl;
	std::cout << "mat4[2][3]: " << mat4.m23 << std::endl;
	std::cout << "mat4[3][0]: " << mat4.m30 << std::endl;
	std::cout << "mat4[3][1]: " << mat4.m31 << std::endl;
	std::cout << "mat4[3][2]: " << mat4.m32 << std::endl;
	
	// testing the maths with matrices
	// matrix2 tests

	// multiplication
	std::cout << "Multiplied matrix2 by 2" << std::endl;
	std::cout << "m00: " << (mat2 * 2).m00 << std::endl;
	std::cout << "m01: " << (mat2 * 2).m01 << std::endl;
	std::cout << "m10: " << (mat2 * 2).m10 << std::endl;
	std::cout << "m11: " << (mat2 * 2).m11 << std::endl;

	// division
	std::cout << "Divided matrix2 by 2" << std::endl;
	std::cout << "m00: " << (mat2 / 2).m00 << std::endl;
	std::cout << "m01: " << (mat2 / 2).m01 << std::endl;
	std::cout << "m10: " << (mat2 / 2).m10 << std::endl;
	std::cout << "m11: " << (mat2 / 2).m11 << std::endl;

	// matrix 3 tests
	// multiplication
	std::cout << "Multiplied matrix3 by 2" << std::endl;
	std::cout << "m00: " << (mat3 * 2).m00 << std::endl;
	std::cout << "m01: " << (mat3 * 2).m01 << std::endl;
	std::cout << "m02: " << (mat3 * 2).m02 << std::endl;
	std::cout << "m10: " << (mat3 * 2).m10 << std::endl;
	std::cout << "m11: " << (mat3 * 2).m11 << std::endl;
	std::cout << "m12: " << (mat3 * 2).m12 << std::endl;
	std::cout << "m20: " << (mat3 * 2).m20 << std::endl;
	std::cout << "m21: " << (mat3 * 2).m21 << std::endl;
	std::cout << "m22: " << (mat3 * 2).m22 << std::endl;

	// division
	std::cout << "Divided matrix3 by 2" << std::endl;
	std::cout << "m00: " << (mat3 / 2).m00 << std::endl;
	std::cout << "m01: " << (mat3 / 2).m01 << std::endl;
	std::cout << "m02: " << (mat3 / 2).m02 << std::endl;
	std::cout << "m10: " << (mat3 / 2).m10 << std::endl;
	std::cout << "m11: " << (mat3 / 2).m11 << std::endl;
	std::cout << "m12: " << (mat3 / 2).m12 << std::endl;
	std::cout << "m20: " << (mat3 / 2).m20 << std::endl;
	std::cout << "m21: " << (mat3 / 2).m21 << std::endl;
	std::cout << "m22: " << (mat3 / 2).m22 << std::endl;

	// matrix 4 tests
	// multiplication
	std::cout << "Multiplied matrix4 by 2" << std::endl;
	std::cout << "m00: " << (mat4 * 2).m00 << std::endl;
	std::cout << "m01: " << (mat4 * 2).m01 << std::endl;
	std::cout << "m02: " << (mat4 * 2).m02 << std::endl;
	std::cout << "m03: " << (mat4 * 2).m03 << std::endl;
	std::cout << "m10: " << (mat4 * 2).m10 << std::endl;
	std::cout << "m11: " << (mat4 * 2).m11 << std::endl;
	std::cout << "m12: " << (mat4 * 2).m12 << std::endl;
	std::cout << "m13: " << (mat4 * 2).m13 << std::endl;
	std::cout << "m20: " << (mat4 * 2).m20 << std::endl;
	std::cout << "m21: " << (mat4 * 2).m21 << std::endl;
	std::cout << "m22: " << (mat4 * 2).m22 << std::endl;
	std::cout << "m23: " << (mat4 * 2).m23 << std::endl;
	std::cout << "m30: " << (mat4 * 2).m30 << std::endl;
	std::cout << "m31: " << (mat4 * 2).m31 << std::endl;
	std::cout << "m32: " << (mat4 * 2).m32 << std::endl;
	std::cout << "m33: " << (mat4 * 2).m33 << std::endl;

	// division
	std::cout << "Divided matrix4 by 2" << std::endl;
	std::cout << "m00: " << (mat4 / 2).m00 << std::endl;
	std::cout << "m01: " << (mat4 / 2).m01 << std::endl;
	std::cout << "m02: " << (mat4 / 2).m02 << std::endl;
	std::cout << "m03: " << (mat4 / 2).m03 << std::endl;
	std::cout << "m10: " << (mat4 / 2).m10 << std::endl;
	std::cout << "m11: " << (mat4 / 2).m11 << std::endl;
	std::cout << "m12: " << (mat4 / 2).m12 << std::endl;
	std::cout << "m13: " << (mat4 / 2).m13 << std::endl;
	std::cout << "m20: " << (mat4 / 2).m20 << std::endl;
	std::cout << "m21: " << (mat4 / 2).m21 << std::endl;
	std::cout << "m22: " << (mat4 / 2).m22 << std::endl;
	std::cout << "m23: " << (mat4 / 2).m23 << std::endl;
	std::cout << "m30: " << (mat4 / 2).m30 << std::endl;
	std::cout << "m31: " << (mat4 / 2).m31 << std::endl;
	std::cout << "m32: " << (mat4 / 2).m32 << std::endl;
	std::cout << "m33: " << (mat4 / 2).m33 << std::endl;

	// testing the matrix4 * matrix4
	gioMat4 mat4_3 = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f };
	gioMat4 mat4_4 = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f };
	std::cout << "mat4_3[0][0]: " << (mat4_3 * mat4_4).m00 << std::endl;
	std::cout << "mat4_3[0][1]: " << (mat4_3 * mat4_4).m01 << std::endl;
	std::cout << "mat4_3[0][2]: " << (mat4_3 * mat4_4).m02 << std::endl;
	std::cout << "mat4_3[0][3]: " << (mat4_3 * mat4_4).m03 << std::endl;
	std::cout << "mat4_3[1][0]: " << (mat4_3 * mat4_4).m10 << std::endl;
	std::cout << "mat4_3[1][1]: " << (mat4_3 * mat4_4).m11 << std::endl;
	std::cout << "mat4_3[1][2]: " << (mat4_3 * mat4_4).m12 << std::endl;
	std::cout << "mat4_3[1][3]: " << (mat4_3 * mat4_4).m13 << std::endl;
	std::cout << "mat4_3[2][0]: " << (mat4_3 * mat4_4).m20 << std::endl;
	std::cout << "mat4_3[2][1]: " << (mat4_3 * mat4_4).m21 << std::endl;
	std::cout << "mat4_3[2][2]: " << (mat4_3 * mat4_4).m22 << std::endl;
	std::cout << "mat4_3[2][3]: " << (mat4_3 * mat4_4).m23 << std::endl;
	std::cout << "mat4_3[3][0]: " << (mat4_3 * mat4_4).m30 << std::endl;
	std::cout << "mat4_3[3][1]: " << (mat4_3 * mat4_4).m31 << std::endl;
	std::cout << "mat4_3[3][2]: " << (mat4_3 * mat4_4).m32 << std::endl;
	std::cout << "mat4_3[3][3]: " << (mat4_3 * mat4_4).m33 << std::endl;
}

void Update()
{
	// Update the game
}

void Render()
{
	// Render the game
}

void CleanUp()
{
	// Clean up the game
}

int main()
{
	std::cout << "Hello, World!" << std::endl;

	Init();

	return 0;
}
