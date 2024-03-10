#pragma once

/*
	The OS folder is going to be where Input.h and Window.h are located.
	These files are going to be the ones that handle the input and windowing of the application.

	I want Input.h to have my own naming convention instead of the one that GLFW uses.
	For example, I want to use the name "gioKey" instead of "GLFW_KEY".

	I also want that file to have inputs for the gamepad / controller.
	with a weight for the joysticks and triggers.

	Window.h is going to be the file that handles the windowing of the application.
	For example, the window's size, the window's title, the window's icon, etc.

	It's also going to have my own naming convention for the window's functions.
	For example, I want to use the name "gioWindow" instead of "GLFWwindow".
*/

/*
* Usage:
* gioInput input = gioInputFromGLFW(window);
* std::cout << gioInputToString(input);
*/

#include <iostream>
#include <string>

// Including GLFW
#ifndef GLFW_INCLUDED
#include <GLFW/glfw3.h>
#define GLFW_INCLUDED
#endif

// Input class
class gioInput
{
private:
	void gioInputFromGLFW(GLFWwindow* window);
public:
	// Keyboard
	int key;
	int action;
	int mods;

	// Mouse
	double x;
	double y;
	double dx;
	double dy;
	double scrollPosY;
	double scrollY;
	int button;
	int buttonAction;
	int buttonMods;

	// Gamepad
	int gamepad;
	int gamepadButton;
	int gamepadButtonAction;
	int gamepadButtonMods;
	gioVec2 gamepadLeftStickAxis;
	gioVec2 gamepadRightStickAxis;
	
	gioVec2 gamepadTrigger;

	// Update
	void Update(GLFWwindow* window)
	{
		gioInputFromGLFW(window);
	}
};

double old_yScrollPos = 0;
double yScrollPos = 0;

std::string gioInputToString(gioInput input);

// glfwGetScrollOffsets doesn't exist in GLFW, so I'm going to create it
void glfwGetScrollOffsets(GLFWwindow* window, double* x, double* y)
{
	*x = 0;
	*y = 0;
}

void updateScroll(double value)
{
	yScrollPos += value;
}

// Convert the GLFW input to the input / every key
void gioInput::gioInputFromGLFW(GLFWwindow* window)
{
	// Keyboard
	key = -1;
	action = -1;
	mods = -1;

	// Mouse
	x = -1;
	y = -1;
	dx = -1;
	dy = -1;
	scrollY = 0;
	button = -1;
	buttonAction = -1;
	buttonMods = -1;

	// Gamepad
	gamepad = -1;
	gamepadButton = -1;
	gamepadButtonAction = -1;
	gamepadButtonMods = -1;
	gamepadLeftStickAxis = gioVec2(-1, -1);
	gamepadRightStickAxis = gioVec2(-1, -1);
	gamepadTrigger = gioVec2(-1, -1);

	// store all input from keyboard to keys, using key scancode
	for (int i = 0; i < 348; i++)
	{
		if (glfwGetKey(window, i) == GLFW_PRESS)
		{
			key = i;
			action = GLFW_PRESS;
			mods = glfwGetKey(window, i);
		}
	}

	// Mouse
	glfwGetCursorPos(window, &x, &y);
	glfwGetCursorPos(window, &dx, &dy);

	// scroll Callback
	glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset)
	{
			updateScroll(yoffset);
	});

	if (yScrollPos != old_yScrollPos)
	{
		scrollY = yScrollPos - old_yScrollPos;
		old_yScrollPos = yScrollPos;
	}


	for (int i = 0; i < 8; i++)
	{
		if (glfwGetMouseButton(window, i) == GLFW_PRESS)
		{
			button = i;
			buttonAction = GLFW_PRESS;
			buttonMods = glfwGetMouseButton(window, i);
		}
	}

	int count;
	// Gamepad
	for (int i = 0; i < 16; i++)
	{
		if (glfwJoystickPresent(i))
		{
			gamepad = i;
			const float* leftjoy = glfwGetJoystickAxes(i, &count);
			for (int j = 0; j < count; j++)
			{
				if (j == 0)
				{
					gamepadLeftStickAxis.x = leftjoy[j];
				}
				else if (j == 1)
				{
					gamepadLeftStickAxis.y = leftjoy[j];
				}
			}

			const unsigned char* buttons = glfwGetJoystickButtons(i, &count);

			for (int j = 0; j < count; j++)
			{
				if (buttons[j] == GLFW_PRESS)
				{
					gamepadButton = j;
					gamepadButtonAction = GLFW_PRESS;
					gamepadButtonMods = buttons[j];
				}
			}

			const float* rightjoy = glfwGetJoystickAxes(i, &count);

			for (int j = 0; j < count; j++)
			{
				if (j == 2)
				{
					gamepadRightStickAxis.x = rightjoy[j];
				}
				else if (j == 3)
				{
					gamepadRightStickAxis.y = rightjoy[j];
				}
			}

			const float* triggers = glfwGetJoystickAxes(i, &count);

			for (int j = 0; j < count; j++)
			{
				if (j == 4)
				{
					gamepadTrigger.x = triggers[j];
				}
				else if (j == 5)
				{
					gamepadTrigger.y = triggers[j];
				}
			}
		}
	}
}

