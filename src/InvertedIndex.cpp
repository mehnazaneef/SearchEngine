#include "InvertedIndex.h"
#include "Tokenizer.h"

void InvertedIndex::addDocument(int docId, const std::vector<std::string> tokens) {
	for (const auto& token : tokens) {
		m_index[token][docId]++;
	}
}

const PostingList* InvertedIndex::getPostingList(const std::string& token) const{
	auto it = m_index.find(token);

	if (it == m_index.end())
		return nullptr;

	return &it->second;
}