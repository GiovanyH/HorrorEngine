#pragma once

// opengl code to draw a quad to the screen

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <iostream>

/*
	Today we're making an animation system
*/


// TODO: use this
class texture_object
{
public:
	unsigned int VAO;
	unsigned int texture;

	unsigned int framex;
	unsigned int framey;

	float tex_size;

	unsigned int tex_sizex;
	unsigned int tex_sizey;

	gioVec2 position;
private:
	bool isFlipped;

	unsigned int VBO, EBO;
	Shader* quad_shader;

	// creating VAO
	void create_VAO()
	{
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
	}

	// creating VBO
	void create_VBO(float vertices[], unsigned int size)
	{
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
	}

	// creating EBO
	void create_EBO(unsigned int indices[], unsigned int size)
	{
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	}

	// setting vertex attributes
	void set_vertex_attributes()
	{
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
	}

	// load and create a texture 
	void create_texture(const char* path)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		// load image, create texture and generate mipmaps
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
		unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);
	}

	// use shader
	void use_shader(const char* vertex, const char* fragment)
	{
		quad_shader->use();
		glUniform1i(glGetUniformLocation(quad_shader->ID, "texture1"), 0);
		unsigned int positionLoc = glGetUniformLocation(quad_shader->ID, "position");
		glUniform2f(positionLoc, 0.0f, 0.0f);
	}

public:
	void change_texture(const char* path)
	{
		create_texture(path);
	}

	texture_object(const char* texture_path, const char* vertex, const char* fragment, gioVec2 size)
	{
		framex = animationData.x;
		framey = animationData.z;

		tex_sizex = (int)size.x;
		tex_sizey = (int)size.y;

		gioVec2 tex_size = gioVec2(tex_sizex, tex_sizey);

		float vertices[] = {
			// positions          // colors           // texture coords
			 +0.5f, +0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   (framex + 1.0f) / tex_size.x, framey / tex_size.y, // top right
			 +0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   (framex + 1.0f) / tex_size.x, (framey - 1.0f) / tex_size.y, // bottom right
			 -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   framex / tex_size.x, (framey - 1.0f) / tex_size.y, // bottom left
			 -0.5f, +0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   framex / tex_size.x, framey / tex_size.y  // top left 
		};
		unsigned int indices[] = {
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
		};

		quad_shader = new Shader(vertex, fragment);

		create_VAO();
		create_VBO(vertices, sizeof(vertices));
		create_EBO(indices, sizeof(indices));
		set_vertex_attributes();
		create_texture(texture_path);
		use_shader(vertex, fragment);

		gioVec2* frame = new gioVec2(framex, framey);
		AddSetting("frame", frame);
	}

	void draw(float deltaTime)
	{
		// bind textures on corresponding texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);

		gioVec2 tex_size = gioVec2(tex_sizex, tex_sizey);

		float vertices[] = {
			// positions          // colors           // texture coords
			 +0.5f, +0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   (framex + 1.0f) / tex_size.x, framey / tex_size.y, // top right
			 +0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   (framex + 1.0f) / tex_size.x, (framey - 1.0f) / tex_size.y, // bottom right
			 -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   framex / tex_size.x, (framey - 1.0f) / tex_size.y, // bottom left
			 -0.5f, +0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   framex / tex_size.x, framey / tex_size.y  // top left 
		};

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		// use shader
		quad_shader->use();

		unsigned int positionLoc = glGetUniformLocation(quad_shader->ID, "position");
		glUniform2f(positionLoc, position.x, position.y);

		// render container
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void delete_object()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
	}
};