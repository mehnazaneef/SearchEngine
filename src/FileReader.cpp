#include "FileReader.h"
#include <iostream>

#include <fstream>
#include <sstream>

std::string FileReader::readFile(const std::string& path) 
{
	std::ifstream file(path);

	if (!file.is_open())
	{
		std::cout << "Failed to open: " << path << "\n";
		return "";
	}

	std::stringstream buffer;

	buffer << file.rdbuf();

	return buffer.str();
}