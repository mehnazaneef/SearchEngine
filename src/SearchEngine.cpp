#include "SearchEngine.h"

bool SearchEngine::containsWord(
	const std::string& text,
	const std::string& word
)
{
	return text.find(word) != std::string::npos;
}
