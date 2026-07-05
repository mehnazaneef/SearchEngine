#include "Tokenizer.h"
#include <sstream>
#include <cctype>

std::vector<std::string> Tokenizer::tokenize(const std::string& text) {
	std::vector<std::string> tokens;
	std::string word;
	std::istringstream stream(text);

	while (stream >> word) {
		for (auto& c : word) {
			c = std::tolower(c);
		}
		tokens.push_back(word);
	}
	return tokens;
}