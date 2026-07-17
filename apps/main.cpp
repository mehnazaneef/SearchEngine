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

	auto results = engine.search(query);

	for (const auto& result : results)
	{
		std::cout << result.getPath().filename().string()
			<< "  Score: "
			<< result.getScore()
			<< '\n';
	}

	return 0;

}