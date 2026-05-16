#include <iostream>

#include "FileReader.h"

int main() {

	FileReader reader;

	std::string text = reader.readFile("data.txt");

	std::cout << text << "\n";

	return 0;

}