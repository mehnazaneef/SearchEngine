#include "SearchEngine.h"

bool SearchEngine::containsWord(
	const std::string& text,
	const std::string& word
)
{
	auto tokens = tokenizer.tokenize(text);

	for (const auto& token : tokens) {
		if (token == word)
			return true;
	}
	return false;
}
