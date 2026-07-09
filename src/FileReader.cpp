#include "FileReader.h"
#include <iostream>

#include <fstream>
#include <sstream>

std::string FileReader::readFile(const std::filesystem::path& path) 
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

std::vector<std::filesystem::path> FileReader::getFiles(const std::filesystem::path& directory) {
	//create an empty vector
	std::vector<std::filesystem::path> result;

	//Iterate through the directory
	for (const auto& entry : std::filesystem::directory_iterator(directory)) {
		//skip non files
		if (!entry.is_regular_file()) continue;
		
		//skip non .txt files
		if (entry.path().extension() != ".txt") continue;

		//store the path
		result.push_back(entry.path());
	}
	//return the vector 
	return result;
}