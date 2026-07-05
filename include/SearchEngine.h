#pragma once

#include <string>
#include "Tokenizer.h"

class SearchEngine
{
public:
	bool containsWord(
		const std::string& text,
		const std::string& word);

private:
	Tokenizer tokenizer;
};