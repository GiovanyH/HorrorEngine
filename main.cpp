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
	gioMat2 mat2(1.0f, 2.0f, 3.0f, 4.0f);
	std::cout << "mat2[0][0]: " << mat2.m[0][0] << std::endl;
	std::cout << "mat2[0][1]: " << mat2.m[0][1] << std::endl;
	std::cout << "mat2[1][0]: " << mat2.m[1][0] << std::endl;
	std::cout << "mat2[1][1]: " << mat2.m[1][1] << std::endl;
	
	// testing the matrix3
	gioMat3 mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
	std::cout << "mat3[0][0]: " << mat3.m[0][0] << std::endl;
	std::cout << "mat3[0][1]: " << mat3.m[0][1] << std::endl;
	std::cout << "mat3[0][2]: " << mat3.m[0][2] << std::endl;
	std::cout << "mat3[1][0]: " << mat3.m[1][0] << std::endl;
	std::cout << "mat3[1][1]: " << mat3.m[1][1] << std::endl;
	std::cout << "mat3[1][2]: " << mat3.m[1][2] << std::endl;
	std::cout << "mat3[2][0]: " << mat3.m[2][0] << std::endl;
	std::cout << "mat3[2][1]: " << mat3.m[2][1] << std::endl;
	std::cout << "mat3[2][2]: " << mat3.m[2][2] << std::endl;

	// testing the matrix4
	gioMat4 mat4(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
	std::cout << "mat4[0][0]: " << mat4.m[0][0] << std::endl;
	std::cout << "mat4[0][1]: " << mat4.m[0][1] << std::endl;
	std::cout << "mat4[0][2]: " << mat4.m[0][2] << std::endl;
	std::cout << "mat4[0][3]: " << mat4.m[0][3] << std::endl;
	std::cout << "mat4[1][0]: " << mat4.m[1][0] << std::endl;
	std::cout << "mat4[1][1]: " << mat4.m[1][1] << std::endl;
	std::cout << "mat4[1][2]: " << mat4.m[1][2] << std::endl;
	std::cout << "mat4[1][3]: " << mat4.m[1][3] << std::endl;
	std::cout << "mat4[2][0]: " << mat4.m[2][0] << std::endl;
	std::cout << "mat4[2][1]: " << mat4.m[2][1] << std::endl;
	std::cout << "mat4[2][2]: " << mat4.m[2][2] << std::endl;
	std::cout << "mat4[2][3]: " << mat4.m[2][3] << std::endl;
	std::cout << "mat4[3][0]: " << mat4.m[3][0] << std::endl;
	std::cout << "mat4[3][1]: " << mat4.m[3][1] << std::endl;
	std::cout << "mat4[3][2]: " << mat4.m[3][2] << std::endl;
	std::cout << "mat4[3][3]: " << mat4.m[3][3] << std::endl;
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
