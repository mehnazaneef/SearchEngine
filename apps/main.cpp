#include <iostream>

#include "FileReader.h"
#include "SearchEngine.h"
#include <filesystem>

int main(int argc, char* argv[]) {



	FileReader reader;

	std::string text = reader.readFile("data/data.txt");

	if (text.empty())
	{
		std::cout << "File is empty or not found\n";
		return 0;
	}

	SearchEngine engine;

	engine.addDocument(1, text);

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
		for (int id : result)
		{
			std::cout << id << " ";
		}
		std::cout << std::endl;
	}

	return 0;

}