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

#include <iostream>

// Including GLFW
#ifndef GLFW_INCLUDED
#include <GLFW/glfw3.h>
#define GLFW_INCLUDED
#endif

// Window class
class gioWindow
{
public:
	// Window's context
	GLFWwindow* window;
private:
	// Window's user pointer
	void* pointer;

	// Window's monitor
	GLFWmonitor* monitor;

	// Window's attributes
	GLFWvidmode* attributes;

	// Window's focus
	int focus;

	// Window's iconify
	int iconify;

	// Window's maximize
	int maximize;

	// Window's hover
	int hover;

	// Window's visible
	int visible;

	// Window's resizable
	int resizable;

	// Window's decorated
	int decorated;

	// Window's floating
	int floating;

public:
	// Constructors
	gioWindow();
	gioWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	gioWindow(int width, int height, const char* title);

	// Destructor
	~gioWindow();

	// Set the window's size
	void SetWindowSize(int width, int height);

	// Set the window's title
	void SetWindowTitle(const char* title);

	// Set the window's icon
	void SetWindowIcon(int count, const GLFWimage* images);

	// Set the window's position
	void SetWindowPosition(int x, int y);

	// Set the window's size limits
	void SetWindowSizeLimits(int minWidth, int minHeight, int maxWidth, int maxHeight);

	// Set the window's aspect ratio
	void SetWindowAspectRatio(int numer, int denom);

	// Set the window's user pointer
	void SetWindowUserPointer(void* pointer);

	// Get the window's user pointer
	void* GetWindowUserPointer();

	// Set the window's monitor
	void SetWindowMonitor(GLFWmonitor* monitor, int x, int y, int width, int height, int refreshRate);

	// Get the window's monitor
	GLFWmonitor* GetWindowMonitor();

	// Get the window's attributes
	const GLFWvidmode* GetWindowAttributes();

	// Set the window's context
	void SetWindowContext(GLFWwindow* window);

	// Get the window's context
	GLFWwindow* GetWindowContext();

	// Set the window's focus
	void SetWindowFocus();

	// Get the window's focus
	int GetWindowFocus();

	// Set the window's iconify
	void SetWindowIconify();

	// Get the window's iconify
	int GetWindowIconify();

	// Set the window's maximize
	void SetWindowMaximize();

	// Get the window's maximize
	int GetWindowMaximize();

	// Set the window's hover
	void SetWindowHover();

	// Get the window's hover
	int GetWindowHover();

	// Set the window's visible
	void SetWindowVisible();

	// Get the window's visible
	int GetWindowVisible();

	// Set the window's resizable
	void SetWindowResizable();

	// Get the window's resizable
	int GetWindowResizable();

	// Set the window's decorated
	void SetWindowDecorated();

	// Get the window's decorated
	int GetWindowDecorated();

	// Set the window's floating
	void SetWindowFloating();

	// Get the window's floating
	int GetWindowFloating();

	// window should close
	int ShouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	// Swap buffers
	void SwapBuffers()
	{
		glfwSwapBuffers(window);
	}

	// Poll events
	void PollEvents(gioInput *input)
	{
		input->Update(this->window);
		glfwPollEvents();
	}

	// Debug print
	void DebugPrint()
	{
		std::cout << "Window's focus: " << focus << std::endl;
		std::cout << "Window's iconify: " << iconify << std::endl;
		std::cout << "Window's maximize: " << maximize << std::endl;
		std::cout << "Window's hover: " << hover << std::endl;
		std::cout << "Window's visible: " << visible << std::endl;
		std::cout << "Window's resizable: " << resizable << std::endl;
		std::cout << "Window's decorated: " << decorated << std::endl;
		std::cout << "Window's floating: " << floating << std::endl;
	}
};

// Window constructors
gioWindow::gioWindow()
{
	// initializing variables
	focus = 0;
	iconify = 0;
	maximize = 0;
	hover = 0;
	visible = 0;
	resizable = 0;
	decorated = 0;
	floating = 0;

	// initializing the pointers
	window = nullptr;
	pointer = nullptr;
	monitor = nullptr;
	attributes = nullptr;

	// Initialize GLFW
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
	}
}

gioWindow::gioWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	// initializing variables
	focus = 0;
	iconify = 0;
	maximize = 0;
	hover = 0;
	visible = 0;
	resizable = 0;
	decorated = 0;
	floating = 0;

	// initializing the pointers
	window = nullptr;
	pointer = nullptr;
	this->monitor = nullptr;
	attributes = nullptr;

	// Initialize GLFW
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create the window
	window = glfwCreateWindow(width, height, title, monitor, share);

	// Set the window's user pointer
	glfwSetWindowUserPointer(window, pointer);

	// Set the window's monitor
	glfwSetWindowMonitor(window, monitor, 0, 0, width, height, 60);

	// Set the window's context
	glfwMakeContextCurrent(window);
}

gioWindow::gioWindow(int width, int height, const char* title)
{
	// initializing variables
	focus = 0;
	iconify = 0;
	maximize = 0;
	hover = 0;
	visible = 0;
	resizable = 0;
	decorated = 0;
	floating = 0;

	// initializing the pointers
	pointer = nullptr;
	this->monitor = nullptr;
	attributes = nullptr;

	// Initialize GLFW
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Create the window
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	// Set the window's context
	glfwMakeContextCurrent(window);
}