const char *gioGetKeyboardInputs(gioInput input)
{
	std::string *result = new std::string("");

	// Keyboard
	*result += "Key: " + std::to_string(input.key) + "\n";
	*result += "Action: " + std::to_string(input.action) + "\n";
	*result += "Mods: " + std::to_string(input.mods) + "\n";

	return (*result).c_str();
}

const char* gioGetMouseInputs(gioInput input)
{
	std::string *result = new std::string("");

	// Mouse
	*result += "X: " + std::to_string(input.x) + "\n";
	*result += "Y: " + std::to_string(input.y) + "\n";
	*result += "ScrollY: " + std::to_string(input.scrollY) + "\n";
	*result += "Button: " + std::to_string(input.button) + "\n";

	return (*result).c_str();
}

const char* gioGetGamepadInputs(gioInput input)
{
	std::string *result = new std::string("");

	// Gamepad
	*result += "GamepadButton: " + std::to_string(input.gamepadButton) + "\n";

	// Printing the gioVec2 axis x and y
	*result += "GamepadLeftAxis: " + std::to_string(input.gamepadLeftStickAxis.x) + ", " + std::to_string(input.gamepadLeftStickAxis.y) + "\n";
	*result += "GamepadRightAxis: " + std::to_string(input.gamepadRightStickAxis.x) + ", " + std::to_string(input.gamepadRightStickAxis.y) + "\n";

	// Printing the gioVec2 trigger x and y
	*result += "GamepadTrigger: " + std::to_string(input.gamepadTrigger.x) + ", " + std::to_string(input.gamepadTrigger.y) + "\n";

	return (*result).c_str();
}

// Convert the input to a string
std::string gioSaveInputs(gioInput input)
{
	std::string result = "";

	// Keyboard
	result += "Key: " + std::to_string(input.key) + "\n";

	result += "\n\n";

	// Mouse
	result += "X: " + std::to_string(input.x) + "\n";
	result += "Y: " + std::to_string(input.y) + "\n";
	result += "ScrollY: " + std::to_string(input.scrollY) + "\n";
	result += "Button: " + std::to_string(input.button) + "\n";

	result += "\n\n";

	// Gamepad
	result += "Gamepad: \n\n";
	result += "Gamepad: " + std::to_string(input.gamepad) + "\n";
	result += "GamepadButton: " + std::to_string(input.gamepadButton) + "\n";

	// Printing the gioVec2 axis x and y
	result += "GamepadLeftAxis: " + std::to_string(input.gamepadLeftStickAxis.x) + ", " + std::to_string(input.gamepadLeftStickAxis.y) + "\n";
	result += "GamepadRightAxis: " + std::to_string(input.gamepadRightStickAxis.x) + ", " + std::to_string(input.gamepadRightStickAxis.y) + "\n";

	// Printing the gioVec2 trigger x and y
	result += "GamepadTrigger: " + std::to_string(input.gamepadTrigger.x) + ", " + std::to_string(input.gamepadTrigger.y) + "\n";

	result += "\n\n";

	return result;
}