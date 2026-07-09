#pragma once

#include <filesystem>

struct Document {
	int id{};
	std::filesystem::path path;
};
