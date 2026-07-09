#include "InvertedIndex.h"
#include "Tokenizer.h"

void InvertedIndex::addDocument(int docId, const std::vector<std::string> tokens) {
	for (const auto& token : tokens) {
		index[token].insert(docId);
	}
}

std::vector<int> InvertedIndex::search(const std::vector<std::string> words) {

	std::unordered_set<int> result = index[words[0]];

	for (size_t i = 1; i < words.size(); i++) {

		const auto& currentSet = index[words[i]];
		std::unordered_set<int> temp;

		for (int docId : result) {
			if (currentSet.find(docId) != currentSet.end()) {
				temp.insert(docId);
			}
		}
		result = std::move(temp);
	}
	return std::vector<int>(result.begin(), result.end());
}