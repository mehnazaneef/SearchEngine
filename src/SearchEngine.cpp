#include "SearchEngine.h"

void SearchEngine::addDocument(int id, const std::string& text) {
	index.addDocument(id, text);
}

std::vector<int> SearchEngine::search(const std::string& query) {
	return index.search(query);
}
