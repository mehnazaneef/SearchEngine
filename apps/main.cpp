#include <iostream>

#include "FileReader.h"
#include "SearchEngine.h"

int main(int argc, char* argv[]) {

	if (argc < 2) {
		std::cout << "Usage: search_engine <word>\n";
		return 1;
	}

	std::string searchWord = argv[1];

	FileReader reader;

	std::string text = reader.readFile("data/data.txt");

	std::cout << "Text read:\n";
	std::cout << text << "\n";

	SearchEngine engine;

	bool found = engine.containsWord(
		text, 
		searchWord
	);

	if (found) {
		std::cout << "Word found" << "\n";
	}
	else
	{
		std::cout << "Word not found" << "\n";
	}

	return 0;

}