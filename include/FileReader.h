#pragma once

#include <string>
#include <vector>
#include <filesystem>

class FileReader
{
public:
	std::string readFile(const std::filesystem::path& path);

	std::vector<std::filesystem::path> getFiles(const std::filesystem::path& directory);
};