// Window destructor -> Terminate GLFW
gioWindow::~gioWindow()
{
	// Terminate GLFW
	glfwTerminate();
}

// Set the window's size
void gioWindow::SetWindowSize(int width, int height)
{
	// Set the window's size
	glfwSetWindowSize(window, width, height);
}

// Set the window's title
void gioWindow::SetWindowTitle(const char* title)
{
	// Set the window's title
	glfwSetWindowTitle(window, title);
}

// Set the window's icon
void gioWindow::SetWindowIcon(int count, const GLFWimage* images)
{
	// Set the window's icon
	glfwSetWindowIcon(window, count, images);
}

// Set the window's position
void gioWindow::SetWindowPosition(int x, int y)
{
	// Set the window's position
	glfwSetWindowPos(window, x, y);
}

// Set the window's size limits
void gioWindow::SetWindowSizeLimits(int minWidth, int minHeight, int maxWidth, int maxHeight)
{
	// Set the window's size limits
	glfwSetWindowSizeLimits(window, minWidth, minHeight, maxWidth, maxHeight);
}

// Set the window's aspect ratio
void gioWindow::SetWindowAspectRatio(int numer, int denom)
{
	// Set the window's aspect ratio
	glfwSetWindowAspectRatio(window, numer, denom);
}

// Set the window's user pointer
void gioWindow::SetWindowUserPointer(void* pointer)
{
	// Set the window's user pointer
	glfwSetWindowUserPointer(window, pointer);
}

// Get the window's user pointer
void* gioWindow::GetWindowUserPointer()
{
	// Get the window's user pointer
	return glfwGetWindowUserPointer(window);
}

// Set the window's monitor
void gioWindow::SetWindowMonitor(GLFWmonitor* monitor, int x, int y, int width, int height, int refreshRate)
{
	// Set the window's monitor
	glfwSetWindowMonitor(window, monitor, x, y, width, height, refreshRate);
}

// Get the window's monitor
GLFWmonitor* gioWindow::GetWindowMonitor()
{
	// Get the window's monitor
	return glfwGetWindowMonitor(window);
}

// Get the window's attributes
const GLFWvidmode* gioWindow::GetWindowAttributes()
{
	// Get the window's attributes
	return glfwGetVideoMode(glfwGetPrimaryMonitor());
}

// Set the window's context
void gioWindow::SetWindowContext(GLFWwindow* window)
{
	// Set the window's context
	glfwMakeContextCurrent(window);
}

// Get the window's context
GLFWwindow* gioWindow::GetWindowContext()
{
	// Get the window's context
	return glfwGetCurrentContext();
}

// Set the window's focus
void gioWindow::SetWindowFocus()
{
	// Set the window's focus
	focus = glfwGetWindowAttrib(window, GLFW_FOCUSED);
}

// Get the window's focus
int gioWindow::GetWindowFocus()
{
	// Get the window's focus
	return focus;
}

// Set the window's iconify
void gioWindow::SetWindowIconify()
{
	// Set the window's iconify
	iconify = glfwGetWindowAttrib(window, GLFW_ICONIFIED);
}

// Get the window's iconify
int gioWindow::GetWindowIconify()
{
	// Get the window's iconify
	return iconify;
}

// Set the window's maximize
void gioWindow::SetWindowMaximize()
{
	// Set the window's maximize
	maximize = glfwGetWindowAttrib(window, GLFW_MAXIMIZED);
}

// Get the window's maximize
int gioWindow::GetWindowMaximize()
{
	// Get the window's maximize
	return maximize;
}

// Set the window's hover
void gioWindow::SetWindowHover()
{
	// Set the window's hover
	hover = glfwGetWindowAttrib(window, GLFW_HOVERED);
}

// Get the window's hover
int gioWindow::GetWindowHover()
{
	// Get the window's hover
	return hover;
}

// Set the window's visible
void gioWindow::SetWindowVisible()
{
	// Set the window's visible
	visible = glfwGetWindowAttrib(window, GLFW_VISIBLE);
}

// Get the window's visible
int gioWindow::GetWindowVisible()
{
	// Get the window's visible
	return visible;
}

// Set the window's resizable
void gioWindow::SetWindowResizable()
{
	// Set the window's resizable
	resizable = glfwGetWindowAttrib(window, GLFW_RESIZABLE);
}

// Get the window's resizable
int gioWindow::GetWindowResizable()
{
	// Get the window's resizable
	return resizable;
}

// Set the window's decorated
void gioWindow::SetWindowDecorated()
{
	// Set the window's decorated
	decorated = glfwGetWindowAttrib(window, GLFW_DECORATED);
}

// Get the window's decorated
int gioWindow::GetWindowDecorated()
{
	// Get the window's decorated
	return decorated;
}

// Set the window's floating
void gioWindow::SetWindowFloating()
{
	// Set the window's floating
	floating = glfwGetWindowAttrib(window, GLFW_FLOATING);
}

// Get the window's floating
int gioWindow::GetWindowFloating()
{
	// Get the window's floating
	return floating;
}