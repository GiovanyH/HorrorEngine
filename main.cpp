// naming convention: gioVec2

// ImGui designs are in a separate file
// called "imgui_designs.h", inside of the "editor" folder, for now

#include <iostream>


/* Core */
// ---------------------
#include "core/types/types.h"

/* OpenGL stuff */
#include "core/libs/glad/glad.h"

/* OS folder is where Input.h, Window.h and the variable EngineConfig are located. */
#include "core/OS/OS.h"

/* My own filesystem so that it has my own naming convention and I can edit it without having to edit the whole code */
#include "core/filesystem/filesystem.h"

/* Render */
// ---------------------
#include "render/shader.h"

/* Used to draw 2D Sprites */
#include "render/draw_quad.h"


/* Audio */
// ---------------------
#include <AL/al.h>
#include <AL/alc.h>

 /* This file contains an example for playing a sound buffer. */
#include "core/audio/audio.h"

/* Editor */
// ---------------------
#include "editor/imgui_designs.h"

// Layout of the application/game
// Init()
// Update()
// CleanUp()

void Init()
{
	// Initialize OpenGL
	gladLoadGL();
	// Initialize ImGui
	gioImGui::Init();
	// Initialize EngineConfig, TODO: EngineConfig.Init() something like this
	std::string* EngineConfigPath = new std::string("EngineConfig.ini");
	AddSetting("engine-settings-configpath", EngineConfigPath);
	core::InitFileSystem();
	core::LoadEngineConfig();

	// Making an entity
	quad_object *quad = new quad_object("PlayerIdle.png", "shaders/quad.vs", "shaders/quad.fs", gioVec2(0.0f, 0.0f), gioVec2(10.0f, 1.0f));
	AddSetting("DebugQuad", quad);
	gioVec2 *frame = new gioVec2(0.0f, 0.0f);
	AddSetting("frame", frame);
}

void Update()
{
	// Update ImGui
	gioImGui::Update();
}

void Render()
{
	// Render the game

}

void CleanUp()
{
	// Clean up ImGui
	gioImGui::CleanUp();
	/* close down OpenAL */
	CloseAL();
}

int main(int argc, char** argv)
{
	// Testing EngineConfig
	AddSetting("hello", (void*)"world");
	std::cout << (const char*)EngineConfig["hello"] << std::endl;

	// creating a gioWindow
	gioWindow *window = new gioWindow(800, 600, "Gio Engine");
	AddSetting("OS-window", window);

	// Begin
	Init();

	// Input stuff
	gioInput *input = new gioInput();
	AddSetting("OS-input", input);

	// Getting the entity
	quad_object *quad = (quad_object*)EngineConfig["DebugQuad"];

	// Getting OpenGL clear_color
	gioVec4* clear_color = (gioVec4*)GetSetting("OpenGL-clear_color");

	// Game loop
	while (!window->ShouldClose())
	{
		glClearColor(clear_color->x * clear_color->w, clear_color->y * clear_color->w, clear_color->z * clear_color->w, clear_color->w);
		glClear(GL_COLOR_BUFFER_BIT);

		quad->draw(*(float*)GetSetting("deltaTime"));

		// Render
		Render();

		// Update
		Update();

		// TODO: delete this comment later
		// update the gioInput
		//input->Update(window->window);
		// gioInput is now passed to window->PollEvents()

		// Add the input to the settings
		AddSetting("OS-keyboardinput-string", (void*)gioGetKeyboardInputs(*input));
		AddSetting("OS-mouseinput-string", (void*)gioGetMouseInputs(*input));
		AddSetting("OS-gamepadinput-string", (void*)gioGetGamepadInputs(*input));

		// Swap buffers
		window->SwapBuffers();
		// Poll events
		window->PollEvents(input);
	}
	CleanUp();
	quad->delete_quad();
	core::UpdateEngineConfig();


	return 0;
}