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

#include "editor/sprite.h"


/* Audio */
// ---------------------
#include <AL/al.h>
#include <AL/alc.h>

#include <glfw/glfw3.h>

 /* This file contains an example for playing a sound buffer. */
#include "core/audio/audio.h"

/* Editor */
// ---------------------
#include "editor/imgui_designs.h"

// Layout of the application/game
// Init()
// Update()
// CleanUp()

// Debug some state
// Animation Data Structure:
// x - start framex
// y - end framex
// z - start framey
// w - end framey
gioVec4 idle_state = gioVec4(0.0f, 0.0f, 5.0f, 5.0f);

std::vector<Sprite*> sprites;

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

	Sprite* sprite = new Sprite("PlayerIdle.png", gioVec2(8.0f, 8.0f), idle_state);
	Sprite* sprite2 = new Sprite("PlayerRun.png", gioVec2(8.0f, 1.0f), idle_state);
	sprites.push_back(sprite);
	sprites.push_back(sprite2);
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

	// Getting OpenGL clear_color
	gioVec4* clear_color = (gioVec4*)GetSetting("OpenGL-clear_color");

	// Game loop
	while (!window->ShouldClose())
	{
		glClearColor(clear_color->x * clear_color->w, clear_color->y * clear_color->w, clear_color->z * clear_color->w, clear_color->w);
		glClear(GL_COLOR_BUFFER_BIT);

		// Update all quads
		for (int i = 0; i < sprites.size(); i++) {
			sprites[i]->draw();
		}

		Sprite *sprite = sprites[0];

		// Render
		Render();

		// Update
		Update();

		if (GetKeyboardInput("GioLeft") == input->key) {
			sprite->position.x -= 1 * (*(float*)GetSetting("deltaTime"));
			sprite->change_state(1, gioVec4(0.0f, 5.0f, 1.0f, 1.0f));
		}
		else if (GetKeyboardInput("GioRight") == input->key) {
			sprite->position.x += 1 * (*(float*)GetSetting("deltaTime"));
			sprite->change_state(2, gioVec4(0.0f, 5.0f, 2.0f, 2.0f));
		}
		else if (GetKeyboardInput("GioUp") == input->key) {
			sprite->position.y += 1 * (*(float*)GetSetting("deltaTime"));
			sprite->change_state(3, gioVec4(0.0f, 5.0f, 3.0f, 3.0f));
		}
		else if (GetKeyboardInput("GioDown") == input->key) {
			sprite->position.y -= 1 * (*(float*)GetSetting("deltaTime"));
			sprite->change_state(4, gioVec4(0.0f, 5.0f, 4.0f, 4.0f));
		}
		else {
			sprite->change_state(5, gioVec4(0.0f, 0.0f, sprite->animationData.z + 4.0f, sprite->animationData.w + 4.0f));
		}

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
	core::UpdateEngineConfig();


	return 0;
}