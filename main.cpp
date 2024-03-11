// naming convention: gioVec2

/*
	Next step is to add ImGui to the project
	in order to easily output the text to the screen
	instead of printing it all the time.

	Next, I want to have a console for the engine
	where we can see the output of the engine's log
	without having to have a console window.
*/

// ImGui designs are going to be in a separate file
// called "imgui_designs.h", inside of the "editor" folder, for now

#include <iostream>

// including glad
#include "core/libs/glad/glad.h"

// including types.h
#include "core/types/types.h"

// including OS.h
#include "core/OS/OS.h"

// including filesystem.h
#include "core/filesystem/filesystem.h"

// including shader.h
#include "render/shader.h"

// including draw_quad.h
#include "render/draw_quad.h"

#include <AL/al.h>
#include <AL/alc.h>

 /* This file contains an example for playing a sound buffer. */

#include "core/audio/audio.h"

// including imgui_designs
#include "editor/imgui_designs.h"

// Layout of the application/game
void Init()
{
	// Initialize the game
	// No need for fancy stuff
	gladLoadGL();

	glEnable(GL_BLEND);

	gioImGui::Init();

	std::string* EngineConfigPath = new std::string("EngineConfig.ini");

	// Initializing EngineConfig
	AddSetting("engine-settings-configpath", EngineConfigPath);
	core::InitFileSystem();

	core::LoadEngineConfig();

	quad_object *quad = new quad_object("seamless.png", "shaders/quad.vs", "shaders/quad.fs");

	AddSetting("DebugQuad", quad);
}

void Update()
{
	// Update the game
	gioImGui::Update();
}

void Render()
{
	// Render the game
}

void CleanUp()
{
	// Clean up the game

	gioImGui::CleanUp();
	/* All done. Delete resources, and close down OpenAL. */
	CloseAL();
}

int main(int argc, char** argv)
{
	AddSetting("hello", (void*)"world");
	std::cout << (const char*)EngineConfig["hello"] << std::endl;

	// creating a gioWindow
	gioWindow *window = new gioWindow(800, 600, "Gio Engine");

	AddSetting("OS-window", window);

	// Begin
	Init();

	gioInput *input = new gioInput();

	AddSetting("OS-input", input);

	quad_object *quad = (quad_object*)EngineConfig["DebugQuad"];

	gioVec4* clear_color = (gioVec4*)GetSetting("OpenGL-clear_color");

	// Game loop
	while (!window->ShouldClose())
	{
		glClearColor(clear_color->x * clear_color->w, clear_color->y * clear_color->w, clear_color->z * clear_color->w, clear_color->w);
		glClear(GL_COLOR_BUFFER_BIT);
		
		quad->draw();

		// Update
		Update();

		// Render
		Render();

		if (input->getButton("GioLeft"))
		{
			std::cout << "Left" << std::endl;
		}

		// update the gioInput
		input->Update(window->window);

		// Add the input to the settings
		AddSetting("OS-keyboardinput-string", (void*)gioGetKeyboardInputs(*input));
		AddSetting("OS-mouseinput-string", (void*)gioGetMouseInputs(*input));
		AddSetting("OS-gamepadinput-string", (void*)gioGetGamepadInputs(*input));

		// Swap buffers
		window->SwapBuffers();
		// Poll events
		window->PollEvents();
	}
	CleanUp();
	quad->delete_quad();
	core::UpdateEngineConfig();


	return 0;
}