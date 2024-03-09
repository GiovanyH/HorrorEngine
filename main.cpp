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

// including imgui_designs
#include "editor/imgui_designs.h"

// Layout of the application/game
void Init()
{
	// Initialize the game
	// No need for fancy stuff
	gladLoadGL();

	gioImGui::Init();
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
}

int main()
{
	AddSetting("hello", (void*)"world");
	std::cout << (const char*)EngineConfig["hello"] << std::endl;

	// creating a gioWindow
	gioWindow *window = new gioWindow(800, 600, "Gio Engine", nullptr, nullptr);

	AddSetting("OS-window", window);

	// Begin
	Init();

	// Game loop
	while (!window->ShouldClose())
	{
		// Update window

		// Update
		Update();

		// Render
		Render();

		// print the gioInput
		gioInput input;
		input.Update(window->window);
		std::cout << gioInputToString(input);

		// Swap buffers
		window->SwapBuffers();
		// Poll events
		window->PollEvents();
	}
	CleanUp();


	return 0;
}