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

/*
	Adding some input functions to EngineConfig
	to later be able to map a string to a key, mouse button, gamepad button, etc.

	Just like most game engines nowadays.
*/

// Add keyboard input
void AddKeyboardInput(std::string name, int *key)
{
	EngineConfig["OS-keyboard" + name] = (void*)key;
}

// Get keyboard input
int* GetKeyboardInput(std::string name)
{
	return (int*)EngineConfig["OS-keyboard" + name];
}

// Add mouse input
void AddMouseInput(std::string name, int* button)
{
	EngineConfig["OS-mouse" + name] = (void*)button;
}

// Get mouse input
int* GetMouseInput(std::string name)
{
	return (int*)EngineConfig["OS-mouse" + name];
}

// Add gamepad input
void AddGamepadInput(std::string name, int* button)
{
	EngineConfig["OS-gamepad" + name] = (void*)button;
}

// Get gamepad input
int* GetGamepadInput(std::string name)
{
	return (int*)EngineConfig["OS-gamepad" + name];
}

// Add gamepad axis
void AddGamepadAxis(std::string name, gioVec2* axis)
{
	EngineConfig["OS-gamepad" + name] = (void*)axis;
}

// Get gamepad axis
gioVec2* GetGamepadAxis(std::string name)
{
	return (gioVec2*)EngineConfig["OS-gamepad" + name];
}

// Add gamepad trigger
void AddGamepadTrigger(std::string name, gioVec2* trigger)
{
	EngineConfig["OS-gamepad" + name] = (void*)trigger;
}

// Get gamepad trigger
gioVec2* GetGamepadTrigger(std::string name)
{
	return (gioVec2*)EngineConfig["OS-gamepad" + name];
}

int gioInput::getButton(const char *input_string)
{
	if (GetKeyboardInput(input_string) == nullptr) return 0;
	return *GetKeyboardInput(input_string) == this->key || *GetGamepadInput(input_string) == this->gamepadButton;
}