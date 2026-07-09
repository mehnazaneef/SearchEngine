#include <iostream>

#include "FileReader.h"
#include "SearchEngine.h"
#include <filesystem>

int main(int argc, char* argv[]) {

	FileReader reader;
	SearchEngine engine;

	auto files = reader.getFiles("data");

	for (const auto& file : files) {
		auto text = reader.readFile(file);
		engine.addDocument(file, text);
	}

	std::string query;
	std::cout << "Enter search query: ";
	std::getline(std::cin, query);

	auto result = engine.search(query);

	if (result.empty()) {
		std::cout << "word not in doc";
	}
	else
	{
		std::cout << "Found in documents: ";
		for (const std::string& filename : result)
		{
			std::cout << filename << " ";
		}
		std::cout << std::endl;
	}

	return 0;

}