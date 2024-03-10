#pragma once

// Include the standard library
#include <iostream>
#include <fstream>
#include <sstream> //for std::stringstream 
#include <string>

namespace core
{
	// Filesystem class
	class gioFileSystem
	{
	public:

		// Methods
		void write(const char* filename, const char* data);
		void read(const char* filename, char* data);
		void append(const char* filename, const char* data);
	};

	void InitFileSystem()
	{
		gioFileSystem* fs = new gioFileSystem();
		// Add the core-filesystem setting
		AddSetting("core-filesystem", fs);
	}

	void gioFileSystem::write(const char* filename, const char* data)
	{
		std::ofstream file;
		file.open(filename);
		file << data;
		file.close();
	}

	void gioFileSystem::read(const char* filename, char* data)
	{
		std::ifstream file;
		file.open(filename);
		file >> data;
		file.close();
	}

	void gioFileSystem::append(const char* filename, const char* data)
	{
		std::ofstream file;
		file.open(filename, std::ios::app);
		file << data;
		file.close();
	}

	// Writing EngineConfig to file
	void WriteToEngineConfig(const char* configname, const char* value)
	{
		const char *filename = (*(std::string*)GetSetting("engine-settings-configpath")).c_str();
		gioFileSystem* fs = (gioFileSystem*)GetSetting("core-filesystem");
		fs->append(filename, (std::string("") + configname + "|" + value).c_str());
	}

	void UpdateEngineConfig()
	{
		const char *filename = (*(std::string*)GetSetting("engine-settings-configpath")).c_str();
		gioFileSystem* fs = (gioFileSystem*)GetSetting("core-filesystem");

		// loop through EngineConfig and write to file
		for (auto it = EngineConfig.begin(); it != EngineConfig.end(); it++)
		{
			// find the inputs and write to file
			if ((it->first.find("OS-keyboard") != std::string::npos || it->first.find("OS-mouse") != std::string::npos || it->first.find("OS-gamepad") != std::string::npos) && it->first.find("string") == std::string::npos && it->second != nullptr)
			{
				std::cout << it->second << std::endl;
				int key = *(int*)it->second;

				fs->append(filename, (std::string("") + it->first + "|" + std::to_string(key) + '\n').c_str());
			}
		}
	}

	void LoadEngineConfig()
	{
		const char *filename = (*(std::string*)GetSetting("engine-settings-configpath")).c_str();
		gioFileSystem* fs = (gioFileSystem*)GetSetting("core-filesystem");

		std::ifstream file;
		file.open(filename);
		std::string line;
		while (std::getline(file, line))
		{
			std::string delimiter = "|";
			std::string name = line.substr(0, line.find(delimiter));
			int *value = new int(stoi(line.substr(line.find(delimiter) + 1, line.length())));

			AddSetting(name, (void*)value);
		}
		file.close();
	}
}