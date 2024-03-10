// including types.h
#include "core/types/types.h"

// including OS.h
#include "core/OS/OS.h"

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#include <imgui.h>

#include <map>

/*
    What I wanna do is edit this file to make it do what I need
    for now this is only the file from ImGui Demo
*/

/*
    I want to make a window for EngineConfig

    then, I want that window to have a option to add inputs to an input dictionary
    that maps whatever std::string name you specify, to a desired input
*/

/*
    I'm going to start this by making a save system for my engine. Where you can easily save whatever you add / remove
    from EngineConfig

    That will make things easier.
*/

static void ShowExampleAppSimpleOverlay(bool* p_open)
{
    static int location = 0;
    ImGuiIO& io = ImGui::GetIO();
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
    if (location >= 0)
    {
        const float PAD = 10.0f;
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImVec2 work_pos = viewport->WorkPos; // Use work area to avoid menu-bar/task-bar, if any!
        ImVec2 work_size = viewport->WorkSize;
        ImVec2 window_pos, window_pos_pivot;
        window_pos.x = (location & 1) ? (work_pos.x + work_size.x - PAD) : (work_pos.x + PAD);
        window_pos.y = (location & 2) ? (work_pos.y + work_size.y - PAD) : (work_pos.y + PAD);
        window_pos_pivot.x = (location & 1) ? 1.0f : 0.0f;
        window_pos_pivot.y = (location & 2) ? 1.0f : 0.0f;
        ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
        window_flags |= ImGuiWindowFlags_NoMove;
    }
    else if (location == -2)
    {
        // Center window
        ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
        window_flags |= ImGuiWindowFlags_NoMove;
    }
    ImGui::SetNextWindowBgAlpha(0.35f); // Transparent background
    if (ImGui::Begin("Example: Simple overlay", p_open, window_flags))
    {
        ImGui::Text("Simple overlay\n" "(right-click to change position)");
        ImGui::Separator();

        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(222, 150, 150, 255));
        ImGui::TextUnformatted((const char*) GetSetting("OS-keyboardinput-string"));
        ImGui::PopStyleColor();
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(150, 222, 150, 255));
        ImGui::TextUnformatted((const char*) GetSetting("OS-mouseinput-string"));
        ImGui::PopStyleColor();
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(150, 150, 222, 255));
        ImGui::TextUnformatted((const char*) GetSetting("OS-gamepadinput-string"));
        ImGui::PopStyleColor();

        if (ImGui::BeginPopupContextWindow())
        {
            if (ImGui::MenuItem("Custom", NULL, location == -1)) location = -1;
            if (ImGui::MenuItem("Center", NULL, location == -2)) location = -2;
            if (ImGui::MenuItem("Top-left", NULL, location == 0)) location = 0;
            if (ImGui::MenuItem("Top-right", NULL, location == 1)) location = 1;
            if (ImGui::MenuItem("Bottom-left", NULL, location == 2)) location = 2;
            if (ImGui::MenuItem("Bottom-right", NULL, location == 3)) location = 3;
            if (p_open && ImGui::MenuItem("Close")) *p_open = false;
            ImGui::EndPopup();
        }
    }
    ImGui::End();
}

// Make a window to play any sounds with ImGui, specifying the sound directory in a text input
static void ShowExampleAppSoundPlayer(bool* p_open)
{
    ImGuiIO& io = ImGui::GetIO();
	
    ALuint source, buffer;
    ALfloat offset;
    ALenum state;

    static char directory[128] = "Directory:";
    
    if (ImGui::Begin("Sound Player", p_open))
	{

		ImGui::Text("Sound Directory:");
		ImGui::SameLine();
        ImGui::InputText("####SoundDirectory", directory, IM_ARRAYSIZE(directory));

		if (ImGui::Button("Play Sound"))
		{
            /* Load the sound into a buffer. */
            char** directory_c_array = (char**) &directory;

            if (InitAL(&directory_c_array, 0) != 0)
                return;

            buffer = LoadSound(directory);
			// Play the sound
            /* Create the source to play the sound with. */
            source = 0;
            alGenSources(1, &source);
            alSourcei(source, AL_BUFFER, (ALint)buffer);
            assert(alGetError() == AL_NO_ERROR && "Failed to setup sound source");

            /* Play the sound until it finishes. */
            alSourcePlay(source);
		}
	}
	ImGui::End();
}

namespace gioImGui
{
    void Init()
    {
        const char* glsl_version = "#version 330";
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsLight();

        gioWindow *window = (gioWindow*)GetSetting("OS-window");

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window->window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);

        // Our state
        bool *show_demo_window = new bool(false);
        bool *show_another_window = new bool(false);
        bool *show_simple_overlay = new bool(true);
        bool* show_example_sound_player = new bool(true);
        gioVec4 *clear_color = new gioVec4(0.45f, 0.55f, 0.60f, 1.00f);

        AddSetting("ImGui-show_demo_window", show_demo_window);
        AddSetting("ImGui-show_another_window", show_another_window);
        AddSetting("ImGui-show_simple_overlay", show_simple_overlay);
        AddSetting("ImGui-show_example_sound_player", show_example_sound_player);
        AddSetting("OpenGL-clear_color", clear_color);
    }

    void Update()
    {
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        bool *show_demo_window = (bool*)GetSetting("ImGui-show_demo_window");
        bool *show_another_window = (bool*)GetSetting("ImGui-show_another_window");
        bool *show_simple_overlay = (bool*)GetSetting("ImGui-show_simple_overlay");
        bool *show_example_sound_player = (bool*)GetSetting("ImGui-show_example_sound_player");
        gioVec4 *clear_color = (gioVec4*)GetSetting("OpenGL-clear_color");

        gioWindow *window = (gioWindow*)GetSetting("OS-window");

        ImGuiIO& io = ImGui::GetIO();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (*show_demo_window)
            ImGui::ShowDemoWindow(show_demo_window);

        if (*show_example_sound_player)
            ShowExampleAppSoundPlayer(show_example_sound_player);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);
            ImGui::End();
        }

        AddSetting("ImGui-show_demo_window", show_demo_window);
        AddSetting("ImGui-show_another_window", show_another_window);
        AddSetting("ImGui-show_simple_overlay", show_simple_overlay);
        AddSetting("ImGui-clear_color", clear_color);

        // 3. Show another simple window.
        if (*show_another_window)
        {
            ImGui::Begin("Another Window", show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                *show_another_window = false;
            ImGui::End();
        }

        if (*show_simple_overlay) ShowExampleAppSimpleOverlay(show_simple_overlay);

        // Rendering
        ImGui::Render();
        int display_w = 800, display_h = 600;
        glfwGetFramebufferSize(window->window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color->x * clear_color->w, clear_color->y * clear_color->w, clear_color->z * clear_color->w, clear_color->w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void CleanUp()
    {
		// Cleanup
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}