// naming convention: gioVec2

/*
	Vectors are now classes for better handling
*/


#include <iostream>

// including types.h
#include "core/types/types.h"

// including OS.h
#include "core/OS/OS.h"

// Layout of the application/game
void Init()
{
	// Initialize the game
	// No need for fancy stuff

	// GLFW stuff
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

	// Begin
	Init();

	// creating a gioWindow
	gioWindow window(800, 600, "Gio Engine", nullptr, nullptr);

	// Game loop
	while (!window.ShouldClose())
	{
		// Update window

		// Update
		Update();

		// Render
		Render();

		// print the gioInput
		gioInput input;
		input.Update(window.window);
		std::cout << gioInputToString(input);

		// Swap buffers
		window.SwapBuffers();
		// Poll events
		window.PollEvents();
	}
	CleanUp();


	return 0;
}