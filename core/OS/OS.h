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
	Including both Input.h and Window.h
*/

#include "input.h"
#include "window.h"

#include <map>
#include <string>

/*
	Made this EngineConfig to be able to easily add settings to the engine
	without making it them global variables.
*/

std::map<std::string, void*> EngineConfig;

// add settings to EngineConfig
void AddSetting(std::string name, void* value)
{
	EngineConfig[name] = value;
}

// get settings from EngineConfig
void* GetSetting(std::string name)
{
	return EngineConfig[name];
}